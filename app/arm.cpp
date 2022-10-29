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

std::vector<double> Arm2D::FK(const std::vector<double>& joint_states) {
    ///> Temporary Variable to store the x coordinate
    double x = link_length_[0]*cos(joint_states[0])
                + link_length_[1]*cos(joint_states[0]
                   + joint_states[1]);
    ///> Temporary Variable to store the y coordinate
    double y = link_length_[0]*sin(joint_states[0])
                + link_length_[1]*sin(joint_states[0]
                   + joint_states[1]);

    return { x, y };
}

joint_states_vec Arm2D::IK(const std::vector<double>& eef_pose) {
    ///> Temporary Variables to store the x&y coordinate of eef
    double x = eef_pose[0];
    double y = eef_pose[1];

    ///> Temporary Variable to store the a & b for math operations
    double a = x*x + y*y
                - pow(link_length_[0], 2)
                    - pow(link_length_[1], 2);

    double b = 2*link_length_[0]*link_length_[1];

    ///> Temporary Variable to store the second joint angle
    double theta_2 = acos(a/b);

    ///> Temporary Variable to store the c & d for math operations
    double c = link_length_[0]*sin(theta_2);

    double d = link_length_[0]
                + link_length_[1]*cos(theta_2);

    ///> Temporary Variable to store the first joint angle
    double theta_1 = atan(y/x) - atan(c/d);

    theta_1 = trunc(theta_1*1000)/1000;
    theta_2 = trunc(theta_2*1000)/1000;

    return {{theta_1, theta_2}};
}
