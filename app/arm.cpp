/**
 * @file arm.cpp
 * @brief The arm interface and dervied arm2D class
 * @author Sparsh Jaiswal <sparshjaiswal97@gmail.com>
 * @date 2022-10-18
 * @copyright 2022 longhongc@gmail.com sparshjaiswal97@gmail.com 
 *
*/

#include <arm.hpp>
#include <math.h>

std::vector<double> Arm2D::FK(const std::vector<double>& joint_states){

    double x = link_length_[0]*cos(joint_states[0]) + link_length_[2]*cos(joint_states[0] + joint_states[1]);
    double y = link_length_[0]*sin(joint_states[0]) + link_length_[2]*sin(joint_states[0] + joint_states[1]);

    return {x,y};




}

joint_states_vec Arm2D::IK(const std::vector<double>& eef_pose){

}
