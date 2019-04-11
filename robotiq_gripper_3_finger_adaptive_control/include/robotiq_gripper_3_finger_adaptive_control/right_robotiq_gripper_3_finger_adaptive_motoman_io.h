#ifndef RIGHT_ROBOTIQ_GRIPPER_3_FINGER_ADAPTIVE_MOTOMAN_IO
#define RIGHT_ROBOTIQ_GRIPPER_3_FINGER_ADAPTIVE_MOTOMAN_IO

typedef enum {
  gripper_status_motoman = 10250,

    gripper_mode_motoman_b0 = 10251,
    gripper_mode_motoman_b1 = 10252,

    go_to_motoman = 10253,

    automatic_release_motoman = 10254,

    individual_control_fingers_mode_motoman = 10262,

    individual_control_scissor_motoman = 10263,

    position_request_a_motoman = 10280,
    speed_request_a_motoman = 10290,
    force_request_a_motoman = 10300,

    position_request_b_motoman = 10310,
    speed_request_b_motoman = 10320,
    force_request_b_motoman = 10330,

    position_request_c_motoman = 10340,
    speed_request_c_motoman = 10350,
    force_request_c_motoman = 10360,

    position_request_scissor_motoman = 10370,
    speed_request_scissor_motoman = 10380,
    force_request_scissor_motoman = 10390,

}
WriteValvues;

#endif
