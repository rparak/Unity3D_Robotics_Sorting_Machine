# Sorting Machine (B&R Automation, SMC) - Unity3D Robotics

## Requirements:

**Software:**
```bash
B&R Automation Studio, Unity3D 2020.1.8f1, Visual Studio 2017/2019
```

**Supported on the following operating systems:**
```bash
Universal Windows Platform, Android
```

Unity3D: https://unity3d.com/get-unity/download/archive

Unity HDRI Pack: https://assetstore.unity.com/packages/2d/textures-materials/sky/unity-hdri-pack-72511

B&R Automation: https://www.br-automation.com/en/downloads/#categories=Software-1344987434933

Visual Studio: https://visualstudio.microsoft.com/downloads/

## Project Description:

The project is focused on a simple demonstration of client / server communication via OPC UA, which is implemented in Unity3D (Server - B&R Automation PLC, Client - Unity3D). The project demonstrates the Digital-Twin of the Sorting Machine with some additional functions. The application uses performance optimization using multi-threaded programming.

This solution can be used to control a real machine or to simulate it (Automation Studio Runtime Simulation/ Real PLC). The Unity3D Digital-Twin application was tested on the simulation using X20CP1584 PLC. It is possible to use another OPC UA server, but in accordance with certain principles (Input / Output nodes).

Example of a simple data processing application:

[OPC UA B&R Automation - Data Processing](https://github.com/rparak/OPCUA_Simple)

Main functions of the Sorting Machine Digital-Twin model:
- Camera Control
- Connect/Disconnect -> Real HW or Simulation (OPC UA Communication)
- Read Data (Position / Speed of the HW)
- Write Data (Attach / Detach of the object, Type of the object, etc.)
- NVIDIA PhysX, etc.

The application can be installed on a mobile phone, tablet or computer, but for communication with the robot it is necessary to be in the same network.

The project was realized at Institute of Automation and Computer Science, Brno University of Technology, Faculty of Mechanical Engineering (NETME Centre - Cybernetics and Robotics Division).

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_Sorting_Machine/blob/main/images/sorting_machine_model.png" width="775" height="450">
</p>

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_Sorting_Machine/blob/main/images/sm_1.PNG" width="800" height="500">
</p>

## Project Hierarchy:

**Repositary [/Unity3D_Robotics_Sorting_Machine/]:**
```bash
/Sorting_Machine_OPCUA_Unity_App/ -> Unity3D Project
[ UI + Main Control            ] /Assets/Script/UI/
[ Data Processing              ] /Assets/Script/Sorting_machine/
[ Object / Light Control       ] /Assets/Script/Service/
[ Individual objects (.blend)  ] /Assets/Object/Blender/
[ Images (UI)                  ] /Assets/Image/
[ Scene of the Application     ] /Assets/Scenes/

/3D_Model/
[ Blender model of the SM          ] /Blender/
[ Inventor model of the SM (.step) ] /Inventor/

/Sorting_Machine_DT/ -> Automatio Studio B&R Project
[ Function Block (Axis Control) ] /Logical/Libraries/rp_funcx/
[ Main Program                  ] /Logical/Main_Control/
[ XYZ Manipulator Program       ] /Logical/XYZ_MANIPULATOR/
[ Camera Conveyor Program       ] /Logical/CAMERA_CONVEYOR/
[ MappView Visualization        ] /Logical/mappView/
```

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_Sorting_Machine/blob/main/images/sm_2.PNG" width="800" height="500">
</p>

## Digital-Twin Application:


## Result:

Youtube: comming soon

## Contact Info:
Roman.Parak@outlook.com

## License
[MIT](https://choosealicense.com/licenses/mit/)

