#ifndef ROBOTIQ_GRIPPER_3_FINGER_ADAPTIVE_OUTPUT_DRIVER
#define ROBOTIQ_GRIPPER_3_FINGER_ADAPTIVE_OUTPUT_DRIVER

#include <iostream>
#include <bitset>
#include <string>

#include <sensor_msgs/JointState.h>

#include <robotiq_gripper_3_finger_adaptive_control/robotiq_gripper_3_finger_adaptive_motoman_io.h>

#include "robotiq_gripper_3_finger_adaptive_control/action_request.h"
#include "robotiq_gripper_3_finger_adaptive_control/gripper_option_1.h"
#include "robotiq_gripper_3_finger_adaptive_control/position_speed_force_request.h"


class GripperServices
{
public:

sensor_msgs::JointState joint_state;

bool rACT(bool gripper_status) {
  bool success;
  if (gripper_status == true) {
    success = WriteValvue(gripper_status_motoman, 1, "rACT");
  } else {
    success = WriteValvue(gripper_status_motoman, 0, "rACT");
  }

  joint_state.position[0] = 0;
  joint_state.position[1] = 0;
  joint_state.position[2] = 0;
  joint_state.position[3] = 0;
  joint_state.position[4] = 0;
  joint_state.position[5] = 0;
  joint_state.position[6] = 0;
  joint_state.position[7] = 0;
  joint_state.position[8] = 0;
  joint_state.position[9] = 0;
  joint_state.position[10] = 0;

  return success;
}

bool rMOD(int gripper_mode) {
  bool success;
  gripper_mode > 3 ? gripper_mode = 3 : gripper_mode < 0 ? gripper_mode = 0 : gripper_mode = gripper_mode;
  switch (gripper_mode) {
  case 0:
  success = (WriteValvue(gripper_mode_motoman_b0, 0, "rMOD") && WriteValvue(gripper_mode_motoman_b1, 0, "rMOD"));
  joint_state.position[0] = 0;
  joint_state.position[1] = 0;
  joint_state.position[2] = 0;
  joint_state.position[3] = 0;
  joint_state.position[4] = 0;
  joint_state.position[5] = 0;
  joint_state.position[6] = 0;
  joint_state.position[7] = 0;
  joint_state.position[8] = 0;
  joint_state.position[9] = 0;
  joint_state.position[10] = 0;

    break;
  case 1:
    success = (WriteValvue(gripper_mode_motoman_b0, 1, "rMOD") && WriteValvue(gripper_mode_motoman_b1, 0, "rMOD"));
  joint_state.position[0] = 0.1744;
  joint_state.position[1] = 0;
  joint_state.position[2] = 0;
  joint_state.position[3] = 0;
  joint_state.position[4] = 0.1744;
  joint_state.position[5] = 0;
  joint_state.position[6] = 0;
  joint_state.position[7] = 0;
  joint_state.position[8] = 0;
  joint_state.position[9] = 0;
  joint_state.position[10] = 0;

    break;
  case 2:
    success = (WriteValvue(gripper_mode_motoman_b0, 0, "rMOD") && WriteValvue(gripper_mode_motoman_b1, 1, "rMOD"));
  joint_state.position[0] = -0.1755;
  joint_state.position[1] = 0;
  joint_state.position[2] = 0;
  joint_state.position[3] = 0;
  joint_state.position[4] = -0.1755;
  joint_state.position[5] = 0;
  joint_state.position[6] = 0;
  joint_state.position[7] = 0;
  joint_state.position[8] = 0;
  joint_state.position[9] = 0;
  joint_state.position[10] = 0;

    break;
  case 3:
    success = (WriteValvue(gripper_mode_motoman_b0, 1, "rMOD") && WriteValvue(gripper_mode_motoman_b1, 1, "rMOD"));
  joint_state.position[0] = -0.1755;
  joint_state.position[1] = 0;
  joint_state.position[2] = 0;
  joint_state.position[3] = 0;
  joint_state.position[4] = -0.1755;
  joint_state.position[5] = 0;
  joint_state.position[6] = 0;
  joint_state.position[7] = 0;
  joint_state.position[8] = 0;
  joint_state.position[9] = 0;
  joint_state.position[10] = 0;

    break;
  default:
    ROS_ERROR_STREAM("Failed to rMOD");
    success = false;
  }
  return success;
}

bool rGTO(bool go_to) {
  bool success;
  if (go_to == true) {
    success = WriteValvue(go_to_motoman, 1, "rGTO");
  } else {
    success = WriteValvue(go_to_motoman, 0, "rGTO");
  }
  return success;
}

bool rATR(bool automatic_release) {
  bool success;
  if (automatic_release == true) {
    success = WriteValvue(automatic_release_motoman, 1, "rATR");
  } else {
    success = WriteValvue(automatic_release_motoman, 0, "rATR");
  }
  return success;
}

bool rICF(bool individual_control_fingers_mode) {
  bool success;
  if (individual_control_fingers_mode == true) {
    success = WriteValvue(individual_control_fingers_mode_motoman, 1, "rICF");
  } else {
    success = WriteValvue(individual_control_fingers_mode_motoman, 0, "rICF");
  }
  return success;
}

bool rICS(bool individual_control_scissor) {
  bool success;
  if (individual_control_scissor == true) {
    success = WriteValvue(individual_control_scissor_motoman, 1, "rICF");
  } else {
    success = WriteValvue(individual_control_scissor_motoman, 0, "rICF");
  }
  return success;
}

bool rPRA(int binary) {
  bool success;
  bool go_to = ReadValvue(go_to_motoman);
  if (go_to == true) {
    WriteValvue(go_to_motoman, 0, "rGTO");
    ros::Duration(0.1).sleep();
  }

  success = WriteByte(position_request_a_motoman, binary, "position_request_a");

  if (go_to == true) {
    WriteValvue(go_to_motoman, 1, "rGTO");
    ros::Duration(0.1).sleep();
  }
  return success;
}

bool rSPA(int binary) {
  return WriteByte(speed_request_a_motoman, binary, "speed_request_a");
}

bool rFRA(int binary) {
  return WriteByte(force_request_a_motoman, binary, "force_request_a");
}

bool rPRB(int binary) {
  bool success;
  bool go_to = ReadValvue(go_to_motoman);
  if (go_to == true) {
    WriteValvue(go_to_motoman, 0, "rGTO");
    ros::Duration(0.1).sleep();
  }

  success = WriteByte(position_request_b_motoman, binary, "position_request_b");

  if (go_to == true) {
    WriteValvue(go_to_motoman, 1, "rGTO");
    ros::Duration(0.1).sleep();
  }
  return success;
}

bool rSPB(int binary) {
  return WriteByte(speed_request_b_motoman, binary, "speed_request_b");
}

bool rFRB(int binary) {
  return WriteByte(force_request_b_motoman, binary, "force_request_b");
}

bool rPRC(int binary) {
  bool success;
  bool go_to = ReadValvue(go_to_motoman);
  if (go_to == true) {
    WriteValvue(go_to_motoman, 0, "rGTO");
    ros::Duration(0.1).sleep();
  }

  success = WriteByte(position_request_c_motoman, binary, "position_request_c");

  if (go_to == true) {
    WriteValvue(go_to_motoman, 1, "rGTO");
    ros::Duration(0.1).sleep();
  }
  return success;
}

bool rSPC(int binary) {
  return WriteByte(speed_request_c_motoman, binary, "speed_request_c");
}

bool rFRC(int binary) {
  return WriteByte(force_request_c_motoman, binary, "force_request_c");
}

bool rPRS(int binary) {
  bool success;
  bool go_to = ReadValvue(go_to_motoman);
  if (go_to == true) {
    WriteValvue(go_to_motoman, 0, "rGTO");
    ros::Duration(0.1).sleep();
  }

  success = WriteByte(position_request_scissor_motoman, binary, "position_request_scissor");

  if (go_to == true) {
    WriteValvue(go_to_motoman, 1, "rGTO");
    ros::Duration(0.1).sleep();
  }
  return success;
}

bool rSPS(int binary) {
  return WriteByte(speed_request_scissor_motoman, binary, "speed_request_scissor");
}

bool rFRS(int binary) {
  return WriteByte(force_request_scissor_motoman, binary, "force_request_scissor");
}

bool action_request(robotiq_gripper_3_finger_adaptive_control::action_request::Request & req,
  robotiq_gripper_3_finger_adaptive_control::action_request::Response & res) {
  res.success = (rACT(req.gripper_status) && rMOD(req.gripper_mode) && rGTO(req.go_to) && rATR(req.automatic_release));
  return res.success;
}

bool gripper_option_1(robotiq_gripper_3_finger_adaptive_control::gripper_option_1::Request & req,
  robotiq_gripper_3_finger_adaptive_control::gripper_option_1::Response & res) {
  res.success = (rICF(req.individual_control_fingers_mode) && rICS(req.individual_control_scissor));
  return res.success;
}

bool finger_position_speed_force_request_a_individual_mode(robotiq_gripper_3_finger_adaptive_control::position_speed_force_request::Request & req,
  robotiq_gripper_3_finger_adaptive_control::position_speed_force_request::Response & res) {
  res.success = (rPRA(req.position_request) && rSPA(req.speed_request) && rFRA(req.force_request));
  return res.success;
}

bool finger_position_speed_force_request_b(robotiq_gripper_3_finger_adaptive_control::position_speed_force_request::Request & req,
  robotiq_gripper_3_finger_adaptive_control::position_speed_force_request::Response & res) {
  res.success = (rPRB(req.position_request) && rSPB(req.speed_request) && rFRB(req.force_request));
  return res.success;
}

bool finger_position_speed_force_request_c(robotiq_gripper_3_finger_adaptive_control::position_speed_force_request::Request & req,
  robotiq_gripper_3_finger_adaptive_control::position_speed_force_request::Response & res) {
  res.success = (rPRC(req.position_request) && rSPC(req.speed_request) && rFRC(req.force_request));
  return res.success;
}

bool scissor_position_speed_force_request(robotiq_gripper_3_finger_adaptive_control::position_speed_force_request::Request & req,
  robotiq_gripper_3_finger_adaptive_control::position_speed_force_request::Response & res) {
  res.success = (rPRS(req.position_request) && rSPS(req.speed_request) && rFRS(req.force_request));
  return res.success;
}

};

#endif
