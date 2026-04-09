/* Copyright 2023 yushakobo
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
#include "supervaka.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_ESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                      KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
        KC_TAB,  KC_X,     KC_F,     KC_D,     KC_P,     KC_Q,     KC_LBRC, KC_RBRC, KC_J,     QK_AREP,  KC_O,     KC_U,     KC_UNDS,  KC_F12,
        KC_BSPC, HOME_N,   HOME_S,   HOME_T,   HOME_C,   NUM_Y,    KC_LPRN, KC_RPRN, NUM_M,    HOME_H,   HOME_A,   HOME_E,   HOME_I,   KC_UNDS,
        LM_SYM,  KC_B,     SYM_V,    NUM_K,    SFT_G,    KC_W,     KC_LCBR, KC_RCBR, KC_COMMA, SFT_L,    NUM_QUOT, SYM_SLSH, KC_DOT,   KC_ENT,
        KC_LEFT, KC_PGUP,  KC_PGDN,  KC_LALT, OSM_LSFT, NUM_SPC,   KC_ENT,  KC_ENT,  NUM_R,    SYM_REP,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT
    ),

    [SYM] = LAYOUT(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                      KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
        _______,  KC_TILD,  KC_LT,    KC_GT,    KC_HASH,  KC_DEL,   _______, _______, _______,  _______,  KC_LBRC,  KC_RBRC,  KC_PERC,  KC_F12,
        _______,  KC_AMPR,  KC_MINS,  KC_PLUS,  SYM_EQL,  KC_DLR,   _______, _______, KC_EQL,   SYM_SCLN, KC_LPRN,  KC_RPRN,  KC_GRV,   _______,
        _______,  KC_CIRC,  KC_PIPE,  KC_ASTR,  KC_BSLS,  KC_ENT,   _______, _______, _______,  KC_COLN,  KC_LCBR,  KC_RCBR,  KC_AT,    _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,  _______,  _______,  _______,  _______
    ),

    // SYM2 is identical to SYM (needed for layer tap issues when rapidly alternating hands)
    [SYM2] = LAYOUT(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                      KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
        _______,  KC_TILD,  KC_LT,    KC_GT,    KC_HASH,  KC_DEL,   _______, _______, _______,  _______,  KC_LBRC,  KC_RBRC,  KC_PERC,  KC_F12,
        _______,  KC_AMPR,  KC_MINS,  KC_PLUS,  SYM_EQL,  KC_DLR,   _______, _______, KC_EQL,   SYM_SCLN, KC_LPRN,  KC_RPRN,  KC_GRV,   _______,
        _______,  KC_CIRC,  KC_PIPE,  KC_ASTR,  KC_BSLS,  KC_ENT,   _______, _______, _______,  KC_COLN,  KC_LCBR,  KC_RCBR,  KC_AT,    _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,  _______,  _______,  _______,  _______
    ),

    [NUM] = LAYOUT(
        _______,  _______,  RM_TOGG,  RM_NEXT,  _______,  _______,                    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  KC_ESC,   KC_TAB,   KC_DEL,   _______,  _______, _______, _______,  _______,  KC_COMMA, KC_DOT,   _______,  _______,
        _______,  KC_1,     KC_2,     SYM_3,    SYM_4,    KC_5,     _______, _______, KC_6,     SYM_7,    SYM_8,    KC_9,     KC_0,     _______,
        _______,  KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  _______,  _______, _______, _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  KC_PSCR,  _______,  _______,  _______,  _______
    ),

    [QWERTY] = LAYOUT(
        KC_GRV,   _______,  _______,  _______,  _______,  _______,                    _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     _______, _______, KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     _______,
        _______,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     _______, _______, KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  _______,
        _______,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     _______, _______, _______,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT, _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______, _______, _______,  _______,  _______,  _______,  _______,  _______
    )
    // clang-format on
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  // caps lock cyan
  if (host_keyboard_led_state().caps_lock) {
    RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 128);
  } else {
    RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 0);
  }

  // num lock cyan
  if (host_keyboard_led_state().num_lock) {
    RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, 0, 128);
  } else {
    RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, 0, 0);
  }

  // scroll lock cyan
  if (host_keyboard_led_state().scroll_lock) {
    RGB_MATRIX_INDICATOR_SET_COLOR(2, 0, 0, 128);
  } else {
    RGB_MATRIX_INDICATOR_SET_COLOR(2, 0, 0, 0);
  }

  // layer state
  switch (get_highest_layer(layer_state)) {
    case SYM:
    case SYM2:
      RGB_MATRIX_INDICATOR_SET_COLOR(37, 0, 0, 128);
      break;
    case NUM:
      RGB_MATRIX_INDICATOR_SET_COLOR(38, 0, 0, 128);
      break;
    case QWERTY:
      RGB_MATRIX_INDICATOR_SET_COLOR(39, 0, 0, 128);
      break;
  }
  return false;
}
