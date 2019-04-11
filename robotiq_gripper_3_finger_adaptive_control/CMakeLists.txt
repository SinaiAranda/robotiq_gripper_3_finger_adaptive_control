cmake_minimum_required(VERSION 2.8.3)
project(robotiq_gripper_3_finger_adaptive_control)

find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs tf motoman_msgs   message_generation)

find_package(Boost REQUIRED COMPONENTS system)

add_compile_options(-std=c++11)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

add_service_files(
  FILES

  output/action_request.srv
  output/gripper_option_1.srv
  output/position_speed_force_request.srv

  input/position_speed_force.srv
  input/gripper_status.srv
)

generate_messages(DEPENDENCIES std_msgs)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS
  LIBRARIES 
  DEPENDS Boost
)

## Declare a cpp executable
add_executable(left_robotiq_gripper_3_finger_adaptive_state src/left_robotiq_gripper_3_finger_adaptive_state.cpp)
target_link_libraries(left_robotiq_gripper_3_finger_adaptive_state ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(left_robotiq_gripper_3_finger_adaptive_state left_robotiq_gripper_3_finger_adaptive_state_gencpp)

add_executable(right_robotiq_gripper_3_finger_adaptive_state src/right_robotiq_gripper_3_finger_adaptive_state.cpp)
target_link_libraries(right_robotiq_gripper_3_finger_adaptive_state ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(right_robotiq_gripper_3_finger_adaptive_state right_robotiq_gripper_3_finger_adaptive_state_gencpp)

add_executable(init_grippers src/init_grippers.cpp)
target_link_libraries(init_grippers ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(init_grippers init_grippers_gencpp)

## Mark executables and libraries for installation
#install(TARGETS robotiq_gripper_3_finger_adaptive_control
#  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

