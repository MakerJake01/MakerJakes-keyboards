// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum keyboard_layers {
    _QWERTY,
    _GAMING,
    _LOWER,
    _RAISE,
    _MOUSEKEYS
};

#define NUMBRS MO(_RAISE)
#define FUNCT  MO(_LOWER)
#define gta    TG(_GAMING)
#define MOUSE  MO(_MOUSEKEYS)

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_GAMING,
    KC_LOWER,
    KC_RAISE,
    KC_MOUSEKEYS,
};

enum combo_events {
  gta_lay
};

const uint16_t PROGMEM gta_combo[] = {KC_Q, KC_T, COMBO_END};

combo_t key_combos[] = {
  [gta_lay] = COMBO_ACTION(gta_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case gta_lay:
      if (pressed) {
        layer_invert(_GAMING);
      }
      break;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT_j42k_2x2u_ortho(
		KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT, 
		KC_LALT, MOUSE, NUMBRS, KC_SPC, FUNCT, KC_RGUI),

	[_RAISE] = LAYOUT_j42k_2x2u_ortho(
		KC_F1,     KC_F2,       KC_F3,     KC_F4,       KC_F5,     KC_F6,    KC_F7,     KC_F8,       KC_F9,     KC_F10,      KC_F11,     KC_F12,
    	KC_MUTE,   KC_1,        KC_2,      KC_3,        KC_4,      KC_5,     KC_6,      KC_7,        KC_8,      KC_9,        KC_0,       KC_ENT,
    	KC_LSFT,   KC_EXLM,     KC_AT,     KC_HASH,     KC_DLR,    KC_PERC,  KC_CIRC,   KC_AMPR,     KC_ASTR,   KC_LPRN,     KC_RPRN,    KC_RCTL,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_LOWER] = LAYOUT_j42k_2x2u_ortho(
		KC_ESC,    KC_TRNS,     KC_PGUP,   KC_TRNS,     KC_TRNS,    QK_BOOT,    MOUSE,         KC_TRNS,     KC_UP,      KC_TRNS,    KC_TRNS,    KC_DEL, 
	    KC_TRNS,   KC_HOME,     KC_PGDN,   KC_VOLD,     KC_VOLU,    KC_MINS,    KC_EQL,    KC_LEFT,     KC_DOWN,    KC_RIGHT,   KC_QUOT,    KC_GRV,
    	KC_LSFT,   KC_MPLY,     KC_QUOT,   KC_TRNS,     KC_TRNS,    KC_LBRC,    KC_RBRC,   KC_TRNS,     KC_TRNS,    KC_DOT,     KC_BSLS,    KC_RCTL,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_GAMING] = LAYOUT_j42k_2x2u_ortho(
		KC_ESC,    KC_TRNS,     KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,     KC_P7,   KC_P8,     KC_P9,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TAB,    KC_TRNS,     KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,     KC_P4,   KC_P5,     KC_P6,    KC_TRNS,    KC_QUOT,    KC_TRNS,
		KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,     KC_P1,   KC_P2,     KC_P3,    KC_TRNS,    KC_BSLS,    KC_TRNS,
		KC_LCTL, KC_LALT, KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS),

	[_MOUSEKEYS] = LAYOUT_j42k_2x2u_ortho(
		KC_ESC,    KC_TRNS,     KC_BTN1,   KC_MS_U,     KC_BTN2,   KC_TRNS,     KC_TRNS,   KC_TRNS,     KC_WH_U,    KC_TRNS,    KC_TRNS,    KC_TRNS,
		KC_TAB,    KC_TRNS,     KC_MS_L,   KC_MS_D,     KC_MS_R,   KC_TRNS,     KC_TRNS,   KC_WH_L,     KC_WH_D,    KC_WH_R,    KC_QUOT,    KC_TRNS,
		KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,     KC_TRNS,   KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_BSLS,    KC_TRNS,
		KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};