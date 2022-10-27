#include <gtest/gtest.h>
#include <arm.hpp>
#include <vector>

TEST(FK, test_case_1) {
  Arm2D test(2,{1,1});
  std::vector<double> result = {2,0};
  EXPECT_EQ(test.FK({0,0}), result);
}

TEST(IK, test_case_1) {
  Arm2D test(2,{1,1});
  std::vector<std::vector<double>> result = {{0},{0}};
  EXPECT_EQ(test.IK({2,0}), result);
}