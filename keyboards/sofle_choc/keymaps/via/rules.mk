# ENCODER_MAP_ENABLE = no
# VIA_ENABLE = no

# # Reduce compiled size
# MOUSEKEY_ENABLE = no
# SPACE_CADET_ENABLE = no
# GRAVE_ESC_ENABLE = no

# CAPS_WORD_ENABLE = yes
# COMBO_ENABLE = yes

# REPEAT_KEY_ENABLE = yes

# SRC += features/achordion.c
# SRC += features/custom_shift_keys.c

# RGB_MATRIX_ENABLE = no

# ACHORDION_ENABLE ?= yes
# ifeq ($(strip $(ACHORDION_ENABLE)), yes)
# 	OPT_DEFS += -DACHORDION_ENABLE
# 	SRC += features/achordion.c
# endif

# CUSTOM_SHIFT_KEYS_ENABLE ?= yes
# ifeq ($(strip $(CUSTOM_SHIFT_KEYS_ENABLE)), yes)
# 	OPT_DEFS += -DCUSTOM_SHIFT_KEYS_ENABLE
# 	SRC += features/custom_shift_keys.c
# endif


DEFERRED_EXEC_ENABLE = no

ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../../../../rules.mk
