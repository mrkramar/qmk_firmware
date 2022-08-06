#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x1269
#define PRODUCT_ID      0x1269
#define DEVICE_VER      0x0001
#define MANUFACTURER    mk
#define PRODUCT         klavesnicka

#define MASTER_RIGHT

/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

/* key matrix pins */
#define MATRIX_ROW_PINS { F6, F7, B1, B3, B2 }
#define MATRIX_COL_PINS { B5, B4, E6, D7, C6, D4, B6 }
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TERM 100
#define DEBOUNCE 5

/* encoder support */
#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }
#define ENCODERS_PAD_A_RIGHT { F4 }
#define ENCODERS_PAD_B_RIGHT { F5 }
#define ENCODER_RESOLUTION 2

#define TAP_CODE_DELAY 10

/* communication between sides */
#define USE_SERIAL
#define SERIAL_USE_MULTI_TRANSACTION
#define SOFT_SERIAL_PIN D2

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* underglow */

#define RGB_DI_PIN D3
#define DRIVER_LED_TOTAL 14
#define RGB_MATRIX_SPLIT {7,7}

#define RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING

#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define RGB_MATRIX_CYCLE_UP_DOWN
#define RGB_MATRIX_CYCLE_OUT_IN
#define RGB_MATRIX_CYCLE_SPIRAL
#define RGB_MATRIX_CYCLE_PINWHEEL
#define RGB_MATRIX_RAINBOW_MOVING_CHEVRON

#define RGB_MATRIX_SLEEP

// firmware size optimalizations

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE
#define LAYER_STATE_8BIT
