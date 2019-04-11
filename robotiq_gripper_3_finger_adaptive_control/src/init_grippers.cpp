#include <ros/ros.h>

#include "robotiq_gripper_3_finger_adaptive_control/action_request.h"
#include "robotiq_gripper_3_finger_adaptive_control/gripper_option_1.h"
#include "robotiq_gripper_3_finger_adaptive_control/position_speed_force_request.h"

int main(int argc, char ** argv) {
  ros::init(argc, argv, "init_grippers");
  ros::NodeHandle node_handle;

  ros::Duration(5.0).sleep();

  ros::ServiceClient serv_gripper_act = node_handle.serviceClient < robotiq_gripper_3_finger_adaptive_control::action_request > ("left_gripper/action_request");
  ros::ServiceClient serv_gripper_psf = node_handle.serviceClient < robotiq_gripper_3_finger_adaptive_control::position_speed_force_request > ("left_gripper/finger_position_speed_force_request_a_individual_mode");

  robotiq_gripper_3_finger_adaptive_control::action_request::Request calib;
  robotiq_gripper_3_finger_adaptive_control::action_request::Response calib_success;

  robotiq_gripper_3_finger_adaptive_control::position_speed_force_request::Request position_speed_force;
  robotiq_gripper_3_finger_adaptive_control::position_speed_force_request::Response position_speed_force_success;

  calib.gripper_status = true;
  calib.gripper_mode = 0;
  calib.go_to= true;
  calib.automatic_release = false;

  position_speed_force.position_request = 0;
  position_speed_force.speed_request = 0;
  position_speed_force.force_request = 0;

  serv_gripper_psf.call(position_speed_force, position_speed_force_success);
  serv_gripper_act.call(calib, calib_success);

  serv_gripper_act = node_handle.serviceClient < robotiq_gripper_3_finger_adaptive_control::action_request > ("right_gripper/action_request");
  serv_gripper_psf = node_handle.serviceClient < robotiq_gripper_3_finger_adaptive_control::position_speed_force_request > ("right_gripper/finger_position_speed_force_request_a_individual_mode");

  serv_gripper_psf.call(position_speed_force, position_speed_force_success);
  serv_gripper_act.call(calib, calib_success);

  return 0;
}
