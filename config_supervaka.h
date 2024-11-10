#define QUICK_TAP_TERM 0
#define DEBOUNCE 10

#define PERMISSIVE_HOLD
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define COMBO_TERM 20
#define COMBO_ONLY_FROM_LAYER 1 // qwerty layer

// Holding Shift while Caps Word is active inverts the shift state.
#define CAPS_WORD_INVERT_ON_SHIFT
// When idle, turn off Caps Word after 5 seconds.
#define CAPS_WORD_IDLE_TIMEOUT 5000

// Don't apply custom shift keys with mods other than Shift.
#define CUSTOM_SHIFT_KEYS_NEGMODS ~MOD_MASK_SHIFT

// Only apply custom shift keys on layer 0.
#define CUSTOM_SHIFT_KEYS_LAYER_MASK (1 << 0)