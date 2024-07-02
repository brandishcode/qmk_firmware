/* Copyright 2023 yushakobo
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

#include "keycodes.h"
#include "keymap_japanese.h"
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BACKSPACE,
        KC_TAB,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    JP_EISU, JP_KANA, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,   KC_SLSH,
        KC_QUOT, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_HOME, KC_END,  KC_D,    KC_H,    KC_T,    KC_N,    KC_S,   KC_ENT,
        KC_MINS, KC_EQL,  KC_Q,    KC_J,    KC_K,    KC_X,    KC_GRAVE,KC_SCLN, KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,   KC_RSFT,
        JP_MHEN, JP_HENK, KC_PSCR, KC_LALT, MO(2),   KC_LSFT, KC_LCTL, KC_LGUI, KC_SPC,  MO(1),   KC_RALT, KC_LGUI, KC_END, KC_RCTL
    ),
        [1] = LAYOUT(
        RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
        KC_CAPS, KC_QUOT, KC_LBRC, KC_RBRC, KC_NUHS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_COPY, KC_PASTE,KC_TRNS, KC_RIGHT,KC_SCLN,
        KC_GRV,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_UNDO, KC_CUT,  KC_DOWN, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        MO(0),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // caps lock cyan
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 128);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(0, 0, 0, 0);
    }

    // num lock cyan
    if (host_keyboard_led_state().num_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, 0, 128);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(1, 0, 0, 0);
    }

    // scroll lock cyan
    if (host_keyboard_led_state().scroll_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(2, 0, 0, 128);
    } else {
        RGB_MATRIX_INDICATOR_SET_COLOR(2, 0, 0, 0);
    }

    // layer state
    switch (get_highest_layer(layer_state)) {
        case 1:
            RGB_MATRIX_INDICATOR_SET_COLOR(37, 0, 0, 128);
            break;
        case 2:
            RGB_MATRIX_INDICATOR_SET_COLOR(38, 0, 0, 128);
            break;
        case 3:
            RGB_MATRIX_INDICATOR_SET_COLOR(39, 0, 0, 128);
            break;
    }
    return false;
}
