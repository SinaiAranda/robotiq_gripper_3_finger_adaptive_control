#ifndef LEFT_ROBOTIQ_GRIPPER_3_FINGER_ADAPTIVE_MOTOMAN_IO
#define LEFT_ROBOTIQ_GRIPPER_3_FINGER_ADAPTIVE_MOTOMAN_IO

typedef enum {
  gripper_status_motoman = 10050,

    gripper_mode_motoman_b0 = 10051,
    gripper_mode_motoman_b1 = 10052,

    go_to_motoman = 10053,

    automatic_release_motoman = 10054,

    individual_control_fingers_mode_motoman = 10062,

    individual_control_scissor_motoman = 10063,

    position_request_a_motoman = 10080,
    speed_request_a_motoman = 10090,
    force_request_a_motoman = 10100,

    position_request_b_motoman = 10110,
    speed_request_b_motoman = 10120,
    force_request_b_motoman = 10130,

    position_request_c_motoman = 10140,
    speed_request_c_motoman = 10150,
    force_request_c_motoman = 10160,

    position_request_scissor_motoman = 10170,
    speed_request_scissor_motoman = 10180,
    force_request_scissor_motoman = 10190,

}
WriteValvues;

#endif
