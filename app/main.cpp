/**
 * @file main.cpp
 * @brief Main executable file
 * @author Sparsh Jaiswal <sparshjaiswal97@gmail.com>
 * @date 2022-10-28
 * @copyright 2022 longhongc@gmail.com sparshjaiswal97@gmail.com 
 *
*/

#include <iostream>
#include <vector>
#include <arm.hpp>
#include <path_planner.hpp>
#include <utils.hpp>

int main() {
    std::vector<double> links = {3, 3};
    Arm2D twoD(2, links);

    std::vector<std::vector<double>> target_state = twoD.IK({{0, 2}});
    std::vector<double> goal = target_state[0];
    std::vector<double> start = {0, 0};
    PathPlanner Planner(&twoD, start, goal);

    std::vector<std::vector<double>> plan = Planner.plan();
    std::vector<std::vector<double>> eef_pos;
    std::vector<std::vector<double>> all_joints_pos;
    std::vector<double> all_joints_step;
    // std::vector<double> eef_step;

    for (int i = 0; i < 10 ; i++) {
        double x, y;
        auto eef_step = twoD.FK(plan[i]);
        eef_pos.emplace_back(eef_step);
        x = links[0]* cos(plan[i][0]);
        y = links[0]* sin(plan[i][0]);

        all_joints_step.clear();
        all_joints_step.emplace_back(x);
        all_joints_step.emplace_back(y);
        all_joints_step.emplace_back(eef_step[0]);
        all_joints_step.emplace_back(eef_step[1]);

        // {{x1,y1,x2,y2}{x1,y1,x2,y2}{x1,y1,x2,y2}{x1,y1,x2,y2}}
        all_joints_pos.emplace_back(all_joints_step);
    }

    std::vector<utils::pose_type> arm_traj;
    for (auto& joint_pos : all_joints_pos) {
        std::vector<double> joint1{joint_pos.at(0), joint_pos.at(1)};
        std::vector<double> joint2{joint_pos.at(2), joint_pos.at(3)};
        utils::pose_type joints_pos{joint1, joint2};
        arm_traj.emplace_back(joints_pos);
    }
    utils::create_arm_traj_YAML(2, links, arm_traj);

    return 0;
}
