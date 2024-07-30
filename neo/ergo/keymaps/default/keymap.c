/* 
Copyright 2024 NEO

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

enum {
  BASE,
  RAISE,
  LOWER,
  COMMANDS,
  TMUX_PREFIX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_hot(
        MO(RAISE),  KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,   
        MO(COMMANDS), KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  
        KC_TRNS, KC_ESC, LSFT_T(KC_A),    KC_S,    KC_D,   KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   RSFT_T(KC_SCLN), KC_QUOT,          KC_ENT,  
        MO(LOWER),   KC_LSFT, KC_NUBS, LCTL_T(KC_Z),    KC_X,    KC_C,   LALT_T(KC_V),     KC_B,    TMUX_PREFIX,    KC_N,    KC_M,   KC_COMM, KC_DOT, RCTL_T(KC_SLSH), KC_UP,   KC_RSFT, 
        KC_LCTL, MO(LOWER),                  KC_LGUI, KC_SPC,   KC_ENT,  MO(RAISE),                                    KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [RAISE] = LAYOUT_hot(
        KC_TRNS, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, 
        KC_KB_VOLUME_UP, KC_TRNS, KC_BTN3, KC_7, KC_8, KC_9, KC_A, KC_B, KC_EXCLAIM, KC_AT, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_EQUAL, KC_TRNS, KC_TRNS,
        KC_KB_VOLUME_DOWN, KC_TRNS, TMUX_PREFIX, KC_4, KC_5, KC_6, KC_C, KC_D, KC_HASH, KC_DOLLAR, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_CIRC,          KC_TRNS,
        KC_KB_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_E, KC_F, KC_TRNS, KC_MINUS, KC_ASTERISK, KC_AMPERSAND, KC_PERCENT, KC_BSLS, KC_TRNS,
        KC_TRNS, KC_TRNS,                   KC_0, KC_0, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS     
    ),

    [LOWER] = LAYOUT_hot(
        KC_MPRV, KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, 
        KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_MNXT, KC_TRNS, KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_DEL, KC_HOME, KC_END, KC_PGUP, RSFT_T(KC_PAGE_DOWN), KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT, KC_TRNS, KC_PRINT_SCREEN, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS     
    ),

    [COMMANDS] = LAYOUT_hot(
        LALT(KC_F10), KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS     
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t keyTimer;

  switch (keycode) {
    case TMUX_PREFIX:
      /* if (record->event.pressed) { */
      /*   keyTimer = timer_read(); */
      /*   SEND_STRING(SS_DOWN(X_LSFT)); */
      /* } else { */
      /*   SEND_STRING(SS_UP(X_LSFT)); */
      /*   if (keyTimer != 0 && timer_elapsed(keyTimer) < TAPPING_TERM) { */
          SEND_STRING(SS_LCTL("a"));
        /* } */
      /* } */
      break;
    default:
      if (keyTimer != 0)
        keyTimer = 0;
  }
  return true;
}
