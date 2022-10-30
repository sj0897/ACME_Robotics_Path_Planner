#include <vector>
#include <fstream>
#include <yaml-cpp/yaml.h>
using std::vector;
using std::ofstream;

/**
 * @Brief  Utility functions
 */
namespace utils {
  /**
   * @Brief  A simple test example of the yaml-cpp library
   */
  inline void create_simple_YAML() {
    YAML::Emitter out; 
    out << YAML::BeginMap; 
    out << YAML::Key << "dof"; 
    out << YAML::Value << 2; 

    vector<double> link_length{3, 3};
    out << YAML::Key << "link_length"; 
    out << YAML::Value << YAML::Flow << link_length; 

    vector<vector<double>> pose{{2.6, 1.5}, {4.1, 4.1}};
    out << YAML::Key << "trajectory"; 
    out << YAML::Value << YAML::Flow << pose; 

    ofstream fout("test.yaml");
    fout << out.c_str();
  }

  using pose_type = vector<vector<double>>; 
  /**
   * @Brief Emit the arm trajectory info into a yaml file 
   *
   * @Param dof: The degree of freedom of the robot
   * @Param link_length: Length of each link
   * @Param pose: A pose consisit of a list of joint coordinates 
   *              (the coordinate of end of each link)
   *              For example: A two link arm has two end of link coordinates.
   *              The pose might be something like 
   *              {{coord of end of first link}, {coord of end-effector}}
   */
  inline void create_arm_traj_YAML(const int dof, 
                                   const vector<double>& link_length,
                                   const vector<pose_type>& poses) {
    YAML::Emitter out; 
    out << YAML::BeginMap; 
    out << YAML::Key << "dof"; 
    out << YAML::Value << dof; 

    out << YAML::Key << "link_length"; 
    out << YAML::Value << YAML::Flow << link_length; 

    out << YAML::Key << "trajectory"; 
    out << YAML::Value << YAML::Flow << poses; 

    ofstream fout("arm_traj.yaml");
    fout << out.c_str();
  }
}
