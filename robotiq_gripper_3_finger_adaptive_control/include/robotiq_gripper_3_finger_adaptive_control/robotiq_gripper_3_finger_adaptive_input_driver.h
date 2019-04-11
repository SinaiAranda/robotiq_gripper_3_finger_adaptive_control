#ifndef ROBOTIQ_GRIPPER_3_FINGER_ADAPTIVE_INPUT_DRIVER
#define ROBOTIQ_GRIPPER_3_FINGER_ADAPTIVE_INTPUT_DRIVER

#include <robotiq_gripper_3_finger_adaptive_control/robotiq_gripper_3_finger_adaptive_motoman_io.h>
#include "robotiq_gripper_3_finger_adaptive_control/gripper_status.h"
#include "robotiq_gripper_3_finger_adaptive_control/position_speed_force.h"

int gIMC() {
    int finger_b_position = ReadByte(120);
  return finger_b_position;
}

int gMOD() {
    int finger_c_position = ReadByte(120);
  return finger_c_position;
}

int gPOA() {
    int finger_a_position = ReadByte(120);
  return finger_a_position;
}

int gPOB() {
    int finger_b_position = ReadByte(120);
  return finger_b_position;
}

int gPOC() {
    int finger_c_position = ReadByte(120);
  return finger_c_position;
}

bool finger_a_position(robotiq_gripper_3_finger_adaptive_control::position_speed_force::Request & req,
  robotiq_gripper_3_finger_adaptive_control::position_speed_force::Response & res) {
  res.position = gPOA();
  return true;
}

bool finger_b_position(robotiq_gripper_3_finger_adaptive_control::position_speed_force::Request & req,
  robotiq_gripper_3_finger_adaptive_control::position_speed_force::Response & res) {
  res.position = gPOB();
  return true;
}

bool finger_c_position(robotiq_gripper_3_finger_adaptive_control::position_speed_force::Request & req,
  robotiq_gripper_3_finger_adaptive_control::position_speed_force::Response & res) {
  res.position = gPOC();
  return true;
}

#endif
