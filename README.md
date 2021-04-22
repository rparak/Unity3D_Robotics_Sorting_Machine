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

The main idea of the application is to use the XYZ manipulator and another axis (camera conveyor) to sort multiple objects. For visual inspection of the object, we use a 2D camera with additional light and the entire control program (axis control, alarm handling, attach / detach of objects, and others) is programmed on the PLC (OPC UA Server). The Unity3d digital-twin application is used to visualize the scene, manipulate objects, and obtain information about the type of object. The application also uses a package (Human-Machine interface - mappView) for data visualization. This data can be viewed locally on the PC panel or remotely on any device using a standard web browser (data management in mappView is completely based on OPC UA).

**MappView (HMI):**
```bash
Simulation Address
PLC_ADDRESS = localhost or 127.0.0.1

http://PLC_ADDRESS:81/index.html?visuId=sm_digital_twin
```

The sorting machine is a simulation model (designed by the author of the application), so far there is no real identical machine.

Example of a simple data processing application (OPC UA):

[OPC UA B&R Automation - Data Processing](https://github.com/rparak/OPCUA_Simple)

Example of an application for controlling the movement of single axis (OPC UA, Unity3D, Mapp View, etc.):

[B&R Automation Workshop](https://github.com/rparak/BaR-Workshop-Simple)

Main functions of the Sorting Machine Digital-Twin model:
- Camera Control
- Connect/Disconnect -> Real HW or Simulation (OPC UA Communication)
- Read Data (Position / Speed of the HW)
- Write Data (Attach / Detach of the object, Type of the object, etc.)
- NVIDIA PhysX, etc.

The application can be installed on a mobile phone, tablet or computer, but for communication with the machine it is necessary to be in the same network.

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

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_Sorting_Machine/blob/main/images/dt_1.png" width="800" height="500">
</p>

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_Sorting_Machine/blob/main/images/dt_2.png" width="800" height="500">
</p>

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_Sorting_Machine/blob/main/images/dt_3.png" width="800" height="500">
</p>

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_Sorting_Machine/blob/main/images/dt_4.png" width="800" height="500">
</p>

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_Sorting_Machine/blob/main/images/dt_5.png" width="800" height="500">
</p>

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_Sorting_Machine/blob/main/images/dt_6.png" width="800" height="500">
</p>

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_Sorting_Machine/blob/main/images/dt_7.png" width="800" height="500">
</p>

## HMI (Human-Machine Interface) - MappView:

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_Sorting_Machine/blob/main/images/mv_1.png" width="800" height="500">
</p>

<p align="center">
<img src="https://github.com/rparak/Unity3D_Robotics_Sorting_Machine/blob/main/images/mv_2.PNG" width="800" height="500">
</p>


## Result:

Youtube: https://www.youtube.com/watch?v=AlEid_gWuA8&t=2s

## Contact Info:
Roman.Parak@outlook.com

## License
[MIT](https://choosealicense.com/licenses/mit/)

