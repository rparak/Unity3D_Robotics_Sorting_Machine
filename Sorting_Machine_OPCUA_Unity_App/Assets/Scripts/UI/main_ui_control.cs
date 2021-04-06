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
File Name: main_ui_control.cs
****************************************************************************/

// ------------------------------------------------------------------------------------------------------------------------ //
// ----------------------------------------------------- LIBRARIES -------------------------------------------------------- //
// ------------------------------------------------------------------------------------------------------------------------ //

// -------------------- Unity -------------------- //
using UnityEngine;
using UnityEngine.UI;
// --------------------- TM ---------------------- //
using TMPro;

public class main_ui_control : MonoBehaviour
{
    // -------------------- GameObject -------------------- //
    public GameObject camera_obj;
    // -------------------- Image -------------------- //
    public Image connection_panel_img, diagnostic_panel_img;
    public Image connection_info_img;
    // -------------------- TMP_InputField -------------------- //
    public TMP_InputField ip_address_txt;
    // -------------------- Float -------------------- //
    private float ex_param = 100f;
    // -------------------- TextMeshProUGUI -------------------- //
    public TextMeshProUGUI xyzM_position_x_txt, xyzM_position_y_txt, xyzM_position_z_txt;
    public TextMeshProUGUI xyzM_velocity_x_txt, xyzM_velocity_y_txt, xyzM_velocity_z_txt;
    public TextMeshProUGUI cC_position_x_txt;
    public TextMeshProUGUI cC_velocity_x_txt;
    public TextMeshProUGUI connectionInfo_txt;

    // ------------------------------------------------------------------------------------------------------------------------ //
    // ------------------------------------------------ INITIALIZATION {START} ------------------------------------------------ //
    // ------------------------------------------------------------------------------------------------------------------------ //
    void Start()
    {
        // Connection information {image} -> Connect/Disconnect
        connection_info_img.GetComponent<Image>().color = new Color32(255, 0, 48, 50);
        // Connection information {text} -> Connect/Disconnect
        connectionInfo_txt.text = "Disconnect";

        // Panel Initialization -> Connection/Diagnostic Panel
        connection_panel_img.transform.localPosition = new Vector3(1215f + (ex_param), 0f, 0f);
        diagnostic_panel_img.transform.localPosition = new Vector3(780f + (ex_param), 0f, 0f);

        // Position XYZ Manipulator -> X..Z
        xyzM_position_x_txt.text = "0.00";
        xyzM_position_y_txt.text = "0.00";
        xyzM_position_z_txt.text = "0.00";
        // Velocity XYZ Manipulator -> X..Z
        xyzM_velocity_x_txt.text = "0.00";
        xyzM_velocity_y_txt.text = "0.00";
        xyzM_velocity_z_txt.text = "0.00";
        // Position Cameraa Conveyor -> X
        cC_position_x_txt.text = "0.00";
        // Velocity Cameraa Conveyor -> X
        cC_velocity_x_txt.text = "0.00";

        // Sortign Machine ID Address
        ip_address_txt.text = "127.0.0.1";
    }

    // ------------------------------------------------------------------------------------------------------------------------ //
    // ------------------------------------------------ MAIN FUNCTION {Cyclic} ------------------------------------------------ //
    // ------------------------------------------------------------------------------------------------------------------------ //
    void Update()
    {
        // Control -> Start {Read OPCUA data}
        GlobalVariables_Main_Control.opcua_config[0] = ip_address_txt.text;
        // Control -> Start {Write OPCUA data}
        GlobalVariables_Main_Control.opcua_config[0] = ip_address_txt.text;

        // ------------------------ Connection Information ------------------------//
        // If the button (connect/disconnect) is pressed, change the color and text
        if (GlobalVariables_Main_Control.connect == true)
        {
            // green color
            connection_info_img.GetComponent<Image>().color = new Color32(135, 255, 0, 50);
            connectionInfo_txt.text = "Connect";
        }
        else if(GlobalVariables_Main_Control.disconnect == true)
        {
            // red color
            connection_info_img.GetComponent<Image>().color = new Color32(255, 0, 48, 50);
            connectionInfo_txt.text = "Disconnect";
        }

        // ------------------------ Cyclic read parameters {diagnostic panel} ------------------------ //
        // Position XYZ Manipulator -> X..Z
        xyzM_position_x_txt.text = GlobalVariables_OPC_UA_client.xyz_manip_pos[0].ToString();
        xyzM_position_y_txt.text = GlobalVariables_OPC_UA_client.xyz_manip_pos[1].ToString();
        xyzM_position_z_txt.text = GlobalVariables_OPC_UA_client.xyz_manip_pos[2].ToString();
        // Velocity XYZ Manipulator -> X..Z
        xyzM_velocity_x_txt.text = GlobalVariables_OPC_UA_client.xyz_manip_vel[0].ToString();
        xyzM_velocity_y_txt.text = GlobalVariables_OPC_UA_client.xyz_manip_vel[1].ToString();
        xyzM_velocity_z_txt.text = GlobalVariables_OPC_UA_client.xyz_manip_vel[2].ToString();
        // Position Cameraa Conveyor -> X
        cC_position_x_txt.text = GlobalVariables_OPC_UA_client.cam_conv_x_pos.ToString();
        // Velocity Cameraa Conveyor -> X
        cC_velocity_x_txt.text = GlobalVariables_OPC_UA_client.cam_conv_x_vel.ToString();

    }

    // ------------------------------------------------------------------------------------------------------------------------//
    // -------------------------------------------------------- FUNCTIONS -----------------------------------------------------//
    // ------------------------------------------------------------------------------------------------------------------------//

    // -------------------- Destroy Blocks -------------------- //
    void OnApplicationQuit()
    {
        // Destroy all
        Destroy(this);
    }

    // -------------------- Connection Panel -> Visible On -------------------- //
    public void TaskOnClick_ConnectionBTN()
    {
        // visible on
        connection_panel_img.transform.localPosition = new Vector3(0f, 0f, 0f);
        // visible off
        diagnostic_panel_img.transform.localPosition = new Vector3(780f + (ex_param), 0f, 0f);
    }

    // -------------------- Connection Panel -> Visible off -------------------- //
    public void TaskOnClick_EndConnectionBTN()
    {
        connection_panel_img.transform.localPosition = new Vector3(1215f + (ex_param), 0f, 0f);
    }

    // -------------------- Diagnostic Panel -> Visible On -------------------- //
    public void TaskOnClick_DiagnosticBTN()
    {
        // visible on
        diagnostic_panel_img.transform.localPosition = new Vector3(0f, 0f, 0f);
        // visible off
        connection_panel_img.transform.localPosition = new Vector3(1215f + (ex_param), 0f, 0f);
    }

    // -------------------- Diagnostic Panel -> Visible Off -------------------- //
    public void TaskOnClick_EndDiagnosticBTN()
    {
        diagnostic_panel_img.transform.localPosition = new Vector3(780f + (ex_param), 0f, 0f);
    }

    // -------------------- Camera Position -> Right -------------------- //
    public void TaskOnClick_CamViewRBTN()
    {
        camera_obj.transform.localPosition    = new Vector3(0.114f, 2.64f, -2.564f);
        camera_obj.transform.localEulerAngles = new Vector3(10f, -30f, 0f);

        camera_obj.GetComponent<Camera>().orthographic = false;
    }

    // -------------------- Camera Position -> Left -------------------- //
    public void TaskOnClick_CamViewLBTN()
    {
        camera_obj.transform.localPosition = new Vector3(-2.114f, 2.64f, -2.564f);
        camera_obj.transform.localEulerAngles = new Vector3(10f, 30f, 0f);

        camera_obj.GetComponent<Camera>().orthographic = false;
    }

    // -------------------- Camera Position -> Main View -------------------- //
    public void TaskOnClick_CamViewMWBTN()
    {
        camera_obj.transform.localPosition = new Vector3(-0.265f, 2.597f, -1.619f);
        camera_obj.transform.localEulerAngles = new Vector3(20f, -40f, 0f);

        camera_obj.GetComponent<Camera>().orthographic = false;
    }

    // -------------------- Camera Position -> Top -------------------- //
    public void TaskOnClick_CamViewTBTN()
    {
        camera_obj.transform.localPosition = new Vector3(-0.71f, 3.11f, -1.06f);
        camera_obj.transform.localEulerAngles = new Vector3(90f, 0f, 0f);

        camera_obj.GetComponent<Camera>().orthographic = true;
        camera_obj.GetComponent<Camera>().orthographicSize = 0.7f;
    }

    // -------------------- Camera Position -> 2D Vision View -------------------- //
    public void TaskOnClick_CamView2DVBTN()
    {
        camera_obj.transform.localPosition = new Vector3(-0.398f, 2.679f, -1.094f);
        camera_obj.transform.localEulerAngles = new Vector3(90f, 0f, 0f);

        camera_obj.GetComponent<Camera>().orthographic = true;
        camera_obj.GetComponent<Camera>().orthographicSize = 0.1f;
    }

    // -------------------- Connect Button -> is pressed -------------------- //
    public void TaskOnClick_ConnectBTN()
    {
        GlobalVariables_Main_Control.connect    = true;
        GlobalVariables_Main_Control.disconnect = false;
    }

    // -------------------- Disconnect Button -> is pressed -------------------- //
    public void TaskOnClick_DisconnectBTN()
    {
        GlobalVariables_Main_Control.connect    = false;
        GlobalVariables_Main_Control.disconnect = true;
    }

}
