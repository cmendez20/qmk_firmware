/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "features/caps_word.h"
#include "muse.h"


enum planck_layers {
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

enum planck_keycodes {
  Base = SAFE_RANGE,
  Nav,
  Mouse,
  Media,
  Num,
  Sym,
  Fun,
  Game,
  Gamefn
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
#define HOME_SCLN RGUI_T(KC_SCLN)

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

/* _BASE 0
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   `  |  Alt |  GUI |LOWER |Space | Bksp |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    KC_Q,       KC_W,      KC_E,                 KC_R,              KC_T,              KC_NO,    KC_NO,    KC_Y,            KC_U,               KC_I,             KC_O,     KC_P,
    HOME_A,     HOME_S,    HOME_D,               HOME_F,            KC_G,              KC_NO,    KC_NO,    KC_H,            HOME_J,             HOME_K,           HOME_L,   HOME_SCLN,
    KC_Z,       KC_X,      KC_C,                 KC_V,              KC_B,              KC_NO,    KC_NO,    KC_N,            KC_M,               KC_COMM,          KC_DOT,   KC_QUOT,
    KC_NO,      KC_SLSH,     LT(_MEDIA, KC_ESC),    LT(_NAV, KC_SPC),   LT(_MOUSE, KC_TAB), KC_NO,    KC_NO,    LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC),   LT(_FUN, KC_DEL),  KC_NO,    TG(_GAME)
),

/* _NAV 1
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    RESET,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,       KC_NO,     	KC_INS,           KC_HOME,          KC_PGDN,          KC_PGUP,    KC_END,
    KC_LGUI,     KC_LALT,     KC_LSFT,     KC_LCTL,     KC_NO,        KC_NO,       KC_NO,       KC_CAPS,          KC_LEFT,          KC_DOWN,          KC_UP,      KC_RGHT,
    KC_NO,       LCTL(KC_X),       LCTL(KC_C),       LCTL(KC_V),       KC_NO,        KC_NO,       KC_NO,       KC_AGIN,          LCTL(KC_V),          LCTL(KC_C),          LCTL(KC_X),     KC_UNDO,
    KC_NO,       KC_NO,       KC_NO,       KC_TRNS,     KC_NO,        KC_NO,       KC_NO,       LT(_SYM, KC_ENT),  LT(_NUM, KC_BSPC), LT(_FUN, KC_DEL),  KC_NO,      KC_NO
),

/* _MOUSE 2
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
    RESET,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,       KC_NO,     	KC_AGIN,          KC_WBAK,          KC_COPY,          KC_PSTE,    KC_WFWD,
    KC_LGUI,     KC_LALT,     KC_LSFT,     KC_LCTL,     KC_NO,        KC_NO,       KC_NO,       KC_NO,            KC_MS_L,          KC_MS_D,          KC_MS_U,    KC_MS_R,
    KC_NO,       KC_NO,       KC_WBAK,     KC_WFWD,     KC_NO,        KC_NO,       KC_NO,       KC_NO,            KC_WH_L,          KC_WH_D,          KC_WH_U,    KC_WH_R,
    KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_TRNS,      KC_NO,       KC_NO,       KC_BTN2,          KC_BTN1,          KC_BTN3,          KC_NO,      KC_NO
),

/* _MEDIA 3
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_MEDIA] = LAYOUT_planck_grid(
    RESET,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,        KC_NO,
    KC_LGUI,     KC_LALT,     KC_LSFT,     KC_LCTL,     KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_MPRV,     KC_VOLD,      KC_VOLU,      KC_MNXT,
    KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,        KC_NO,
    KC_NO,       KC_NO,       KC_TRNS,     KC_NO,       KC_NO,        KC_NO,       KC_NO,       KC_MSTP,     KC_MPLY,     KC_MUTE,      KC_NO,        KC_NO
),

/* _NUM 4
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    KC_LBRC,       KC_7,       KC_8,       KC_9,       KC_RBRC,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,       KC_NO,     RESET,
    KC_SLASH,       KC_4,       KC_5,       KC_6,       KC_EQL,        KC_NO,       KC_NO,       KC_NO,       KC_RCTL,      KC_RSFT,     KC_LALT,   KC_RGUI,
    KC_GRV,        KC_1,       KC_2,       KC_3,       KC_BSLS,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,       KC_NO,     KC_NO,
    KC_NO,         KC_NO,      KC_DOT,     KC_0,       KC_MINS,       KC_NO,       KC_NO,       KC_NO,       KC_TRNS,      KC_NO,       KC_NO,     KC_NO
),

/* _SYM 5
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_planck_grid(
    KC_LCBR,   KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,  KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,       KC_NO,       RESET,
    KC_QUES,   KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,  KC_NO,       KC_NO,       KC_NO,       KC_RCTL,      KC_RSFT,     KC_LALT,     KC_RGUI,
    KC_TILD,   KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,  KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,       KC_NO,       KC_NO,
    KC_COLN,   KC_SLSH,   KC_LPRN, KC_RPRN, KC_UNDS,  KC_NO,       KC_NO,       KC_TRNS,     KC_NO,        KC_NO,       KC_NO,       KC_NO
),

/* _FUN 6
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUN] = LAYOUT_planck_grid(
    KC_F12,    KC_F7,     KC_F8,  KC_F9,  KC_SLEP,   KC_5,  KC_NO, KC_NO,  KC_NO,     KC_NO,    KC_NO,     RESET,
    KC_F11,    KC_F4,    KC_F5, KC_F6, KC_WFWD,   KC_NO, KC_NO, KC_NO,  KC_RCTL,   KC_RSFT,  KC_LALT,   KC_RGUI,
    KC_F10,    KC_F1,    KC_F2, KC_F3, KC_WBAK,   KC_NO, KC_NO, KC_NO,  KC_NO,     KC_NO,    KC_NO,     KC_NO,
    KC_NO,     KC_NO,    KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO,  KC_NO,     KC_TRNS,  KC_NO,     KC_NO
),

/* _GAME 7
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R,  KC_T,   KC_Y,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPLY,
    KC_LCTL,    KC_A, KC_S, KC_D, KC_F,  KC_G,   KC_NO,  KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V,  KC_B,   KC_M,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,  KC_NO, KC_NO, KC_LALT, KC_SPC, MO(_GAMEFN), KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(_BASE)
),

/* _GAMEFN 8
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMEFN] = LAYOUT_planck_grid(
    KC_NO,  KC_1,  KC_NO,  KC_3,  KC_4,    KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_2,    KC_NO, KC_NO, KC_NO, KC_4,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_TRNS, KC_5, KC_6, KC_7, KC_8,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_ESC,  KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC
)

};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_caps_word(keycode, record)) { return false; }
  // Your macros ...

  return true;
}

void matrix_scan_user(void) {
  caps_word_task();
  // Other tasks...
}