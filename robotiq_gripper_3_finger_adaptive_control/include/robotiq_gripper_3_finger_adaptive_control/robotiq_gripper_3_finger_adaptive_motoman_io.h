#ifndef ROBOTIQ_GRIPPER_3_FINGER_ADAPTIVE_MOTOMAN_IO
#define ROBOTIQ_GRIPPER_3_FINGER_ADAPTIVE_MOTOMAN_IO

#include "motoman_msgs/WriteSingleIO.h"
#include "motoman_msgs/ReadSingleIO.h"

bool WriteValvue(int address, int value, std::string action) {
  ros::NodeHandle nh;
  ros::ServiceClient write_io = nh.serviceClient < motoman_msgs::WriteSingleIO > ("write_single_io");

  motoman_msgs::WriteSingleIO::Request write_req;
  motoman_msgs::WriteSingleIO::Response write_res;

  write_req.address = address;
  write_req.value = value;
  bool success = write_io.call(write_req, write_res);

  if (success) {
    ROS_INFO_STREAM("Write to " + action);
  } else {
    ROS_ERROR_STREAM("Failed to " + action);
  }
  return success;
}

int ReadValvue(int address) {
  ros::NodeHandle nh;
  ros::ServiceClient read_io = nh.serviceClient < motoman_msgs::ReadSingleIO > ("read_single_io");

  motoman_msgs::ReadSingleIO::Request read_req;
  motoman_msgs::ReadSingleIO::Response read_res;

  read_req.address = address;
  bool success = read_io.call(read_req, read_res);

  if (success) {
    ROS_INFO_STREAM("Read: " << read_res.value);
  } else {
    ROS_ERROR_STREAM("Failed to Read");
  }
  return read_res.value;
}

bool WriteByte(int address, int binary, std::string action) {
  std::string binary_str = std::bitset < 8 > (binary).to_string();
  std::reverse(binary_str.begin(), binary_str.end());

  int bit;
  bool success;

  for (int i = 0; i <= 7; i++) {
    bit = std::stoi(std::string(1, binary_str[i]));
    success = WriteValvue(address + i, bit, action);
    if (success == false) {
      return success;
    }
  }
  return success;
}

int ReadByte(int address) {
  int bit;
  int byte = 0;
  for (int i = 0; i <= 7; i++) {
    bit = ReadValvue(address + i);
    if (bit > 0) {
      (i == 0) ? byte = 1: (i == 1) ? byte = byte + 2 : (i == 2) ? byte = byte + 4 : (i == 3) ? byte = byte + 8 : (i == 4) ? byte = byte + 16 : (i == 5) ? byte = byte + 32 : (i == 6) ? byte = byte + 64 : byte = byte + 128;
    }
  }
  return byte;
}
#endif
