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
File Name: object_transform.cs
****************************************************************************/

// ------------------------------------------------------------------------------------------------------------------------//
// ----------------------------------------------------- LIBRARIES --------------------------------------------------------//
// ------------------------------------------------------------------------------------------------------------------------//

// -------------------- System -------------------- //
using System;
// -------------------- Unity -------------------- //
using UnityEngine;

public class object_transform : MonoBehaviour
{
    // -------------------- Game Object { PUBLIC }  -------------------- //
    // Main objects (cubes)
    public GameObject[] cube_p = new GameObject[9];
    // XYZ Manipulator End-Effector
    public GameObject xyz_manip_ee;
    // Camera Conveyor Pad
    public GameObject cam_conv_pad;
    // Initial Pad
    public GameObject init_pad;
    // -------------------- Float -------------------- //
    // Object positions (x, y, z) 
    private float[] offset_x = new float[9] { -0.07998198f, 1.80006e-05f, 0.08001792f, -0.07998198f, 1.698732e-05f, 0.08001798f, -0.07998198f, 1.698732e-05f, 0.08001798f };
    private float[] offset_y = new float[9] { 0.03750359f, 0.03750359f, 0.0374996f, 0.0375036f, 0.0375036f, 0.0375036f, 0.0375036f, 0.03750361f, 0.03750361f };
    private float[] offset_z = new float[9] { -0.06000222f, -0.06000222f, -0.06000222f, 0.0f, 0.0f, 0.0f, 0.05999755f, 0.05999755f, 0.05999755f };
    // -------------------- INT -------------------- //
    private int main_state = 0;

    // ------------------------------------------------------------------------------------------------------------------------//
    // ------------------------------------------------ INITIALIZATION {START} ------------------------------------------------//
    // ------------------------------------------------------------------------------------------------------------------------//
    void Start()
    {
        // ------------------------ Initialization {Object p[0 - 9] -> 9 parts} ------------------------//
        for (int i = 0; i <= 8; i++)
        {
            // Default - Position, Rotation, Scale
            cube_p[i].transform.localPosition = new Vector3(offset_x[i], offset_y[i], offset_z[i]);
            cube_p[i].transform.localEulerAngles = new Vector3(0f, 0f, 0f);
            cube_p[i].transform.localScale = new Vector3(1f, 1f, 1f);
            // Freez Cube -> ON
            cube_p[i].GetComponent<Rigidbody>().isKinematic = true;
            // Trigger Collider -> OFF
            cube_p[i].GetComponent<MeshCollider>().convex = true; 
        }
    }

    // ------------------------------------------------------------------------------------------------------------------------//
    // ------------------------------------------------ MAIN FUNCTION {Cyclic} ------------------------------------------------//
    // ------------------------------------------------------------------------------------------------------------------------//
    void Update()
    {

        switch (main_state)
        {
            case 0:
                {
                    // ------------------------ Attach Object { Object XYZ Manip. EE } ------------------------//
                    if (GlobalVariables_OPC_UA_client.gripp_attach == true)
                    {
                        // Freez Cube -> ON
                        cube_p[GlobalVariables_OPC_UA_client.set_obj_id].GetComponent<Rigidbody>().isKinematic = true;
                        // Set Parent {Gripper -> ABB}
                        cube_p[GlobalVariables_OPC_UA_client.set_obj_id].transform.SetParent(xyz_manip_ee.transform);
                        // Set Position
                        cube_p[GlobalVariables_OPC_UA_client.set_obj_id].transform.localPosition = new Vector3(0f, -0.0141f, 0f);

                        main_state = 1;
                    }

                }
                break;

            case 1:
                {
                    // ------------------------ Detach Object { 1) Detach Object, 2) Attach Object Cam. Conv. Pad } ------------------------//
                    if (GlobalVariables_OPC_UA_client.gripp_detach == true)
                    {

                        // Freez Cube -> ON
                        cube_p[GlobalVariables_OPC_UA_client.set_obj_id].GetComponent<Rigidbody>().isKinematic = true;
                        // Set Parent {Camera Conveyor Pad}
                        cube_p[GlobalVariables_OPC_UA_client.set_obj_id].transform.SetParent(cam_conv_pad.transform);
                        // Set Position
                        cube_p[GlobalVariables_OPC_UA_client.set_obj_id].transform.localPosition = new Vector3(0f, 0.01264703f, 0f);

                        main_state = 2;

                    }
                }
                break;
            case 2:
                {
                    // ------------------------ Attach Object { Object XYZ Manip. EE } ------------------------//
                    if (GlobalVariables_OPC_UA_client.gripp_attach == true)
                    {
                        // Freez Cube -> ON
                        cube_p[GlobalVariables_OPC_UA_client.set_obj_id].GetComponent<Rigidbody>().isKinematic = true;
                        // Set Parent {XYZ Manipulator End-Effector}
                        cube_p[GlobalVariables_OPC_UA_client.set_obj_id].transform.SetParent(xyz_manip_ee.transform);
                        // Set Position
                        cube_p[GlobalVariables_OPC_UA_client.set_obj_id].transform.localPosition = new Vector3(0f, -0.0141f, 0f);

                        main_state = 3;
                    }
                }
                break;

            case 3:
                {
                    // ------------------------ Detach Object { Detach Object: type 10 -> Trash or type 1,2 .. -> Warehous (BR, SMC, etc.) detach NULL (environment base) } ------------------------//
                    if (GlobalVariables_OPC_UA_client.gripp_detach == true)
                    {
                        if (GlobalVariables_OPC_UA_client.main_obj_type == 10)
                        {
                            // Freez Cube -> OFF
                            cube_p[GlobalVariables_OPC_UA_client.set_obj_id].GetComponent<Rigidbody>().isKinematic = false;
                            // Set Parent {Bin (Green, Yellow, Magneta} -> NULL
                            cube_p[GlobalVariables_OPC_UA_client.set_obj_id].transform.SetParent(null);
                        }
                        else
                        {
                            // Freez Cube -> ON
                            cube_p[GlobalVariables_OPC_UA_client.set_obj_id].GetComponent<Rigidbody>().isKinematic = true;
                            // Set Parent -> NULL
                            cube_p[GlobalVariables_OPC_UA_client.set_obj_id].transform.SetParent(null);
                        }

                        main_state = 0;

                    }
                }
                break;
        }

        // ------------------------ Write Parameters { Param. GameObject Unity -> OpcUA B&R } ------------------------//
        GlobalVariables_OPC_UA_client.main_obj_id = GlobalVariables_OPC_UA_client.set_obj_id;

        // ------- Reset Parameters {Default Position, Rotation, Scale} ------- //
        if (GlobalVariables_OPC_UA_client.reset_param == true)
        {
            GlobalVariables_OPC_UA_client.main_obj_type = 0;

            // ------------------------ Initialization {Cube p[0 - 9] -> 9 parts} ------------------------//
            for (int i = 0; i <= 8; i++)
            {
                // Default - Position, Rotation, Scale
                cube_p[i].transform.localPosition = new Vector3(offset_x[i], offset_y[i], offset_z[i]);
                cube_p[i].transform.localEulerAngles = new Vector3(0f, 0f, 0f);
                cube_p[i].transform.localScale = new Vector3(1f, 1f, 1f);
                cube_p[i].transform.SetParent(init_pad.transform);

                // Freez Cube -> ON
                cube_p[i].GetComponent<Rigidbody>().isKinematic = true;
                // Trigger Collider -> OFF
                cube_p[i].GetComponent<MeshCollider>().convex = true;
            }
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
            // Destroy all
            Destroy(this);
        }
        catch (Exception e)
        {
            // Destroy all
            Destroy(this);
        }
    }
}
