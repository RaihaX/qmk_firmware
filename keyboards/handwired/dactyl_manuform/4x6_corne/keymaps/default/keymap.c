#include QMK_KEYBOARD_H


#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Fillers to make layering more clear

#define ____ KC_TRNS

#define GUI_SLS  LGUI(KC_SLSH)
#define GUI_ENT  LGUI(KC_ENT)
#define GUI_TAB  LGUI_T(KC_TAB)

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum {
    TD1 = 1,
    TD2 = 2,
    TD3 = 3
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD1] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQUAL),
    [TD2] = ACTION_TAP_DANCE_DOUBLE(KC_BSLASH, KC_SLASH),
    [TD3] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Base (qwerty)
	 * +-----------------------------------------+                             +-----------------------------------------+
	 * | TAB  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  | DEL  |
	 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
	 * | SHFT |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |  '   |
	 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
	 * | CTRL |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |ENTER |
	 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
	 *                      |lower | spc  | alt  |                             | gui  | bspc |raise |
	 *                      +------+------+------+                             +------+------+------+
	 */

	[_BASE] = LAYOUT( \
	  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
		  GUI_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_DEL, \
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, \
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_ENTER,\
	  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		                                      LOWER,   KC_SPC, KC_LALT,    KC_LGUI,  KC_BSPC,  RAISE \
		                                  //`--------------------------'  `--------------------------'
		                  \
	),

	[_LOWER] = LAYOUT(
	  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
		  KC_TILD, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX,                      XXXXXXX, TD(TD2), XXXXXXX, KC_WH_U, XXXXXXX, RESET  , \
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_WH_R, XXXXXXX, \
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LCTL, KC_PGUP, KC_PGDN, KC_HOME,  KC_END, XXXXXXX,                      TD(TD3), TD(TD1), KC_WH_L, KC_WH_D, KC_PSCR, XXXXXXX, \
	  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		                                      LOWER,   KC_SPC, KC_LALT,    GUI_ENT,  KC_BSPC,  RAISE \
		                                  //`--------------------------'  `--------------------------'
	),

	[_RAISE] = LAYOUT(
	  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
		   KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX, \
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LSFT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX, \
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LCTL,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD, KC_VOLU, XXXXXXX, \
	  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		                                        LOWER,  KC_SPC, GUI_SLS,   KC_LGUI,  KC_BSPC,  RAISE \
		                                  //`--------------------------'  `--------------------------'                         
	)
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
