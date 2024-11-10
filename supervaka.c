#ifdef ACHORDION_ENABLE
#include "features/achordion.h"
#endif  // ACHORDION_ENABLE
#ifdef CUSTOM_SHIFT_KEYS_ENABLE
#include "features/custom_shift_keys.h"
#endif  // CUSTOM_SHIFT_KEYS_ENABLE

#pragma once 

enum layers {
  BASE,
  QWERTY,
  SYM,
  SYM2,
  NUM,
};

// not used
#define SYM_PLUS LT(SYM,KC_PLUS)
#define SYM_LPRN LT(SYM,KC_LPRN)
#define SYM_3    LT(SYM,KC_3)
#define SYM_2    LT(SYM,KC_2)
// not used

// #define LM_LCTL		LM(QWERTY,MOD_LCTL)
#define LM_LCTL     LT(QWERTY, KC_Z)

#define LM_LGUI 	LM(QWERTY,MOD_LGUI)
#define OSM_LGUI 	OSM(MOD_LGUI)
#define OSM_LCTL 	OSM(MOD_LCTL)
#define OSM_LSFT 	OSM(MOD_LSFT)

#define HOME_N 	LALT_T(KC_N)
#define HOME_S 	LGUI_T(KC_S)
#define HOME_T 	LCTL_T(KC_T)
#define HOME_C 	LT(SYM,KC_C)

#define SFT_Y LSFT_T(KC_Y)
#define SFT_M LSFT_T(KC_M)

#define SFT_G LSFT_T(KC_G)
#define SFT_L LSFT_T(KC_L)

#define HOME_H  LT(SYM2,KC_H)
#define HOME_A	RCTL_T(KC_A)
#define HOME_E 	RGUI_T(KC_E)
#define HOME_I 	LALT_T(KC_I)

#define NUM_R   LT(NUM,KC_R)

#define SYM_EQL  LT(SYM,KC_EQL)
#define SYM_SCLN LT(SYM2,KC_SCLN)
#define SYM_1    LT(SYM,KC_1)
#define SYM_0    LT(SYM2,KC_0)

#define SYM_4    LT(SYM,KC_4)
#define SYM_7    LT(SYM2,KC_7)

#define SYM_N    LT(SYM,KC_N)
#define SYM_I    LT(SYM2,KC_I)

#ifdef COMBO_ENABLE
const uint16_t PROGMEM test_combo1[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {KC_Z, KC_X, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, C(KC_C)),
    COMBO(test_combo2, C(KC_V)),
    COMBO(test_combo3, C(KC_Z)),
};
#endif // COMBO_ENABLE

#ifdef CUSTOM_SHIFT_KEYS_ENABLE
const custom_shift_key_t custom_shift_keys[] = {
  {KC_DOT, KC_EXLM}, // Shift . is !
  {KC_COMMA, KC_DOT},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);
#endif  // CUSTOM_SHIFT_KEYS_ENABLE


static bool lt_with_mods_key(keyrecord_t* record, uint8_t mods) {
  if (!record->tap.count) {      // If holding.
    if (record->event.pressed) { // On hold press.
      register_mods(mods);       // Hold mods.
    } else {                     // On hold release.
      unregister_mods(mods);     // Release mods.
    }
  }
  return true;  // Continue normal handling.
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#ifdef ACHORDION_ENABLE
  if (!process_achordion(keycode, record)) { return false; }
#endif  // ACHORDION_ENABLE
#ifdef CUSTOM_SHIFT_KEYS_ENABLE
  if (!process_custom_shift_keys(keycode, record)) { return false; }
#endif  // CUSTOM_SHIFT_KEYS_ENABLE

    switch (keycode) {
        // Behave as KC_Z on tap, LM(_NAV, MOD_LCTL) on hold.
        case LM_LCTL:
            return lt_with_mods_key(record, MOD_BIT(KC_LCTL));
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef ACHORDION_ENABLE
  achordion_task();
#endif  // ACHORDION_ENABLE
}

#ifdef ACHORDION_ENABLE
bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand
  switch (tap_hold_keycode) {
    case LM_LCTL:
    case NUM_R:

    // case HOME_C:
    // case HOME_H:
    // case SYM_EQL:
    // case SYM_SCLN:
    // case SYM_1:
    // case SYM_0:
      return true;
      break;

  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}
#endif  // ACHORDION_ENABLE

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case HOME_N: return KC_X;
        case HOME_S: return KC_F;
        case HOME_T: return KC_D;  // For "TD" bigram.
		    case HOME_C: return KC_P;

        case NUM_R: return KC_R;


		case KC_B: return KC_X;
		case KC_V: return KC_F;
		case KC_K: return KC_D;
		case KC_G: return KC_P;

		case KC_X: return KC_B;
		case KC_F: return KC_V;
		case KC_D: return KC_K;
		case KC_P: return KC_G;

		case HOME_A: return KC_O;
		case HOME_E: return KC_U;
        case HOME_I: return KC_COMMA;

        case KC_M: return KC_M;
        case SFT_M: return KC_M;
        case KC_L: return KC_M;

        case KC_O: return KC_A;
        case KC_U: return KC_E;

        case KC_LBRC: return KC_LPRN;
        case KC_LPRN: return KC_LBRC;

        case KC_RBRC: return KC_RPRN;
        case KC_RPRN: return KC_RBRC;
    }

    return KC_TRNS;
}
