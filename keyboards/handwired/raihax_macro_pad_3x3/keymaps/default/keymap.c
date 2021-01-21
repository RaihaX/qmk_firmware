#include "kb.h"

enum layer {
    LAYER_FIRST,
    LAYER_SECOND,
};

#define LY_SECND MO(LAYER_SECOND)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_FIRST] = KEYMAP(
		LGUI(KC_ESC), 	LGUI(KC_Q), 	LY_SECND, 
		LGUI(KC_ENT), 	LGUI(KC_S), 	LGUI(KC_F), 
		LGUI(KC_E), 	LGUI(KC_B), 	LGUI(KC_T)
    ),

    [LAYER_SECOND] = KEYMAP(
        RESET,  		_______,		_______,
        _______,  		_______,		_______,
        _______,  		_______,		_______
    ),
};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}
