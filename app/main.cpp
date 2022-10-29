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
    std::vector<std::vector<double>> all_joints_pos;
    std::vector<double> all_joints_step;
    // std::vector<double> eef_step;

    double x,y;
    
    for(int i = 0; i<10;i++){

        auto eef_step = twoD.FK(plan[i]);
        eef_pos.emplace_back(eef_step);
        x = links[0]* cos(plan[i][0]);
        y = links[0]* sin(plan[i][0]);

        all_joints_step.clear();
        all_joints_step.emplace_back(x);
        all_joints_step.emplace_back(y);
        all_joints_step.emplace_back(eef_step[0]);
        all_joints_step.emplace_back(eef_step[1]);

        all_joints_pos.emplace_back(all_joints_step);





    }

    

    return 0;
}
