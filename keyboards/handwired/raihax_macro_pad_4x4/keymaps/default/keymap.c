#include "kb.h"

enum layer {
    LAYER_FIRST,
    LAYER_SECOND,
};

#define LY_SECND MO(LAYER_SECOND)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_FIRST] = KEYMAP(
        _______,	LGUI(KC_ESC), 	LGUI(KC_Q), 	LY_SECND, 
	LGUI(KC_ENT), 	LGUI(KC_S), 	LGUI(KC_F), 	KC_WREF, 
	LGUI(KC_E), 	LGUI(KC_B), 	LGUI(KC_T), 	KC_CALC, 
	KC_MPRV, 	KC_MNXT, 	KC_MPLY, 	KC_MUTE
    ),

    [LAYER_SECOND] = KEYMAP(
        RESET,  	_______,	_______, 	_______,
        KC_LEFT,  	KC_DOWN,	KC_UP,		KC_RIGHT,
        _______,  	_______,	_______,	_______,
        _______,  	_______,	_______,	_______
    ),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}
