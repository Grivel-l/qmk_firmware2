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

#define RGB_REPEAT_INTERVAL 80

enum layers {
  DEFAULT,
  BASIC,
  RAISE,
  LOWER,
  COMMANDS
};

enum custom_keycodes {
  TMUX_PREFIX = SAFE_RANGE,
  CUSTOM_COPY,
  CUSTOM_PASTE
};

enum combo_events {
  CMB_CTRL
};

const rgblight_segment_t PROGMEM white[] = RGBLIGHT_LAYER_SEGMENTS({5, 11, HSV_WHITE});
const rgblight_segment_t PROGMEM pink[] = RGBLIGHT_LAYER_SEGMENTS({5, 11, HSV_TEAL});
const rgblight_segment_t PROGMEM rgbLower[] = RGBLIGHT_LAYER_SEGMENTS({5, 11, HSV_TURQUOISE});
const rgblight_segment_t PROGMEM rgbRaise[] = RGBLIGHT_LAYER_SEGMENTS({5, 11, HSV_SPRINGGREEN});
const rgblight_segment_t PROGMEM rgbCommands[] = RGBLIGHT_LAYER_SEGMENTS({5, 11, HSV_CORAL});
const rgblight_segment_t* const PROGMEM rgbLayers[] = RGBLIGHT_LAYERS_LIST(white, pink, rgbLower, rgbRaise, rgbCommands);

const uint16_t PROGMEM ctrlCombo[] = { LCTL_T(KC_Z), KC_LGUI, COMBO_END };
combo_t key_combos[] = {
  [CMB_CTRL] = COMBO_ACTION(ctrlCombo)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [DEFAULT] = LAYOUT_hot(
        MO(RAISE),  KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,   
        MO(COMMANDS), KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  
        KC_TRNS, KC_ESC, LSFT_T(KC_A),    KC_S,    KC_D,   KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   RSFT_T(KC_SCLN), KC_QUOT,          KC_ENT,  
        MO(LOWER),   TMUX_PREFIX, KC_NUBS, LCTL_T(KC_Z),    KC_X,    KC_C,   LALT_T(KC_V),     KC_B,    QK_REPEAT_KEY,    KC_N,    KC_M,   KC_COMM, KC_DOT, RCTL_T(KC_SLSH), KC_UP,   MO(COMMANDS), 
        KC_LCTL, MO(LOWER),                  KC_LGUI, KC_SPC,   MO(RAISE),  TMUX_PREFIX,                                    KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [RAISE] = LAYOUT_hot(
        KC_TRNS, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
        KC_MPRV, CUSTOM_COPY, KC_BTN3, KC_7, KC_8, KC_9, KC_A, KC_B, KC_EXCLAIM, KC_AT, KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_EQUAL, KC_TRNS, KC_TRNS,
        KC_MPLY, CUSTOM_PASTE, TMUX_PREFIX, KC_4, KC_5, KC_6, KC_C, KC_D, KC_HASH, KC_DOLLAR, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_CIRC,          KC_TRNS,
        KC_MNXT, KC_TRNS, KC_TRNS, KC_X, KC_1, KC_2, KC_3, KC_E, KC_F, KC_TRNS, KC_MINUS, KC_ASTERISK, KC_AMPERSAND, KC_PERCENT, KC_BSLS, KC_TRNS,
        KC_TRNS, KC_TRNS,                   KC_TRNS, KC_0, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [LOWER] = LAYOUT_hot(
        KC_AUDIO_VOL_UP, KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
        KC_AUDIO_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_AUDIO_VOL_DOWN, KC_TRNS, KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT, KC_DEL, KC_HOME, KC_END, KC_PGUP, KC_PGDN, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LALT, KC_TRNS, KC_PRINT_SCREEN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [COMMANDS] = LAYOUT_hot(
        LALT(KC_F10), KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, QK_BOOTLOADER, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        TG(BASIC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                     QK_UNDERGLOW_MODE_PREVIOUS, QK_UNDERGLOW_TOGGLE, QK_UNDERGLOW_MODE_NEXT
    ),

    [BASIC] = LAYOUT_hot(
        MO(RAISE),  KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,   
        MO(COMMANDS), KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  
        KC_TRNS, KC_ESC, KC_A,    KC_S,    KC_D,   KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,          KC_ENT,  
        MO(LOWER),   KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,   KC_V,     KC_B,    KC_LEFT_ALT,    KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_UP,   MO(COMMANDS), 
        KC_LCTL, MO(LOWER),                  KC_LGUI, KC_SPC,   KC_ENT,  MO(RAISE),                                    KC_LEFT, KC_DOWN, KC_RIGHT
    ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  if (rgblight_is_enabled()) {
    rgblight_set_layer_state(2, layer_state_cmp(state, LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, RAISE));
    rgblight_set_layer_state(4, layer_state_cmp(state, COMMANDS));
  }
  return state;
}

void  process_combo_event(uint16_t comboIndex, bool pressed) {
  switch (comboIndex) {
    case CMB_CTRL:
      if (pressed) {
        register_code(KC_LCTL);
        layer_on(LOWER);
      } else {
        unregister_code(KC_LCTL);
        layer_clear();
      }
      break ;
  }
}

void keyboard_post_init_user(void) {
    rgblight_layers = rgbLayers;
    rgblight_setrgb_range(0, 0, 0, 0, 5);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t keyTimer;

  switch (keycode) {
    case CUSTOM_COPY:
      if (record->event.pressed) {
        register_code(KC_LEFT_CTRL);
        register_code(KC_LEFT_SHIFT);
        tap_code(KC_C);
        unregister_code(KC_LEFT_CTRL);
        unregister_code(KC_LEFT_SHIFT);
      }
      return false;
    case CUSTOM_PASTE:
      if (record->event.pressed) {
        register_code(KC_LEFT_CTRL);
        register_code(KC_LEFT_SHIFT);
        tap_code(KC_V);
        unregister_code(KC_LEFT_CTRL);
        unregister_code(KC_LEFT_SHIFT);
      }
      return false;
    case TG(BASIC):
      // This is to fix an unwanted behavior with RGB when toggling layer
      if (record->event.pressed) {
        layer_off(COMMANDS);
        rgblight_blink_layer_repeat(1, RGB_REPEAT_INTERVAL, 5);
        layer_invert(BASIC);
      }
      return false;
    case LALT(KC_F10):
      if (record->event.pressed) {
        layer_off(COMMANDS);
        rgblight_blink_layer_repeat(0, RGB_REPEAT_INTERVAL, 5);
      }
      break ;
    case TMUX_PREFIX:
      if (record->event.pressed)
        SEND_STRING(SS_LCTL("a"));
      return false;
    default:
      if (keyTimer != 0)
        keyTimer = 0;
  }
  return true;
}
