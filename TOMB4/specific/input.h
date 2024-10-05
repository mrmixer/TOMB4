#pragma once
#include "../global/types.h"

long Key(long number);
long S_UpdateInput();
long ReadJoystick(long& x, long& y);

extern const char* KeyboardButtons[272];
extern const char* GermanKeyboard[272];
extern short layout[2][18];

extern long conflict[18];
extern long input;
extern long linput;
extern long dbinput;
extern long inputBusy;
extern short ammo_change_timer;
extern char ammo_change_buf[12];

#include <stdint.h>
#include <xinput.h>

typedef enum gamepad_key_flag_t {
    gamepad_key_flag_none,
    gamepad_key_flag_pressed = 0x1 << 0,
    gamepad_key_flag_just_pressed = 0x1 << 1,
    gamepad_key_flag_just_released = 0x1 << 2,
} gamepad_key_flag_t;

typedef enum gamepad_button_t {
    gamepad_button_menu, /* Start, on the right */
    gamepad_button_view, /* Select, on the left */
    gamepad_button_a,
    gamepad_button_cross = gamepad_button_a,
    gamepad_button_b,
    gamepad_button_circle = gamepad_button_b,
    gamepad_button_x,
    gamepad_button_square = gamepad_button_x,
    gamepad_button_y,
    gamepad_button_triangle = gamepad_button_y,
    gamepad_button_dpad_up,
    gamepad_button_dpad_down,
    gamepad_button_dpad_left,
    gamepad_button_dpad_right,
    gamepad_button_left_shoulder,
    gamepad_button_l1 = gamepad_button_left_shoulder,
    gamepad_button_right_shoulder,
    gamepad_button_r1 = gamepad_button_right_shoulder,
    gamepad_button_left_thumbstick,
    gamepad_button_l3 = gamepad_button_left_thumbstick,
    gamepad_button_right_thumbstick,
    gamepad_button_r3 = gamepad_button_right_thumbstick,
    gamepad_button_count
} gamepad_button_t;

typedef struct gamepad_t {
    union {
        float left_trigger;
        float l2;
    };
    union {
        float right_trigger;
        float r2;
    };
    float left_thumbstick_x;
    float left_thumbstick_y;
    float right_thumbstick_x;
    float right_thumbstick_y;
    uint8_t buttons[gamepad_button_count];
} gamepad_t;
