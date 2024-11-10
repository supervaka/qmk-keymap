#include QMK_KEYBOARD_H

#include "supervaka.c"

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

// clang-format off
#define SYM_LAYER LAYOUT_5x6( \
    _______,   	_______,  _______,  _______,  _______,  _______,                        _______,  _______,  _______,  _______,  _______,    _______, \
    _______,	KC_TILD,  KC_LT,	KC_GT,	  KC_HASH,  KC_DEL,                         _______,  _______,  KC_LBRC,  KC_RBRC,  KC_PERC,	_______, \
    _______,  	KC_AMPR,  KC_MINS, 	KC_PLUS,  SYM_EQL,	KC_DLR,                         KC_GRV,   SYM_SCLN, KC_LPRN,  KC_RPRN,  KC_GRV,     _______, \
    _______,  	KC_CIRC,  KC_PIPE,  KC_ASTR,  KC_BSLS,  KC_ENT,                         _______,  KC_COLN,  KC_LCBR,  KC_RCBR,	KC_AT,   	_______, \
                          _______,  _______,                                                                _______,  _______, \
                                              _______,  _______,                        _______,  _______, \
                                              _______,  _______,                        _______,  _______, \
                                              _______,  _______,                        _______,  _______ \
) \

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_5x6(
    KC_ESC,   	KC_F1,    KC_F2,  	C(KC_C),  C(KC_V),  KC_F5,            KC_F6,    KC_F7,  	KC_F8,    KC_F9,    KC_F10,     KC_F11,
    KC_TAB, 	KC_X,	  KC_F,		KC_D,	  KC_P, 	KC_Q,             KC_J,	    QK_AREP,	KC_O,     KC_U,		KC_SCLN,	KC_F12,
    KC_BSPC,  	HOME_N,	  HOME_S, 	HOME_T,	  HOME_C,	SFT_Y,            SFT_M,    HOME_H,     HOME_A,	  HOME_E,	HOME_I,   	KC_UNDS,
    LM_LCTL,  	KC_B,     KC_V,		KC_K,	  SFT_G,	KC_W,             KC_COMMA, SFT_L,		KC_QUOT,  KC_SLSH,	KC_DOT,   	KC_ENT,
                          KC_ENT,   KC_LALT,                                                    _______,  KC_ENT,
                                              OSM_LSFT, KC_SPC,           NUM_R,    QK_REP,
                                              KC_ENT,  KC_HOME,           KC_END,   KC_ENT,
                                              _______, KC_GRV,            KC_LGUI,  _______
),
// SYM2 == SYM, is needed for layer tap issues when rapidly alternating hands
[SYM] = SYM_LAYER,
[SYM2] = SYM_LAYER,
[NUM] = LAYOUT_5x6(
    _______,   	_______,  _______,  _______,  _______,  _______,          _______,  _______,  _______,  _______,  _______,    QK_BOOTLOADER,
    _______,	_______,  KC_ESC,	KC_TAB,   KC_DEL,   _______,          _______,  _______,  KC_COMMA, KC_DOT,   _______,	  _______,
    _______,  	KC_1,     KC_2,  	KC_3,     SYM_4,    KC_5,             KC_6,     SYM_7,    KC_8,     KC_9,     KC_0,   	  _______,
    _______,  	KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  _______,          _______,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT,   _______,
                          _______,  _______,                                                  KC_PSCR, _______,
                                              _______,  _______,          _______,  KC_PSCR,
                                              _______,  _______,          _______,  _______,
                                              _______,  _______,          _______,  _______

),

[QWERTY] = LAYOUT_5x6(
    KC_GRV,   	_______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,  _______,  _______,    _______,
    _______,	KC_Q,	  KC_W,     KC_E,	  KC_R,	    KC_T,               KC_Y,	  KC_U,     KC_I,	  KC_O,	    KC_P,	    _______,
    _______,  	KC_A,	  KC_S,     KC_D,	  KC_F,	    KC_G,               KC_H,	  KC_J,     KC_K,	  KC_L,	    KC_SCLN,   	_______,
    _______,  	KC_Z,	  KC_X,     KC_C,	  KC_V,	    KC_B,               _______,  KC_LEFT,  KC_UP,    KC_DOWN,  KC_RIGHT,   _______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______,
                                                _______,_______,            _______,_______
),
};

