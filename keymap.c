 /*
  * A Swedish layout in the spirit of Engram and Hands Down.
  */

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum custom_keycodes {
    V_SAVE = SAFE_RANGE,
	V_UNDO,
	V_QUIT,
	V_PSTU,
	V_SRPL,
};

enum layers {
	DEF = 0,
	NAV,
	SYM,
	FUN,
	NUM
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, FUN);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case V_SAVE:

        if (record->event.pressed) {
            SEND_STRING(">w");
			register_code(KC_ENTER);
		}
		else {
		    unregister_code(KC_ENTER);
        }
        break;

    case V_UNDO:
        if (record->event.pressed) {
            SEND_STRING(">u");
			register_code(KC_ENTER);
		}
		else {
			unregister_code(KC_ENTER);
        }
        break;

    case V_QUIT:
        if (record->event.pressed) {
            SEND_STRING(">q");
			register_code(KC_ENTER);
		}
		else {
			unregister_code(KC_ENTER);
        }
        break;

	case V_PSTU:
        if (record->event.pressed) {
            SEND_STRING(">pu");
			register_code(KC_ENTER);
		}
		else {
			unregister_code(KC_ENTER);
        }
        break;

	case V_SRPL:
        if (record->event.pressed) {
            SEND_STRING(">%s");
		}
		else {
        }
        break;
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[DEF] = LAYOUT_split_3x6_3(
        SE_DIAE, SE_Q,         SE_Y,         SE_O,         SE_U,         SE_ACUT,   SE_V,   SE_D,         SE_G,         SE_J,         SE_X,         SE_SECT,
		SE_MINS, LALT_T(SE_C), LCTL_T(SE_I), LGUI_T(SE_E), LSFT_T(SE_A), SE_COMM,   SE_K,   LSFT_T(SE_T), LGUI_T(SE_S), RCTL_T(SE_R), LALT_T(SE_L), SE_QUOT,
		SE_DQUO, SE_W,         SE_ARNG,      SE_ODIA,      SE_ADIA,      SE_DOT,    SE_P,   SE_B,         SE_F,         SE_M,         SE_Z,         TG(NUM),
		                                     TG(NAV),      KC_SPC,       MO(NAV),   MO(SYM),SE_N,         RALT_T(SE_H)
	),
	[NAV] = LAYOUT_split_3x6_3(
		KC_SLEP, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE,   KC_DEL,  KC_BSPC, KC_ESC,  KC_INS,  KC_NO,   KC_PWR,
		KC_WAKE, KC_LALT, KC_LCTL, KC_LGUI, KC_LSFT, KC_MPLY,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_CAPS, KC_NO,
		KC_NO,   V_SRPL,  V_QUIT,  V_SAVE,  V_UNDO,  V_PSTU,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,   KC_NO,
		                           KC_TRNS, KC_TRNS, KC_TRNS,   MO(SYM), KC_ENT, KC_TAB
	),
	[SYM] = LAYOUT_split_3x6_3(
		KC_NO, SE_PND, SE_LBRC, SE_LPRN, SE_LCBR, SE_COLN,   SE_SCLN, SE_RCBR, SE_RPRN, SE_RBRC, SE_CURR,  KC_NO,
		KC_NO, SE_AT,  SE_EXLM, SE_QUES, SE_ASTR, SE_SLSH,   SE_BSLS, SE_EQL,  SE_PLUS, SE_MINS, SE_HASH,  KC_NO,
		KC_NO, SE_DLR, SE_LABK, SE_PIPE, SE_RABK, SE_GRV,    SE_CIRC, SE_PERC, SE_AMPR, SE_TILD, SE_EURO,  KC_NO,
		                        SE_UNDS, KC_TRNS, MO(NAV),     KC_TRNS, KC_TRNS, KC_TRNS
	),
	[FUN] = LAYOUT_split_3x6_3(
		KC_NO,  KC_NO, LSFT(SE_G), SE_B,    SE_W,    SE_E,     SE_H,    SE_J,    SE_K,   SE_L,  KC_NO, KC_NO,
		KC_NO,  SE_7,  SE_3,       SE_1,    SE_5,    SE_9,     SE_8,    SE_4,    SE_0,   SE_2,  SE_6,  KC_NO,
		KC_F11, KC_F7, KC_F3,      KC_F1,   KC_F5,   KC_F9,    KC_F8,   KC_F4,   KC_F10, KC_F2, KC_F6, KC_F12,
		                           KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
	),
	[NUM] = LAYOUT_split_3x6_3(
	    RESET, KC_NO,   SE_Q, SE_W, SE_E, SE_R,    KC_PSLS,  KC_7,   KC_8,   KC_9,  KC_PMNS, KC_BSPC,
		KC_NO, KC_TAB,  SE_A, SE_S, SE_D, SE_F,    KC_PAST,  KC_4,   KC_5,   KC_6,  KC_PPLS, KC_TAB,
		KC_NO, KC_LSFT, SE_Z, SE_X, SE_C, SE_V,    KC_PEQL,  KC_1,   KC_2,   KC_3,  KC_PCMM, KC_TRNS,
		              KC_LALT, KC_LCTL, KC_SPC,    KC_ENT,   KC_0,   SE_DOT
	)
};
