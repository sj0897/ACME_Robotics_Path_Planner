[![Build Status](https://github.com/sj0897/ACME_Robotics_Path_Planner/actions/workflows/build_and_coveralls.yml/badge.svg)](https://github.com/sj0897/ACME_Robotics_Path_Planner/actions/workflows/build_and_coveralls.yml)
[![Coverage Status](https://coveralls.io/repos/github/sj0897/ACME_Robotics_Path_Planner/badge.png?branch=master)](https://coveralls.io/github/sj0897/ACME_Robotics_Path_Planner?branch=master)

# ACME Robotics Path Planner
This project is to design a path planner for various kind of robotics arm.  
A path planner can allow the robotics arm to move from one state to another and avoid collision through the trajectory. 

**Author:**  
|Name|UID|Github account|
|-----|-----|-----|
|Chang-Hong Chen|117397857|longhongc|
|Sparsh Jaiswal|117433968|sj0897| 

## Table of Contents
- [**Design & Methodology**](#design--methodology)  
- [**Build**](#build)  
- [**Run**](#run)  
- [**Demo**](#demo)  
- [**Docs**](#docs)  
 
## Design & Methodology
<details>
<summary>Phase 0 (Proposal)</summary>  
The detail of the proposal is in the Proposal directory.   

#### UML Diagram  
<img src="https://user-images.githubusercontent.com/28807825/195421760-ab0f5376-8b94-49ca-8258-db5514085743.png" alt="midterm_proposol_uml" width="700"/>  

#### Quad Chart
<img width="681" alt="808x_quad_chart" src="https://user-images.githubusercontent.com/28807825/195422070-405c3a34-ab3b-4419-8697-51e7f42a85fb.png">

#### Video 
https://www.youtube.com/watch?v=pWCyieuHHsQ  
</details>

<details>
<summary>Phase 1 (Design)</summary>  

#### Progress  
- [x] UML intial design
- [x] Classes barebone design
- [x] Building and documentng setup
- [x] Initial backlog design

#### UML Diagram  
<img width="627" alt="image" src="https://user-images.githubusercontent.com/28807825/196823499-77bd3877-373c-4830-aca9-364a7b79902c.png">

#### Activity Diagram
<img width="292" alt="image" src="https://user-images.githubusercontent.com/28807825/196823615-ef2368d8-55bd-4359-9561-c92042739156.png">

#### Video
https://youtu.be/x7Cnl6RYBdM
</details>

<details>
<summary>Phase 2 (Q1 release)</summary>  
Implemented the IK, FK, and planning class along with the visualization tool. 

#### UML Diagram  
<img width="627" alt="image" src="https://user-images.githubusercontent.com/28807825/196823499-77bd3877-373c-4830-aca9-364a7b79902c.png">

#### Video

https://youtu.be/2jF5UPY9P6g

</details>

## Build
```
mkdir build && cd build
cmake ..
make -j
```

## Run
```
cd build/app
./shell-app
```

## Demo
Copy the generated trajectory config to script folder.  
Then visualize the arm trajectory with the visualize_arm.py script. 
```
cd scripts
cp ../build/app/arm_traj.yaml .
python3 visualize_arm.py
```
### Results
The blue dots are the joints and the light blue lines are the links.  
The arm is moving from a state to another.  
![example](https://user-images.githubusercontent.com/28807825/198857109-ea1e47ce-856e-4804-93dc-5e3d52243b65.png)


## Docs
The development docs and doxygen docs are in the documents folder.

### Generate doxygen docs
The doxygen docs will automatically be generated in the documents folder. 
```
doxygen Doxyfile
```

## Links

https://docs.google.com/spreadsheets/d/13U8-sXTIre1m_5L26LODDyiWqxcg9dg30RVNmKRkZ0Y/edit#gid=636711951





