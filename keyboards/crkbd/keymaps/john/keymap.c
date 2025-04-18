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

#define TAPSPC LT(1,KC_SPC)
#define TAPENT LT(2,KC_ENT)
#define TAPPING_TERM_PER_KEY

enum {
  TD_SHFT_CUSTOM
};

enum {
  BASE_LAYER,
  FN_AND_NUMBER,
  SYMBOLS,
  MEDIA
}

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_SHFT_CUSTOM] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

layer_state_t layer_state_set_user(layer_state_t state){
    return update_tri_layer_state (state,1,2,3);
}
// 123 = !@#
// 456 = $%ˆ ¡™£¢∞§¶•ªªªªªº‘“«©≠–`œœœœå
// 7890 = &*()
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_LAYER] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     CTL_T(KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  LCAG(KC_LEFT),LCAG(KC_RIGHT),                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_QUOT,  
  // |--------+--------+--------+--------+--------+--------|    KC_A,KC_A,                 |--------+--------+--------+--------+--------+--------|  
LGUI_T(KC_ESC),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      LCA(KC_LEFT),LCA(KC_RIGHT),                    KC_H,    KC_J,    KC_K,    KC_L,  KC_SCLN,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  TD(TD_SHFT_CUSTOM),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                       KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH,  KC_ESC,

  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      KC_LCTL,   KC_LALT,  TAPSPC,     TAPENT,   KC_LSFT, KC_A/*<-tbd this keycodes*/
                                      //`--------------------------'  `--------------------------'

  ),

    [FN_AND_NUMBER] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TRNS, KC_F1,  KC_F2,  KC_F3,  KC_F4,    KC_TRNS,     KC_TRNS,KC_TRNS,                  KC_MINS, KC_1,    KC_2,     KC_3,   KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_F5,  KC_F6,  KC_F7,  KC_F8,    KC_TRNS,     LCA(KC_UP),LCA(KC_DOWN),                  KC_EQL, KC_4,    KC_5,     KC_6,   KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS,  KC_F9,  KC_F10, KC_F11, KC_F12,   KC_TRNS,                      KC_0,    KC_7,    KC_8,     KC_9,   KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS,KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),
  [SYMBOLS] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TRNS, KC_TRNS,  KC_GRAVE, KC_MINS, KC_EQL, KC_TRNS,     KC_TRNS,KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_GRAVE,KC_TRNS,KC_RBRC, KC_LBRC, KC_EQL,  KC_BSLS, ,   KC_TRNS,LCA(KC_ENT),                    KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT, KC_TRNS,KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    [MEDIA] = LAYOUT_split_3x6_3_ex2(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_STOP, KC_MPLY, MS_WHLU, MS_WHLD, KC_TRNS,     KC_TRNS,KC_TRNS,                  KC_TRNS, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS, KC_TRNS,  KC_TRNS,     KC_TRNS,KC_TRNS, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  )
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case CTL_T(KC_TAB):
        case LGUI_T(KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}