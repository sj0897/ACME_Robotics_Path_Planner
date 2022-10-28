/**
 * @file path_planner.hpp
 * @brief The path planner class that plans a collistion-free
 *        trajectory from start to goal
 * @author Chang-Hong Chen <longhongc@gmail.com>
 * @date 2022-10-18
 * @copyright 2022 longhongc@gmail.com sparshjaiswal97@gmail.com 
 *
*/

#pragma once
#include <memory>
#include <vector>
#include "./arm.hpp"

/**
 * @Brief  The path planner class calculates a collision-free path
 *         for the given manipulator to move from start state
 *         to the goal state
 */
class PathPlanner {
 public:
    /**
     * @Brief  Constructor
     *
     * @Param arm: The target manipulator
     * @Param start: A start joints state
     * @Param goal: A goal joints state
     */
    PathPlanner(Arm* arm,
                const std::vector<double>& start,
                const std::vector<double>& goal):
      arm_ptr_{arm},
      start_state_{start},
      goal_state_{goal} {};

    ~PathPlanner(){
      arm_ptr_.release();
    };

    /**
     * @Brief  Check if the joints state is within obstacles
     *
     * @Param state: A joints state
     *
     * @Returns Is collide or not
     */
    bool is_obstacle(const std::vector<double>& state);
    /**
     * @Brief  Plan a collision-free path from start to goal
     *
     * @Returns A collision free path if exisit
     */
    joint_states_vec plan();
    /**
     * @Brief  A-Star algorithm for path finding
     */
    void a_star();
    /**
     * @Brief  RRT algorithm for path finding
     */
    void rrt();

 private:
    /**
     * @Brief  A pointer of the target manipulator
     */
    std::unique_ptr<Arm> arm_ptr_;
    /**
     * @Brief  A start joints state
     */
    std::vector<double> start_state_;
    /**
     * @Brief  A goal joints state
     */
    std::vector<double> goal_state_;
    /**
     * @Brief  A collision-free path from start to goal
     */
    joint_states_vec path_;
};

