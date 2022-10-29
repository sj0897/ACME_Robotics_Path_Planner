#include <iostream>
#include <arm.hpp>
#include <path_planner.hpp>
#include <vector>

int main()
{
    std::vector<double> links = {1,1};
    Arm2D twoD(2,links);

    std::vector<std::vector<double>> target_state = twoD.IK({{0,2}});
    std::vector<double> goal = target_state[0];
    std::vector<double> start = {0,0};
    PathPlanner Planner(&twoD,start,goal);
    
    std::vector<std::vector<double>> plan = Planner.plan();
    std::vector<std::vector<double>> eef_pos;
    
    for(int i = 0; i<10;i++){
        eef_pos.emplace_back(twoD.FK(plan[i]));

    }

    

    return 0;
}
