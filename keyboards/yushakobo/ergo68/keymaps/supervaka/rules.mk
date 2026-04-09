VIA_ENABLE = yes
DEFERRED_EXEC_ENABLE = no
KEY_OVERRIDE_ENABLE = no

ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../../../../../rules.mk
