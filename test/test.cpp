/**
 * @file test.cpp
 * @brief File containing all the unit tests
 * @author Sparsh Jaiswal <sparshjaiswal97@gmail.com>
 * @date 2022-10-28
 * @copyright 2022 longhongc@gmail.com sparshjaiswal97@gmail.com 
 *
*/

#include <gtest/gtest.h>
#include <vector>
#include <../include/arm.hpp>
#include <../include/path_planner.hpp>

///> Test to check the Forward Kinematics of the 2d arm
TEST(FK, test_case_1) {
  Arm2D test(2, {1, 1});
  std::vector<double> result = {2, 0};
  EXPECT_EQ(test.FK({0, 0}), result);
}

///> Test to check the Inverse kinematics of the 2d arm
TEST(IK, test_case_1) {
  std::vector<double> links = {1, 1};
  Arm2D test(2, links);
  std::vector<std::vector<double>> result = {{1.57, 0}};
  EXPECT_EQ(test.IK({0, 2}), result);
}

///> Test to check the plan method of the planner
TEST(plan, test_case_1) {
  std::vector<double> links = {1, 1};
  Arm2D trial(2, links);
  std::vector<double> start = {0, 0};
  std::vector<double> goal = {1.57, 0};
  PathPlanner testPlanner(&trial, start, goal);

  std::vector<std::vector<double>> result;
  result = {{0.157*1, 0}, {0.157*2, 0}, {0.157*3, 0},
              {0.157*4, 0}, {0.157*5, 0}, {0.157*6, 0},
                {0.157*7, 0}, {0.157*8, 0}, {0.157*9, 0},
                  {0.157*10, 0}};

  joint_states_vec plan = testPlanner.plan();

  EXPECT_EQ(result, plan);
}

TEST(is_obstacle, test_case_1) {
  std::vector<double> links = {1, 1};
  Arm2D trial(2, links);
  std::vector<double> start = {0, 0};
  std::vector<double> goal = {1.57, 0};
  PathPlanner testPlanner(&trial, start, goal);
  EXPECT_EQ(testPlanner.is_obstacle(links), false);
}
