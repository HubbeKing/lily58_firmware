#pragma once

#include "config_common.h"

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS { C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2, B6 }
#define DIODE_DIRECTION COL2ROW

// Set handed-ness by EEPROM flag
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_split_keyboard.md#handedness-by-eeprom
#define EE_HANDS

// Define Communication
#define USE_SERIAL
#define SOFT_SERIAL_PIN D2

// Allows dual displays to show modifiers etc
#define SERIAL_USE_MULTI_TRANSACTION
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_TRANSPORT_MIRROR

// Set maximum length of tap to 225ms
// Longer than 225ms is a hold
#define TAPPING_TERM 225

// Debounce - wait for 10ms after state change before sending keypresses, to prevent unintended inputs due to noise
#define DEBOUNCE 10

// set OLED brightness (0-255)
#define OLED_BRIGHTNESS 255

// require mod-taps to be held for TAPPING_TERM before registering a hold,
// even if another key is tapped
#define IGNORE_MOD_TAP_INTERRUPT

// when tap-holding a mod-tap key, force hold rather than repeating tap
//#define TAPPING_FORCE_HOLD

// Use the lily font to get the Lily58 logo instead of the qmk logo
#define OLED_FONT_H "lib/glcdfont_lily.c"
