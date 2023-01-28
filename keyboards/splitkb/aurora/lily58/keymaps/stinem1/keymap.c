#include QMK_KEYBOARD_H

enum layers {
    _DEFAULT,
    _LOWER,
	_RAISE,
	_ADJUST,
	_GAMING
};

enum {
  TD_GAMING
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DEFAULT] = LAYOUT(KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV ,
            			KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_MINS,
            			KC_LCTL, KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                   KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,
            			KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , XXXXXXX, XXXXXXX, KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                                   KC_LALT, KC_LGUI, MO(1)  , KC_SPC , KC_ENT , MO(2)  , KC_BSPC, KC_RGUI),
	
	[_LOWER] = LAYOUT(_______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
            		  KC_F1  ,   KC_F2,   KC_F3, KC_F4  , KC_F5  , KC_F6  ,                       KC_F7  , KC_F8  ,KC_F9   , KC_F10 , KC_F11 , KC_F12 ,
            		  KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
            		  _______, _______, _______, _______, _______, _______, _______,     _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
                                                 _______, TD(TD_GAMING), _______, _______,     _______, MO(3)  , _______, _______),

	[_RAISE] = LAYOUT(_______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
            		  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
            		  KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
            		  KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,     _______, KC_PLUS, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,
                                                 _______, _______, MO(3)  , _______,     _______, _______, _______, _______),
	
	[_ADJUST] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
				       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
				       XXXXXXX, RGB_M_B, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
				       KC_LSFT, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
				                                  _______, _______, _______, _______,     _______, _______, _______, _______),

	[_GAMING] = LAYOUT(KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
			    	   KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , TD(TD_GAMING),                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
				       KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  
				       KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_M   , KC_B   , XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
				                                  KC_LALT, KC_LGUI, KC_SPC , KC_ENT ,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX)
};

#ifdef TAP_DANCE_ENABLE
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
		register_code(KC_T);
	} else if (state->count == 2) {
		if (layer_state_is(_GAMING)) {
			layer_off(_GAMING);
		} else {
			layer_on(_GAMING);
		}
	}
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
	if (state->count == 1) {
		unregister_code(KC_T);
	}
}

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_GAMING] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};
#endif
