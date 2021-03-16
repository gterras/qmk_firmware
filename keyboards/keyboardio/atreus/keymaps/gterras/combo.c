/* Copyright 2021 Grégoire Terras
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

#include "keymap_french.c"
#include "quantum.h"

enum combo_events {
    RESET_KEYBOARD,
    COPY,
    PASTE,
};

const uint16_t PROGMEM reset_combo[] = {FR_B, FR_J, KC_LCTRL, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {FR_P, FR_U, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {FR_P, FR_E, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [RESET_KEYBOARD] = COMBO_ACTION(reset_combo),
    [COPY] = COMBO_ACTION(copy_combo),
    [PASTE] = COMBO_ACTION(paste_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case RESET_KEYBOARD: if (pressed) { reset_keyboard(); } break;
    case COPY: if (pressed) { tap_code16(LCTL(FR_C)); } break;
    case PASTE: if (pressed) { tap_code16(LCTL(FR_V)); } break;
    }
}
