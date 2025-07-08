/*
Adapated from manna harbour miryoku layout
Using 34 keys instead of 36
Combos on thumbs activates the 3rd missing thumb key layers
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
  _Colmak
};

enum custom_keycodes {
  Email = SAFE_RANGE,
  Pswd,
  Ema,
  Andr
};

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_QUO RCTL_T(KC_QUOT)

#ifdef COMBO_ENABLE // Good practice to wrap combo code

// Define names for your combos
enum combos {
  CMB_MOUSE, // Combo to activate Media layer
  CMB_FUN,   // Combo to activate Fun layer
  CMB_ESC
};

// uint16_t COMBO_LEN = COMBO_COUNT; // Use if COMBO_COUNT isn't the last item

// Define the key sequences that trigger the combos
// IMPORTANT: Use the *tap* keycode of your Mod-Tap/Layer-Tap thumb keys

// Left Thumb Keys: LT(_Nav, KC_SPC) and LT(_Media, KC_TAB) -> Tap codes are KC_SPC, KC_TAB
const uint16_t PROGMEM mouse_combo_keys[] = { LT(_Nav, KC_SPC), LT(_Media, KC_TAB), COMBO_END };

// Right Thumb Keys: LT(_Sym, KC_ENT) and LT(_Num, KC_BSPC) -> Tap codes are KC_ENT, KC_BSPC
const uint16_t PROGMEM fun_combo_keys[] = { LT(_Num, KC_BSPC), LT(_Sym, KC_ENT), COMBO_END };

// const uint16_t PROGMEM esc_combo_keys[] = { HOME_D,  HOME_F, COMBO_END };
const uint16_t PROGMEM esc_combo_keys[] = { KC_Q,  KC_W, COMBO_END };

// Define the combo array mapping sequences to actions
combo_t key_combos[] = {
    // When KC_SPC and KC_TAB are pressed together, toggle the _Mouse layer
    // [CMB_MOUSE] = COMBO(mouse_combo_keys, TG(_Mouse)), // <-- Target layer changed to _Mouse
    [CMB_MOUSE] = COMBO(mouse_combo_keys, TG(_Mouse)), // <-- Target layer changed to _Mouse

    // When KC_ENT and KC_BSPC are pressed together, toggle the _Fun layer
    // [CMB_FUN] = COMBO(fun_combo_keys, TG(_Fun)) // <-- Target layer is _Fun (as requested)
    [CMB_FUN] = COMBO(fun_combo_keys, OSL(_Fun)), // <-- Target layer is _Fun (as requested)

    [CMB_ESC] = COMBO(esc_combo_keys, KC_ESC) // <-- Target layer is _Fun (as requested)
};

#endif // COMBO_ENABLE

// Tap Dance declarations
enum {
    TD_Z_ESC, // Tap once for Q, twice for ESC
    TD_P_DEL  // Tap once for P, twice for DEL
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_P_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_DEL)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_Base] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K, HOME_L, HOME_QUO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,                           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLASH,  KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
              KC_ESC,   LT(_Nav, KC_SPC),       LT(_Media, KC_TAB),            LT(_Sym, KC_ENT),   LT(_Num, KC_BSPC),  LT(_Fun, KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),

    [_Nav] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, KC_NO,   KC_NO,  OSM(MOD_HYPR), KC_NO, KC_NO,               LCTL(KC_PGUP), KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_LCTL, KC_LALT, KC_LCMD, KC_LSFT,  KC_NO,                  LCTL(KC_PGDN), KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_NO,  LCMD(KC_X), LCMD(KC_C), LCMD(KC_V),   KC_NO,                KC_NO,   KC_DEL,   KC_NO,   KC_NO,  KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
               LT(_Media, KC_TAB),   KC_TRNS,   LT(_Mouse, KC_LSFT),   LT(_Sym, KC_ENT),   MO(_Fun),  LT(_Fun, KC_DEL)
                                      //`--------------------------'  `--------------------------'
  ),

  [_Mouse] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,  KC_WBAK, KC_UNDO, KC_AGIN, KC_WFWD,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_LCTL, KC_LALT, KC_LCMD, KC_LSFT,  KC_NO,                         KC_NO,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_WBAK, KC_WFWD,  KC_NO,  KC_NO,                         KC_NO,  KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_NO,   TO(_Base),  KC_TRNS,   KC_BTN2,  KC_BTN1,  KC_BTN3
                                      //`--------------------------'  `--------------------------'
  ),

  [_Media] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_LCTL, KC_LALT, KC_LCMD, KC_LSFT,  KC_NO,                         KC_MSTP,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                         KC_NO,   KC_MUTE,  KC_NO,   KC_NO,   KC_NO,  TO(_Colmak),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,  KC_NO,    KC_NO,   TG(_Mouse),  KC_MPLY,  KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

    [_Num] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,  KC_LBRC,   KC_7,    KC_8,    KC_9,  KC_RBRC,                        Andr,   Ema,    Email,    Pswd,   KC_NO,   QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_SCLN,  KC_4,    KC_5,    KC_6,   KC_EQL,                        KC_NO,  KC_RSFT, KC_RCMD, KC_LALT, KC_RCTL,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_GRV,   KC_1,    KC_2,    KC_3,  KC_BSLS,                         KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_DOT,   KC_0,   KC_MINS,   KC_NO,    KC_TRNS,  KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

    [_Sym] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,  KC_LCBR,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_COLN,  KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                        KC_NO,  KC_RSFT, KC_RCMD, KC_LALT, KC_RCTL,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_NO,  KC_TILD, KC_EXLM, KC_AT,  KC_HASH, KC_PIPE,                         KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LPRN, KC_RPRN, KC_UNDS,   KC_TRNS,  KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

    [_Fun] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_F12,  KC_F7,   KC_F8,   KC_F9,  KC_SLEP,                        Andr,    Ema,    Email,   Pswd,   KC_NO,   QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_F11,   KC_F4,   KC_F5,  KC_F6,   KC_NO,                        KC_NO,  KC_RSFT, KC_RCMD, KC_LALT, KC_RCTL,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,   KC_F10,   KC_F1,  KC_F2,   KC_F3,   KC_NO,                         RM_TOGG,   BL_TOGG,  BL_STEP,   BL_OFF,   TG(_Colmak),   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [_Colmak] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,    KC_Q,    KC_W,    KC_F,    KC_P,   KC_B,                          KC_J,    KC_L,    KC_U,    KC_Y,  KC_QUOT,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,    KC_A,    KC_R,    KC_S,    KC_T,   KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,    KC_Z,    KC_X,    KC_C,    KC_D,   KC_V,                          KC_K,    KC_H,   KC_COMM, KC_DOT, KC_SLASH,  TO(_Base),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            LT(_Media, KC_ESC),   LT(_Nav, KC_SPC),   LT(_Mouse, KC_TAB),   LT(_Sym, KC_ENT),   LT(_Num, KC_BSPC),  LT(_Fun, KC_DEL)
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_caps_word(keycode, record)) { return false; }

  // #ifdef COMBO_ENABLE
  //     if (!process_combo_event(keycode, record)) { // Process combos first
  //         return false;
  //     }
  // #endif

  // Your macros ...
  switch(keycode) {
      case Email:
        if (record->event.pressed) {
            SEND_STRING("mendecj812@gmail.com");
        }
        return false;

      case Pswd:
        if (record->event.pressed) {
            SEND_STRING("ZMalqwop$7");
        }
        return false;

      case Andr:
        if (record->event.pressed) {
            SEND_STRING("k2U3n2FDQvlGUOtyqdHe3d");
        }
        return false;

      case Ema:
        if (record->event.pressed) {
            SEND_STRING("emA1l4T3sT1ng");
        }
        return false;
  }

  return true;
}

void matrix_scan_user(void) {
  caps_word_task();
  // #ifdef COMBO_ENABLE
  //     combo_task(); // Important for combos to work reliably
  // #endif
  // Other tasks...
}
