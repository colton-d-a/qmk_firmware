/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

#define L1_BSPC LT(1, KC_BSPC)
#define L2_SPC LT(2, KC_SPC)
#define XXX KC_NO

// Add case if you want to add a unique tapping term to a specific key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case KC_GRV:
        //     return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_4x6_5(KC_GRV,  KC_1, KC_2, KC_3,    KC_4,    KC_5,          KC_6,    KC_7,   KC_8,    KC_9,   KC_0,    KC_TILD,
                             KC_EQL,  KC_Q, KC_W, KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_BSLS,
                             KC_MINS, KC_A, KC_S, KC_D,    KC_F,    KC_G,          KC_H,    KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,
                             KC_ESC,  KC_Z, KC_X, KC_C,    KC_V,    KC_B,          KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
                                                  KC_LSFT, L1_BSPC, KC_DEL,        KC_TAB,  L2_SPC, KC_LSFT, 
                                                           KC_LCTL, KC_LALT,       KC_LGUI, KC_LCTL),

    [1] = LAYOUT_split_4x6_5(XXX,    XXX,     XXX,     XXX,     XXX,     XXX,      XXX,     XXX,     XXX,     KC_LPRN,  KC_RPRN, XXX,
                             XXX,    XXX,     XXX,     XXX,     XXX,     XXX,      XXX,     KC_LCBR, KC_RCBR, KC_LBRC,  KC_RBRC, XXX,
                             XXX,    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXX,     XXX,
                             XXX,    XXX,     XXX,     XXX,     XXX,     XXX,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,   XXX,     XXX,
                                                       XXX,     _______,  XXX,     _______,  KC_SPC, XXX, 
                                                                XXX,     XXX,      KC_RGUI, XXX),

    [2] = LAYOUT_split_4x6_5(XXX,     XXX,   XXX,    XXX,    XXX,     XXX,         XXX, XXX,     XXX,      XXX,     XXX,     XXX,
                             KC_SCRL, KC_F9, KC_F10, KC_F11, KC_F12,  KC_INS,      XXX, XXX,     XXX,      XXX,     XXX,     XXX,
                             KC_PAUS, KC_F5, KC_F6,  KC_F7,  KC_F8,   KC_PSCR,     XXX, KC_LSFT, KC_LCTL,  KC_LALT, KC_LGUI, XXX,
                             KC_NUM,  KC_F1, KC_F2,  KC_F3,  KC_F4,   KC_CAPS,     XXX, XXX,     XXX,      XXX,     XXX,     XXX,
                                                     XXX,    KC_BSPC, _______,     XXX, _______,  XXX, 
                                                             XXX,     KC_RALT,     XXX, XXX),
};
