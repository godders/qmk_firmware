/* Copyright 2022 godders
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
	_QWERTY,
	_LOWER,
	_RAISE,
	_FUNC,
	_RESET
};

enum keycodes {
	LOWER = SAFE_RANGE,
	RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT(
		KC_ESC,  KC_1,  KC_2,  KC_3,     KC_4,     KC_5,    KC_6,          KC_7,      KC_8,    KC_9,    KC_0,    KC_BSPC,
		KC_ESC,  KC_Q,  KC_W,  KC_E,     KC_R,     KC_T,    KC_Y,          KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_TAB,  KC_A,  KC_S,  KC_D, LSFT_T(KC_F), KC_G,    KC_H,       RSFT_T(KC_J), KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,  KC_X,  KC_C,     KC_V,     KC_B,    KC_N,          KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
		KC_LCTL, LCTL(KC_UP),  KC_SPC,   KC_LGUI,  RAISE,   KC_ENT, KC_MPLY, KC_SPC,    LOWER,   KC_RALT, LSG(KC_M),LSG(KC_O), KC_RCTL),
	[_LOWER] = LAYOUT(
		KC_GRV,  KC_EXLM, LSFT(KC_2),  LSFT(KC_3), KC_DLR,           KC_PERC, KC_CIRC,   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
		KC_GRV,  KC_1,  KC_2,  KC_3,     KC_4,     KC_5,             KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_BSPC,
		KC_NO,   KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,            KC_PGUP, KC_HOME,   KC_UP,   KC_END,  KC_NO,   KC_DEL,
		KC_TRNS, KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,            KC_PGDN, KC_LEFT,   KC_DOWN, KC_RGHT, KC_SLSH, KC_TRNS,
		KC_TRNS, KC_NO, KC_NO, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RALT_T(KC_BSPC),KC_NO,KC_NO, KC_TRNS),
	[_RAISE] = LAYOUT(
		KC_NO,   KC_NO,   KC_NO,      KC_NO,      KC_NO,   KC_NO,            KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_GRV,  KC_EXLM, LSFT(KC_2), LSFT(KC_3), KC_DLR,  KC_PERC,          KC_CIRC,   KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
		KC_NO,   KC_BTN4,   KC_BTN3,  KC_BTN2,    KC_BTN1, KC_WH_U,       LSFT(KC_NUBS),KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_NUHS,
		KC_TRNS, KC_BTN5,   KC_NO,    KC_WH_L,    KC_WH_R, KC_WH_D,          KC_NUBS,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TILD,
		KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[_FUNC] = LAYOUT(
		KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,
		KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,
		RGB_TOG, RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,          KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT,  KC_NO,    KC_NO,
		KC_TRNS, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,          KC_NO,   DT_DOWN, DT_PRNT, DT_UP,    KC_NO,    KC_TRNS,
		KC_TRNS, KC_NO,    KC_NO, MO(_RESET),KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,    KC_NO,    KC_TRNS),
	[_RESET] = LAYOUT(
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _FUNC);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _FUNC);
      }
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _FUNC);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _FUNC);
      }
      return false;
    }
  return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
	// Left
	if (index == 0) {
		// Cursor up/down
		tap_code(clockwise ? KC_DOWN : KC_UP);
	}
	// Centre
	else if (index == 1) {
		// Mouse wheel up/down
		tap_code(clockwise ? KC_VOLU : KC_VOLD);
	}
	// Right
	else if (index == 2) {
		if (IS_LAYER_ON(_LOWER) || IS_LAYER_ON(_RAISE)){
			// Mouse wheel up/down
			tap_code(clockwise ? KC_WH_D : KC_WH_U);
		}
		else{
			// Mouse wheel left/right
			tap_code(clockwise ? KC_WH_R : KC_WH_L);
		}
	}
	return true;
}
#endif
