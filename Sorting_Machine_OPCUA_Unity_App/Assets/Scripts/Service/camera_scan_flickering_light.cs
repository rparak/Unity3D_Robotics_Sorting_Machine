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
File Name: camera_scan_flickering_light.cs
****************************************************************************/

// ------------------------------------------------------------------------------------------------------------------------//
// ----------------------------------------------------- LIBRARIES --------------------------------------------------------//
// ------------------------------------------------------------------------------------------------------------------------//

// -------------------- System -------------------- //
using System.Collections;
// -------------------- Unity -------------------- //
using UnityEngine;

public class camera_scan_flickering_light : MonoBehaviour
{

    // -------------------- Light -------------------- //
    Light camera_light;
    // -------------------- Float -------------------- //
    float light_frequency = 0.05f;
    // -------------------- INT -------------------- //
    // Object Type: 1 -> SMC (blue), 2 -> BR (orange), 10 -> Err(red)
    private int[] obj_C = new int[9] { 1, 2, 1, 2, 10, 2, 1, 2, 1 };

    // ------------------------------------------------------------------------------------------------------------------------//
    // ------------------------------------------------ INITIALIZATION {START} ------------------------------------------------//
    // ------------------------------------------------------------------------------------------------------------------------//
    void Start()
    {
        // Initialization Light structure (turn off -> first)
        camera_light = GetComponent<Light>();
        camera_light.enabled = false;
    }

    // ------------------------------------------------------------------------------------------------------------------------ //
    // ------------------------------------------------ MAIN FUNCTION {Cyclic} ------------------------------------------------ //
    // ------------------------------------------------------------------------------------------------------------------------ //
    void Update()
    {
        if (GlobalVariables_OPC_UA_client.camera)
        {
            // Flickering Light
            StartCoroutine(FlickeringLight_Enable(camera_light, light_frequency));
            // Get the object type from the currently scanned object
            GlobalVariables_OPC_UA_client.main_obj_type = obj_C[GlobalVariables_OPC_UA_client.set_obj_id];
        }
    }

    // ------------------------------------------------------------------------------------------------------------------------//
    // -------------------------------------------------------- FUNCTIONS -----------------------------------------------------//
    // ------------------------------------------------------------------------------------------------------------------------//

    // -------------------- Flickering Light_Enable -------------------- //
    IEnumerator FlickeringLight_Enable(Light spot_light, float frequency)
    {
        spot_light.enabled = true;
        yield return new WaitForSeconds(frequency);
        spot_light.enabled = false;
        yield return new WaitForSeconds(frequency);
    }
}
