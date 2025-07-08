/*
// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
*/

#pragma once

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// default but used in macros
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#define CAPS_WORD_IDLE_TIMEOUT 4000  // Turn off Caps Word after 4 seconds.

// mouse
// --- Optimized Mouse Key Settings for 27" 4K @ 60Hz on macOS ---

// How long to wait before starting mouse movement (ms)
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          5     // Keep: Good responsiveness.

// How often to update mouse movement (ms)
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16    // Keep: Aligns well with 60Hz (62.5 updates/sec).

// Smallest unit of cursor movement.
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA     1     // Keep: Essential for 4K precision.

// Pixels to move before acceleration.
#undef MOUSEKEY_INITIAL_SPEED
#define MOUSEKEY_INITIAL_SPEED  1     // Keep: Good for fine initial control.

// Pixels to move at maximum speed.
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      30   // Increase: For faster 4K traversal (was 22).
                                      // (40 units * 62.5 updates/sec = 2500 units/sec)
                                      // Approx. 1.5 seconds to cross 3840px.

// Time to reach maximum speed (in units of MOUSEKEY_INTERVAL).
// This is the standard QMK way to control acceleration.
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX   35    // Introduce: Provides a smooth acceleration ramp.
                                      // (25 intervals * 16ms/interval = 400ms to reach max speed)

// --- Wheel Settings ---

// How often to update wheel movement (ms)
#undef MOUSEKEY_WHEEL_INTERVALk
#define MOUSEKEY_WHEEL_INTERVAL 45    // Decrease: For smoother, faster scrolling (was 83).
                                      // (50 updates/sec)

// Lines to scroll at maximum speed.
#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 2    // Increase: For faster scrolling (was 3).

// Time to reach maximum wheel speed (in units of MOUSEKEY_WHEEL_INTERVAL).
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 45 // Introduce: Smooth wheel acceleration.
                                      // (15 intervals * 20ms/interval = 300ms to reach max wheel speed)

// Note: MOUSEKEY_DECELERATED_SPEED is not a standard QMK mousekey setting
// and has been effectively replaced by using MOUSEKEY_TIME_TO_MAX.

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#define COMBO_COUNT 3
#define EXTRA_SHORT_COMBOS
