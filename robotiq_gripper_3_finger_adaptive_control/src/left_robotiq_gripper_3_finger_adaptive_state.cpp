#include <ros/ros.h>
#include <robotiq_gripper_3_finger_adaptive_control/left_robotiq_gripper_3_finger_adaptive_motoman_io.h>
#include <robotiq_gripper_3_finger_adaptive_control/robotiq_gripper_3_finger_adaptive_output_driver.h>
#include <robotiq_gripper_3_finger_adaptive_control/robotiq_gripper_3_finger_adaptive_input_driver.h>

int main(int argc, char ** argv) {
  ros::init(argc, argv, "left_robotiq_gripper_3_finger_adaptive_state");
  ros::NodeHandle nh;
  ros::Publisher joint_pub = nh.advertise < sensor_msgs::JointState > ("joint_states", 1);
  ros::AsyncSpinner spinner(2);
  ros::Rate loop_rate(30);

  GripperServices serv_grip;

  serv_grip.joint_state.name.resize(11);
  serv_grip.joint_state.position.resize(11);

  serv_grip.joint_state.name[0] = "left_gripper_finger_joint_a_1";
  serv_grip.joint_state.name[1] = "left_gripper_finger_joint_a_2";
  serv_grip.joint_state.name[2] = "left_gripper_finger_joint_a_3";
  serv_grip.joint_state.name[3] = "left_gripper_finger_joint_a_4";
  serv_grip.joint_state.name[4] = "left_gripper_finger_joint_b_1";
  serv_grip.joint_state.name[5] = "left_gripper_finger_joint_b_2";
  serv_grip.joint_state.name[6] = "left_gripper_finger_joint_b_3";
  serv_grip.joint_state.name[7] = "left_gripper_finger_joint_b_4";
  serv_grip.joint_state.name[8] = "left_gripper_finger_joint_c_2";
  serv_grip.joint_state.name[9] = "left_gripper_finger_joint_c_3";
  serv_grip.joint_state.name[10] = "left_gripper_finger_joint_c_4";

  serv_grip.joint_state.position[0] = 0;
  serv_grip.joint_state.position[1] = 0;
  serv_grip.joint_state.position[2] = 0;
  serv_grip.joint_state.position[3] = 0;
  serv_grip.joint_state.position[4] = 0;
  serv_grip.joint_state.position[5] = 0;
  serv_grip.joint_state.position[6] = 0;
  serv_grip.joint_state.position[7] = 0;
  serv_grip.joint_state.position[8] = 0;
  serv_grip.joint_state.position[9] = 0;
  serv_grip.joint_state.position[10] = 0;

  ros::ServiceServer service_action_request = nh.advertiseService("left_gripper/action_request", & GripperServices::action_request, & serv_grip);
  ros::ServiceServer service_gripper_option_1 = nh.advertiseService("left_gripper/gripper_option_1", & GripperServices::gripper_option_1, & serv_grip);

  ros::ServiceServer service_finger_position_speed_force_request_a_individual_mode = nh.advertiseService("left_gripper/finger_position_speed_force_request_a_individual_mode", & GripperServices::finger_position_speed_force_request_a_individual_mode, & serv_grip);
  ros::ServiceServer service_finger_position_speed_force_request_b = nh.advertiseService("left_gripper/finger_position_speed_force_request_b", & GripperServices::finger_position_speed_force_request_b, & serv_grip);
  ros::ServiceServer service_finger_position_speed_force_request_c = nh.advertiseService("left_gripper/finger_position_speed_force_request_c",  & GripperServices::finger_position_speed_force_request_c, & serv_grip);
  ros::ServiceServer service_scissor_position_speed_force_request = nh.advertiseService("left_gripper/scissor_position_speed_force_request",  & GripperServices::scissor_position_speed_force_request, & serv_grip);

  //ros::ServiceServer service_finger_a_position = nh.advertiseService("left_gripper/finger_a_position", finger_a_position);
  //ros::ServiceServer service_finger_b_position = nh.advertiseService("left_gripper/finger_b_position", finger_b_position);
  //ros::ServiceServer service_finger_c_position = nh.advertiseService("left_gripper/finger_c_position", finger_c_position);

  spinner.start();

  while (ros::ok()) {
    serv_grip.joint_state.header.stamp = ros::Time::now();
    joint_pub.publish(serv_grip.joint_state);

    loop_rate.sleep();
  }
  return 0;
}
