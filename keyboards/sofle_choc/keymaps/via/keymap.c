/* Copyright 2023 Brian Low
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
#define SYM_LAYER LAYOUT( \
    _______,   	_______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,    _______, \
    _______,	KC_TILD,  KC_LT,	KC_GT,	  KC_HASH,  KC_DEL,                         _______,  _______,  KC_LBRC,  KC_RBRC,  KC_PERC,	_______, \
    _______,  	KC_AMPR,  KC_MINS, 	KC_PLUS,  SYM_EQL,	KC_DLR,                         KC_EQL,   SYM_SCLN, KC_LPRN,  KC_RPRN,  KC_GRV,     _______, \
    _______,  	KC_CIRC,  KC_PIPE,  KC_ASTR,  KC_BSLS,  KC_ENT,  XXXXXXX,     XXXXXXX,  _______,  KC_COLN,  KC_LCBR,  KC_RCBR,	KC_AT,   	_______, \
                          _______,  _______,  _______,  _______, _______,     _______,  _______,  _______,  _______,  _______ \
) \

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT(
    KC_ESC,   	KC_F1,    KC_F2,  	KC_F3,    KC_F4,    KC_F5,                          KC_F6,    KC_F7,  	KC_F8,    KC_F9,    KC_F10,     KC_F11,
    KC_TAB, 	KC_X,	  KC_F,		KC_D,	  KC_P, 	KC_Q,                           KC_J,	  QK_AREP,	KC_O,     KC_U,		KC_UNDS,	KC_F12,
    KC_BSPC,  	HOME_N,	  HOME_S, 	HOME_T,	  HOME_C,	SFT_Y,                          SFT_M,    HOME_H,	HOME_A,	  HOME_E,	HOME_I,   	KC_UNDS,
    LM_LCTL,  	KC_B,     KC_V,		KC_K,	  SFT_G,	KC_W,    XXXXXXX,     XXXXXXX,  KC_COMMA, SFT_L,	KC_QUOT,  KC_SLSH,	KC_DOT,   	KC_ENT,
                          KC_ENT,   KC_LALT,  OSM_LSFT,	KC_SPC,  KC_ENT,      KC_UNDS,  NUM_R,    QK_REP,   _______,  KC_ENT
),
// SYM2 == SYM, is needed for layer tap issues when rapidly alternating hands
[SYM] = SYM_LAYER,
[SYM2] = SYM_LAYER,
[NUM] = LAYOUT(
    _______,   	_______,  RGB_TOG,  RGB_MOD,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,    _______,
    _______,	_______,  KC_ESC,	KC_TAB,   KC_DEL,   _______,                        _______,  _______,  KC_COMMA, KC_DOT,   _______,	_______,
    _______,  	KC_1,     KC_2,  	SYM_3,    SYM_4,    KC_5,                           KC_6,    SYM_7,  	SYM_8,     KC_9,     KC_0,   	_______,
    _______,  	KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  _______, XXXXXXX,     XXXXXXX,  _______,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT,   _______,
                          _______,  _______,  _______,  _______, _______,     _______,  _______,  KC_PSCR,  _______,  _______
),
[QWERTY] = LAYOUT(
    KC_GRV,   	_______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,    _______,
    _______,	KC_Q,	  KC_W,     KC_E,	  KC_R,	    KC_T,                           KC_Y,	  KC_U,     KC_I,	  KC_O,	    KC_P,	    _______,
    _______,  	KC_A,	  KC_S,     KC_D,	  KC_F,	    KC_G,                           KC_H,	  KC_J,     KC_K,	  KC_L,	    KC_SCLN,   	_______,
    _______,  	KC_Z,	  KC_X,     KC_C,	  KC_V,	    KC_B,    XXXXXXX,     XXXXXXX,  _______,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT,   _______,
                          _______,  _______,  _______,  _______, _______,     _______,  _______,  _______,  _______,	_______
),
};



#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif
