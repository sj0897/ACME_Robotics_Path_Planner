/**
 * @file arm.hpp
 * @brief The arm interface and dervied arm2D class
 * @author Chang-Hong Chen <longhongc@gmail.com>
 * @date 2022-10-18
 * @copyright 2022 longhongc@gmail.com sparshjaiswal97@gmail.com 
 *
*/

#pragma once
#include <vector>
#include<cmath>

/**
 * @Brief  A vector of joint_states
 */
using joint_states_vec = std::vector<std::vector<double>>;

/**
 * @Brief  The arm interface for 2D and 3D arm
 */
class Arm {
 public:
    /**
     * @Brief  Constructor
     *
     * @Param dof: Degree of freedom
     * @Param link_length: Length of all links
     */
    Arm(int dof, const std::vector<double>& link_length):
      dof_{dof},
      link_length_{link_length},
      joint_states_(dof, 0.0) {}
    /**
     * @Brief  Default constructor
     */
    Arm(): Arm(2, {1, 1}) {}
    /**
     * @Brief  Destructor
     */
    virtual ~Arm() {}


    /**
     * @Brief  Remove copy constructor
     *
     */
    Arm(const Arm&) = delete;
    /**
     * @Brief  Remove assignment constructor
     *
     */
    Arm& operator=(const Arm&) = delete;

    /**
     * @Brief  Forward kinematic
     *
     * @Param joint_states: The angle values of all joints
     *                      starting from the base link to the end-effector
     *
     * @Returns The end-effector pose (coordinate and orientation)
     */
    virtual std::vector<double> FK(const std::vector<double>& joint_states) = 0;
    /**
     * @Brief  Inverse kinematic
     *
     * @Param eef_pose: The pose of the end-effector,
     *                  including cartesian coordinate and orientation
     *
     * @Returns A vector of joint_states (IK can have multiple solutions or none)
     */
    virtual joint_states_vec IK(const std::vector<double>& eef_pose) = 0;

 protected:
    /**
     * @Brief Degree of freedom
     */
    int dof_;
    /**
     * @Brief Length of all links
     */
    std::vector<double> link_length_;
    /**
     * @Brief The angle values of all joints
     *        starting from the base link to the end-effector
     */
    std::vector<double> joint_states_;
};

/**
 * @Brief  A 2D planar arm class
 */
class Arm2D: public Arm {
 public:
    /**
     * @Brief Constructor
     *
     * @Param dof: Degree of freedom
     * @Param link_length: Length of all links
     */
    Arm2D(int dof, const std::vector<double>& link_length):
      Arm(dof, link_length),
      eef_pose_(3, 0.0) {
        eef_pose_ = Arm2D::FK(joint_states_);
      }

    /**
     * @Brief  Default constructor
     *
     */
    Arm2D(): Arm() {}

    /**
     * @Brief  Destructor
     */
    virtual ~Arm2D() {}

    /**
     * @Brief  Remove copy constructor
     *
     */
    explicit Arm2D(const Arm&) = delete;
    /**
     * @Brief  Remove assignment constructor
     *
     */
    Arm2D& operator=(const Arm&) = delete;

    /**
     * @Brief  Forward kinematic
     *
     * @Param joint_states: The angle values of all joints
     *                      starting from the base link to the end-effector
     *
     * @Returns The end-effector pose (coordinate and orientation)
     */
    std::vector<double> FK(const std::vector<double>& joint_states) override;
    /**
     * @Brief  Inverse kinematic
     *
     * @Param eef_pose: The pose of the end-effector,
     *                  including cartesian coordinate and orientation
     *
     * @Returns A vector of joint_states (IK can have multiple solutions or none)
     */

    joint_states_vec IK(const std::vector<double>& eef_pose) override;

 private:
    /**
     * @Brief The end-effector pose (coordinate and orientation)
     *        A 2D planar arm end-effector pose has x, y, and theta
     */
    std::vector<double> eef_pose_;
};
