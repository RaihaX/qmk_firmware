#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Reyhan Thee
#define PRODUCT         Macro Pad 4x4
#define DESCRIPTION     4x4 Macro Pad with two Rotary Encoder

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS { F7, F6, F5, F4 }
#define MATRIX_COL_PINS { C6, D4, D0, D1 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5

/* disable these deprecated features by default */
#ifndef LINK_TIME_OPTIMIZATION_ENABLE
  #define NO_ACTION_MACRO
  #define NO_ACTION_FUNCTION
#endif

#define ENCODERS_PAD_A { B5 }
#define ENCODERS_PAD_B { B6 }

#define ENCODER_RESOLUTION 1
#endif
