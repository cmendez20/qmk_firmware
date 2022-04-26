/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "features/caps_word.h"
#include <stdio.h>

enum custom_layers {
  _Base,
  _Nav,
  _Mouse,
  _Media,
  _Num,
  _Sym,
  _Fun,
  _Game,
  _Gamefn
};

enum custom_keycodes {
  Base = SAFE_RANGE,
  Nav,
  Mouse,
  Media,
  Num,
  Sym,
  Fun,
  Game,
  Gamefn,
  Email
};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCN RGUI_T(KC_SCLN)

#define _BASE 0
#define _NAV 1
#define _MOUSE 2
#define _MEDIA 3
#define _NUM 4
#define _SYM 5
#define _FUN 6
#define _GAME 7
#define _GAMEFN 8

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K, HOME_L, HOME_SCN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_QUOT, TG(_GAME),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
       LT(_MEDIA, KC_ESC),   LT(_NAV, KC_SPC),   LT(_MOUSE, KC_TAB),   LT(_SYM, KC_ENT),   LT(_NUM, KC_BSPC),  LT(_FUN, KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       RESET,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                  LCTL(KC_PGUP), KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_CAPS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,  KC_NO,                  LCTL(KC_PGDN), KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_NO,  LCTL(KC_X), LCTL(KC_C), LCTL(KC_V),   KC_NO,                KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
               LT(_MEDIA, KC_TAB),   KC_TRNS,   LT(_MOUSE, KC_LSFT),   LT(_SYM, KC_ENT),   LT(_NUM, KC_BSPC),  LT(_FUN, KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,  KC_WBAK, KC_UNDO, KC_AGIN, KC_WFWD, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,  KC_NO,                         KC_NO,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_WBAK, KC_WFWD,  KC_NO,  KC_NO,                         KC_NO,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO,   KC_NO,  KC_TRNS,   KC_BTN2,  KC_BTN1,  KC_BTN3
                                      //`--------------------------'  `--------------------------'
  ),

  [_MEDIA] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,  KC_NO,                         KC_NO,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,  KC_NO,    KC_NO,   KC_MSTP,  KC_MPLY,  KC_MUTE
                                      //`--------------------------'  `--------------------------'
  ),

    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,  KC_LBRC,   KC_7,    KC_8,    KC_9,  KC_RBRC,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_SLASH,  KC_4,    KC_5,    KC_6,   KC_EQL,                        KC_NO,  KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_GRV,   KC_1,    KC_2,    KC_3,  KC_BSLS,                         KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_DOT,   KC_0,   KC_MINS,   KC_NO,    KC_TRNS,  KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,  KC_LCBR,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_BSLS, KC_QUES,  KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                        KC_NO,  KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_NO,  KC_TILD, KC_EXLM, KC_AT,  KC_HASH, KC_PIPE,                         KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LPRN, KC_RPRN, KC_UNDS,   KC_TRNS,  KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

    [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_F12,  KC_F7,   KC_F8,   KC_F9,  KC_SLEP,                        KC_NO,   KC_NO,   Email,   KC_NO,   KC_NO,   RESET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_F11,   KC_F4,   KC_F5,  KC_F6,   KC_NO,                        KC_NO,  KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_F10,   KC_F1,  KC_F2,   KC_F3,   KC_NO,                         KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [_GAME] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,   KC_Q,    KC_W,   KC_E,    KC_R,     KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   RESET,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_NO,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,   KC_NO,   KC_NO,   KC_NO,  TO(_BASE),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                     KC_LALT,  KC_SPC,  MO(_GAMEFN),    KC_NO,   KC_NO,  TO(_BASE)
                                      //`--------------------------'  `--------------------------'
  ),

    [_GAMEFN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,   KC_1,   KC_NO,   KC_3,    KC_4,     KC_M,                         KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_2,    KC_NO,  KC_NO,   KC_NO,    KC_4,   KC_Y,                         KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,   KC_NO,   KC_Y,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO,   KC_NO,  KC_TRNS,    KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_caps_word(keycode, record)) { return false; }
  // Your macros ...
  switch(keycode) {
      case Email: // types my email address
      if (record->event.pressed) {
          SEND_STRING("mendecj812@gmail.com");
      }
      return false;
  }

  return true;
}

void matrix_scan_user(void) {
  caps_word_task();
  // Other tasks...
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM my_logo[] = {
 // 'anime', 128x32px
// 'unnamed_02', 128x32px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0xc0, 0x20, 0x20, 0x20, 0x90, 0x98, 0x98, 0x90, 0x80, 0x24, 0x24, 0x80, 0x00, 0x00, 
0x9c, 0x9c, 0x84, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0xe0, 0xe0, 0xe0, 0x38, 0x38, 0x98, 0x98, 0x98, 
0xe0, 0xe0, 0xe4, 0xe0, 0xe0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x20, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0xe4, 0x84, 0x9c, 
0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x20, 0x20, 0xd8, 0x24, 0x24, 0x9b, 0x98, 0x98, 
0xe4, 0xe4, 0xe7, 0xfb, 0xfb, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x83, 0xfc, 0xfc, 0xfc, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0xdc, 0x9c, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 
0x3f, 0x3f, 0x07, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x30, 0x20, 0x20, 
0x20, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0x98, 0xf8, 0x20, 0x23, 
0x07, 0x07, 0x1f, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
0x00, 0x00, 0x00, 0x13, 0x1b, 0x24, 0x61, 0xe3, 0xe3, 0xe1, 0xe4, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 
0x9f, 0x9f, 0xdf, 0x9f, 0x9f, 0x9f, 0x1f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xe7, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 
0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xff, 0x27, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x78, 0x78, 0x63, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f, 
0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x3f, 0x3f, 0x1f, 0x1f, 0x1f, 0x1c, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x78, 0x7c, 0x7c, 0x7f, 0x7f, 0x7f, 
0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 
0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x5f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f, 0x7f, 0x7f, 0x7f};
    oled_write_raw_P(my_logo, sizeof(my_logo));
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
    // if (!process_caps_word(keycode, record)) { return false; }
  }
  return true;
}

#endif // OLED_ENABLE
