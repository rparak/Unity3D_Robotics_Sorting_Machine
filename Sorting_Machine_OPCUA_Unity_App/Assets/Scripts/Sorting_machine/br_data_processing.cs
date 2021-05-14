/****************************************************************************
MIT License
Copyright(c) 2020 Roman Parak
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*****************************************************************************
Author   : Roman Parak
Email    : Roman.Parak @outlook.com
Github   : https://github.com/rparak
File Name: br_data_processing.cs
****************************************************************************/

// ------------------------------------------------------------------------------------------------------------------------//
// ----------------------------------------------------- LIBRARIES --------------------------------------------------------//
// ------------------------------------------------------------------------------------------------------------------------//

// -------------------- System -------------------- //
using System;
using System.Threading;
// -------------------- Unity -------------------- //
using UnityEngine;
// -------------------- OPCUA -------------------- //
using Opc.Ua;
using Opc.Ua.Client;
using Opc.Ua.Configuration;

// -------------------- Class {Global Variable} -> Main Control -------------------- //
public static class GlobalVariables_Main_Control
{
    // String //
    public static string[] opcua_config = new string[2];
    // Bool // 
    public static bool enable_r, enable_w;
    public static bool connect, disconnect;
}

public static class GlobalVariables_OPC_UA_client
{
    // -------------------- XYZ Manipulator -------------------- //
    //  NodeId  //
    public static NodeId[] xyz_manip_pos_node = new NodeId[3] { "ns=6;s=::AsGlobalPV:dT_Main.xyz_manipulator.X.actual_position", "ns=6;s=::AsGlobalPV:dT_Main.xyz_manipulator.Y.actual_position", "ns=6;s=::AsGlobalPV:dT_Main.xyz_manipulator.Z.actual_position" };
    public static NodeId[] xyz_manip_vel_node = new NodeId[3] { "ns=6;s=::AsGlobalPV:dT_Main.xyz_manipulator.X.actual_velocity", "ns=6;s=::AsGlobalPV:dT_Main.xyz_manipulator.Y.actual_velocity", "ns=6;s=::AsGlobalPV:dT_Main.xyz_manipulator.Z.actual_velocity" };
    //  Float  //
    public static float[] xyz_manip_pos = new float[3];
    public static float[] xyz_manip_vel = new float[3];

    // -------------------- Camera Conveyor  -------------------- //
    //  NodeId  //
    public static NodeId cam_conv_x_pos_node = "ns=6;s=::AsGlobalPV:dT_Main.camera_conveyor.X.actual_position";
    public static NodeId cam_conv_x_vel_node = "ns=6;s=::AsGlobalPV:dT_Main.camera_conveyor.X.actual_velocity";
    //  Float  //
    public static float cam_conv_x_pos;
    public static float cam_conv_x_vel;
    // -------------------- Camera Control -------------------- //
    //  NodeId  //
    public static NodeId camera_node = "ns=6;s=::AsGlobalPV:dT_Main.camera.scan";
    //  Float  //
    public static bool camera;
    // -------------------- Cube Transform (Main) -------------------- //
    //  NodeId  //
    public static NodeId[] gripp_node = new NodeId[2] { "ns=6;s=::AsGlobalPV:dT_Main.service.object.write.attach", "ns=6;s=::AsGlobalPV:dT_Main.service.object.write.detach" };
    public static NodeId reset_param_node = "ns=6;s=::AsGlobalPV:dT_Main.service.object.write.reset";
    public static NodeId set_obj_id_node = "ns=6;s=::AsGlobalPV:dT_Main.service.object.write.set_object_id";
    // Read {OpCUA B&R -> Unity}
    //  Bool  //
    public static bool gripp_attach, gripp_detach;
    public static bool reset_param;
    // Int //
    public static int set_obj_id;
    // Write {Unity -> OpcUA B&R}
    // String //
    public static string obj_id_w_node = "ns=6;s=::AsGlobalPV:dT_Main.service.object.read.object_id";
    public static string obj_type_w_node = "ns=6;s=::AsGlobalPV:dT_Main.service.object.read.object_type";
    // Int //
    public static int main_obj_id;
    public static int main_obj_type;
}


public class br_data_processing : MonoBehaviour
{
    // -------------------- ApplicationConfiguration -------------------- //
    private ApplicationConfiguration client_configuration_r = new ApplicationConfiguration();
    private ApplicationConfiguration client_configuration_w = new ApplicationConfiguration();
    // -------------------- EndpointDescription -------------------- //
    private EndpointDescription client_end_point_r, client_end_point_w;
    // -------------------- Session -------------------- //
    private Session client_session_r, client_session_w;
    // -------------------- Thread -------------------- //
    private Thread opcua_client_r_Thread, opcua_client_w_Thread;
    // -------------------- Int -------------------- //
    private int main_br_state = 0;

    // ------------------------------------------------------------------------------------------------------------------------//
    // ------------------------------------------------ INITIALIZATION {START} ------------------------------------------------//
    // ------------------------------------------------------------------------------------------------------------------------//
    void Start()
    {
        // PLC IP Address
        GlobalVariables_Main_Control.opcua_config[0] = "127.0.0.1";
        // OPC UA Port Number
        GlobalVariables_Main_Control.opcua_config[1] = "4840";
        
        // ------------------------ Initialization { B&R/SMC Digital Twin {Control Robot} - OPC UA Read Data } ------------------------//
        // Control -> Start {Read OPCUA data}
        GlobalVariables_Main_Control.enable_r = true;
        // ------------------------ Initialization { B&R/SMC Digital Twin {Control Robot} - OPC UA Write Data } ------------------------//
        // Control -> Start {Read OPCUA data}
        GlobalVariables_Main_Control.enable_w = true;

    }

    // ------------------------------------------------------------------------------------------------------------------------ //
    // ------------------------------------------------ MAIN FUNCTION {Cyclic} ------------------------------------------------ //
    // ------------------------------------------------------------------------------------------------------------------------ //
    private void Update()
    {
        switch (main_br_state)
        {
            case 0:
                {
                    // ------------------------ Wait State {Disconnect State} ------------------------//
                    if (GlobalVariables_Main_Control.connect == true)
                    {
                        // Control -> Start {Read OPCUA data}
                        GlobalVariables_Main_Control.enable_r = true;
                        // Control -> Start {Write OPCUA data}
                        GlobalVariables_Main_Control.enable_w = true;

                        // Initialization threading block
                        opcua_client_r_Thread = new Thread(() => OPCUa_r_thread_function(GlobalVariables_Main_Control.opcua_config[0], GlobalVariables_Main_Control.opcua_config[1]));
                        opcua_client_r_Thread.IsBackground = true;
                        // Start threading block
                        opcua_client_r_Thread.Start();

                        // Initialization threading block
                        opcua_client_w_Thread = new Thread(() => OPCUa_w_thread_function(GlobalVariables_Main_Control.opcua_config[0], GlobalVariables_Main_Control.opcua_config[1]));
                        opcua_client_w_Thread.IsBackground = true;
                        // Start threading block
                        opcua_client_w_Thread.Start();

                        // go to connect state
                        main_br_state = 1;
                    }
                }
                break;
            case 1:
                {
                    // ------------------------ Data Processing State {Connect State} ------------------------//
                    if (GlobalVariables_Main_Control.disconnect == true)
                    {
                        // Control -> Start {Read OPCUA data}
                        GlobalVariables_Main_Control.enable_r = false;
                        // Control -> Start {Write OPCUA data}
                        GlobalVariables_Main_Control.enable_w = false;

                        // Abort threading block {OPCUA -> read data}
                        if (opcua_client_r_Thread.IsAlive == true)
                        {
                            opcua_client_r_Thread.Abort();
                        }
                        // Abort threading block {OPCUA -> write data}
                        if (opcua_client_w_Thread.IsAlive == true)
                        {
                            opcua_client_w_Thread.Abort();
                        }
                        if (opcua_client_r_Thread.IsAlive == false && opcua_client_w_Thread.IsAlive == false)
                        {
                            // go to initialization state {wait state -> disconnect state}
                            main_br_state = 0;
                        }
                    }
                }
                break;
        }
    }

    // ------------------------------------------------------------------------------------------------------------------------//
    // -------------------------------------------------------- FUNCTIONS -----------------------------------------------------//
    // ------------------------------------------------------------------------------------------------------------------------//

    // -------------------- Abort Threading Blocks -------------------- //
    void OnApplicationQuit()
    {
        try
        {
            // Stop - threading while
            GlobalVariables_Main_Control.enable_r  = false;
            GlobalVariables_Main_Control.enable_w = false;

            // Abort threading block
            if (opcua_client_r_Thread.IsAlive == true)
            {
                opcua_client_r_Thread.Abort();
            }
            if (opcua_client_w_Thread.IsAlive == true)
            {
                opcua_client_w_Thread.Abort();
            }
        }
        catch (Exception e)
        {
            // Destroy all
            Destroy(this);
        }
        finally
        {
            // Destroy all
            Destroy(this);
        }
    }

    void OPCUa_r_thread_function(string ip_adr, string port_adr)
    {
        if (GlobalVariables_Main_Control.enable_r == true)
        {
            // OPCUa client configuration
            client_configuration_r = opcua_client_configuration();
            // Establishing communication
            client_end_point_r = CoreClientUtils.SelectEndpoint("opc.tcp://" + ip_adr + ":" + port_adr, useSecurity: false, operationTimeout: 5000);
            // Create session
            client_session_r = opcua_create_session(client_configuration_r, client_end_point_r);
        }

        // Threading while {read data}
        while (GlobalVariables_Main_Control.enable_r)
        {
            // ---------- FLOAT ---------- //
            // Position / Velocity - Camera Conveyor
            GlobalVariables_OPC_UA_client.cam_conv_x_pos = float.Parse(client_session_r.ReadValue(GlobalVariables_OPC_UA_client.cam_conv_x_pos_node).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.cam_conv_x_vel = float.Parse(client_session_r.ReadValue(GlobalVariables_OPC_UA_client.cam_conv_x_vel_node).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            // Position / Velocity - XYZ Manipulator
            GlobalVariables_OPC_UA_client.xyz_manip_pos[0] = float.Parse(client_session_r.ReadValue(GlobalVariables_OPC_UA_client.xyz_manip_pos_node[0]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.xyz_manip_pos[1] = float.Parse(client_session_r.ReadValue(GlobalVariables_OPC_UA_client.xyz_manip_pos_node[1]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.xyz_manip_pos[2] = float.Parse(client_session_r.ReadValue(GlobalVariables_OPC_UA_client.xyz_manip_pos_node[2]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.xyz_manip_vel[0] = float.Parse(client_session_r.ReadValue(GlobalVariables_OPC_UA_client.xyz_manip_vel_node[0]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.xyz_manip_vel[1] = float.Parse(client_session_r.ReadValue(GlobalVariables_OPC_UA_client.xyz_manip_vel_node[1]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            GlobalVariables_OPC_UA_client.xyz_manip_vel[2] = float.Parse(client_session_r.ReadValue(GlobalVariables_OPC_UA_client.xyz_manip_vel_node[2]).ToString(), System.Globalization.CultureInfo.InvariantCulture);
            // ---------- BOOL ---------- //
            // Service Control
            // Object
            GlobalVariables_OPC_UA_client.gripp_attach = bool.Parse(client_session_r.ReadValue(GlobalVariables_OPC_UA_client.gripp_node[0]).ToString());
            GlobalVariables_OPC_UA_client.gripp_detach = bool.Parse(client_session_r.ReadValue(GlobalVariables_OPC_UA_client.gripp_node[1]).ToString());
            // Reset Environment
            GlobalVariables_OPC_UA_client.reset_param  = bool.Parse(client_session_r.ReadValue(GlobalVariables_OPC_UA_client.reset_param_node).ToString());
            // ---------- INT ---------- //
            GlobalVariables_OPC_UA_client.set_obj_id = int.Parse(client_session_r.ReadValue(GlobalVariables_OPC_UA_client.set_obj_id_node).ToString());
            // ---------- BOOL ---------- //
            // Camera Scan
            GlobalVariables_OPC_UA_client.camera = bool.Parse(client_session_r.ReadValue(GlobalVariables_OPC_UA_client.camera_node).ToString());

            // Thread Sleep {2 ms}
            Thread.Sleep(2);
        }
    }

    // ------------------------ Threading Block { OPCUa Write Data } ------------------------//
    void OPCUa_w_thread_function(string ip_adr, string port_adr)
    {
        if (GlobalVariables_Main_Control.enable_w == true)
        {
            // OPCUa client configuration
            client_configuration_w = opcua_client_configuration();
            // Establishing communication
            client_end_point_w = CoreClientUtils.SelectEndpoint("opc.tcp://" + ip_adr + ":" + port_adr, useSecurity: false, operationTimeout: 5000);
            // Create session
            client_session_w = opcua_create_session(client_configuration_w, client_end_point_w);
        }

        // Threading while {write data}
        while (GlobalVariables_Main_Control.enable_w)
        {
            // -------------------- Sorting Machine Data -------------------- //
            // Object ID (0 .. Number of objects)
            opcua_write_value(client_session_w, GlobalVariables_OPC_UA_client.obj_id_w_node, GlobalVariables_OPC_UA_client.main_obj_id.ToString());
            // Object Type (Type 1, Type 2, ..., Type Err.)
            opcua_write_value(client_session_w, GlobalVariables_OPC_UA_client.obj_type_w_node, GlobalVariables_OPC_UA_client.main_obj_type.ToString());

            // Thread Sleep {10 ms}
            Thread.Sleep(10);
        }
    }
    // ------------------------ OPCUa Client {Application -> Configuration (STEP 1)} ------------------------//
    ApplicationConfiguration opcua_client_configuration()
    {
        // Configuration OPCUa Client {W/R -> Data}
        var config = new ApplicationConfiguration()
        {
            // Initialization (Name, Uri, etc.)
            ApplicationName = "OPCUa_AS", // OPCUa AS (Automation Studio B&R)
            ApplicationUri = Utils.Format(@"urn:{0}:OPCUa_AS", System.Net.Dns.GetHostName()),
            // Type -> Client
            ApplicationType = ApplicationType.Client,
            SecurityConfiguration = new SecurityConfiguration
            {
                // Security Configuration - Certificate
                ApplicationCertificate = new CertificateIdentifier { StoreType = @"Directory", StorePath = @"%CommonApplicationData%\OPC Foundation\CertificateStores\MachineDefault", SubjectName = Utils.Format(@"CN={0}, DC={1}", "OPCUa_AS", System.Net.Dns.GetHostName()) },
                TrustedIssuerCertificates = new CertificateTrustList { StoreType = @"Directory", StorePath = @"%CommonApplicationData%\OPC Foundation\CertificateStores\UA Certificate Authorities" },
                TrustedPeerCertificates = new CertificateTrustList { StoreType = @"Directory", StorePath = @"%CommonApplicationData%\OPC Foundation\CertificateStores\UA Applications" },
                RejectedCertificateStore = new CertificateTrustList { StoreType = @"Directory", StorePath = @"%CommonApplicationData%\OPC Foundation\CertificateStores\RejectedCertificates" },
                AutoAcceptUntrustedCertificates = true,
                AddAppCertToTrustedStore = true
            },
            TransportConfigurations = new TransportConfigurationCollection(),
            TransportQuotas = new TransportQuotas { OperationTimeout = 5000 },
            ClientConfiguration = new ClientConfiguration { DefaultSessionTimeout = 60000 },
            TraceConfiguration = new TraceConfiguration()
        };
        config.Validate(ApplicationType.Client).GetAwaiter().GetResult();
        if (config.SecurityConfiguration.AutoAcceptUntrustedCertificates)
        {
            config.CertificateValidator.CertificateValidation += (s, e) => { e.Accept = (e.Error.StatusCode == StatusCodes.BadCertificateUntrusted); };
        }

        var application = new ApplicationInstance
        {
            ApplicationName = "OPCUa_AS",
            ApplicationType = ApplicationType.Client,
            ApplicationConfiguration = config
        };
        application.CheckApplicationInstanceCertificate(false, 2048).GetAwaiter().GetResult();

        return config;
    }

    // ------------------------ OPCUa Client {Application -> Create Session (STEP 2)} ------------------------//
    Session opcua_create_session(ApplicationConfiguration client_configuration, EndpointDescription client_end_point)
    {
        return Session.Create(client_configuration, new ConfiguredEndpoint(null, client_end_point, EndpointConfiguration.Create(client_configuration)), false, "", 5000, null, null).GetAwaiter().GetResult();
    }

    // ------------------------ OPCUa Client {Write Value (Define - Node)} ------------------------//
    bool opcua_write_value(Session client_session, string node_id, string value_write)
    {
        // Initialization (Bide)
        NodeId init_node = NodeId.Parse(node_id);

        try
        {
            // Find Node (OPCUa Client)
            Node node = client_session.NodeCache.Find(init_node) as Node;
            DataValue init_data_value = client_session.ReadValue(node.NodeId);

            // Preparation data for writing
            WriteValue value = new WriteValue()
            {
                NodeId = init_node,
                AttributeId = Attributes.Value,
                Value = new DataValue(new Variant(Convert.ChangeType(value_write, init_data_value.Value.GetType()))),
            };

            // Initialization (Write)
            WriteValueCollection init_write = new WriteValueCollection();
            // Append variable
            init_write.Add(value);

            StatusCodeCollection results = null;
            DiagnosticInfoCollection diagnosticInfos = null;

            // Wriate data
            client_session.Write(null, init_write, out results, out diagnosticInfos);

            // Check Result (Status)
            if (results[0] == StatusCodes.Good)
            {
                return true;
            }
            else
            {
                return false;
            }

        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);

            return false;
        }
    }
}
