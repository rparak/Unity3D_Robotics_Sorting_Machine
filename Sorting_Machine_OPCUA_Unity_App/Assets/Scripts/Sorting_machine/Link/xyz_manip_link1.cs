﻿// ------------------------------------------------------------------------------------------------------------------------//
// ----------------------------------------------------- LIBRARIES --------------------------------------------------------//
// ------------------------------------------------------------------------------------------------------------------------//

// -------------------- Unity -------------------- //
using UnityEngine;

public class xyz_manip_link1 : MonoBehaviour
{
    void FixedUpdate()
    {
        transform.localPosition = new Vector3(0f, 0.1034999f, 0.001499951f + GlobalVariables_OPC_UA_client.xyz_manip_pos[0] / 10000);
    }
    void OnApplicationQuit()
    {
        Destroy(this);
    }
}