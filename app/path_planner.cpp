/**
 * @file path_planner.cpp
 * @brief The path planner class that plans a collistion-free
 *        trajectory from start to goal
 * @author Sparsh Jaiswal <sparshjaiswal97@gmail.com>
 * @date 2022-10-18
 * @copyright 2022 longhongc@gmail.com sparshjaiswal97@gmail.com 
 *
*/

#include <cstdio>
#include <path_planner.hpp>
#include <vector>

bool PathPlanner::is_obstacle(const std::vector<double>& state){
    return false;
}

joint_states_vec PathPlanner::plan(){
    double theta_1_step = (goal_state_[0] - start_state_[0])/10;
    double theta_2_step = (goal_state_[1] - start_state_[1])/10;

    double theta_1_start = start_state_[0];
    double theta_2_start = start_state_[2];

    std::vector<double> step;

    for(int i=0; i<10; i++){
        theta_1_start += theta_1_step;
        theta_2_start += theta_2_step;
        step.clear();
        step.emplace_back(theta_1_start);
        step.emplace_back(theta_2_start);

        path_.emplace_back(step);

    }

    return path_;
}

void PathPlanner::a_star(){

}

void PathPlanner::rrt(){

}