ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../../rules.mk

ifeq ($(strip $(KEYBOARD)), handwired/dactyl_manuform/5x6)
BOOTLOADER = atmel-dfu
VIA_ENABLE = yes
endif

ifeq ($(strip $(KEYBOARD)), sofle_choc)
ENCODER_MAP_ENABLE = no
endif
