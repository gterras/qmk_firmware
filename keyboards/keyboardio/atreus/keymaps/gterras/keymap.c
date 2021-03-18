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

#include "shared_enum.h"
#include "keymap_french.c"

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BÉPO Layer - Tap
    ,----------------------------------.              ,----------------------------------.
    |   B  |   É  |   P  |   O  |   W  |              |   M  |   V  |   D  |   L  |   J  |
    |------+------+------+------+------|              |------+------+------+------+------|
    |   A  |   U  |   I  |   E  |   ,  |              |   C  |   T  |   S  |   R  |   N  |
    |------+------+------+------+------+------.,------+------+------+------+------+------|
    |   K  |   Y  |   X  |   Z  |   .  |   !  ||   ~  |   '  |   Q  |   G  |   H  |   F  |
    |------+------+------+------+------+------||------+------+------+------+------+------|
    |      |  Alt |      | Ctrl | Spc  |      ||      | Entr | CtrlR| Super|  Alt |      |
    `-----------------------------------------'`-----------------------------------------' */

  /* BÉPO Layer - Hold
    ,----------------------------------.              ,----------------------------------.
    |      |   È  |      |   Ô  |      |              |   "  |      |      |      |      |
    |------+------+------+------+------|              |------+------+------+------+------|
    |  MAJ |   Ù  |MACROS|   Ê  |   ;  |              |   Ç  |      |MACROS|      |  MAJ |
    |------+------+------+------+------+------.,------+------+------+------+------+------|
    |   À  |      |      |      |   :  |   ?  ||  ² |      |      |      |      |      |
    |------+------+------+------+------+------||------+------+------+------+------+------|
    |      |      |      | Ctrl |RAISE |      ||      | RAISE| CtrlR|      |      |      |
    `-----------------------------------------'`-----------------------------------------' */

  [_BEPO] = LAYOUT(
    FR_B, TD(E_ACUTE), FR_P, FR_O, FR_W, FR_M, FR_V, FR_D, FR_L, FR_J,
    MT(MOD_LSFT, FR_A), TD(U), LT(_MACROS, FR_I), TD(E), TD(VIRG), TD(C), FR_T, FR_S, FR_R, MT(MOD_RSFT, FR_N),
    TD(K), FR_Y, FR_X, TD(DOT), FR_Z, FR_EXLM, FR_TILD, FR_QUOT, FR_Q, FR_G, FR_H, FR_F,
    _______, KC_LALT, _______, KC_LCTRL, LT(_RAISE, KC_SPC), _______, _______, LT(_RAISE, KC_ENT), KC_RCTRL, KC_LGUI, KC_LALT, _______),




  /* RAISE Layer
    ,----------------------------------.              ,----------------------------------.
    |   &  |   #  |  Up  |  { } | @ |  |              |   `  |   7  |   8  |   9  |   +  |
    |------+------+------+------+------|              |------+------+------+------+------|
    |   -  | Left |  Dwn | Rght | ( )  |              |   %  |   4  |   5  |   6  |   =  |
    |------+------+------+------+------+------.,------+------+------+------+------+------|
    |   _  |   $  |  / \ |  < > | [ ]  |  €£  || ^¨ | Corr |   1  |   2  |   3  |   *  |
    |------+------+------+------+------+------||------+------+------+------+------+------|
    |  Esc |  Tab |  Alt | Ctrl |RAISE |      ||      | RAISE| CtrlR|   0  |  Alt | Suppr|
    `-----------------------------------------'`-----------------------------------------' */

  [_RAISE] = LAYOUT(
    FR_AMPR, FR_HASH, KC_UP, TD(CURLY_BRACKETS), FR_AT, FR_GRV, KC_P7, KC_P8, KC_P9, FR_PLUS,
    MT(MOD_LSFT, FR_MINS), KC_LEFT, KC_DOWN, KC_RGHT, TD(PARENTHESES), FR_PERC, KC_P4, KC_P5, KC_P6, MT(MOD_RSFT, FR_EQL),
    FR_UNDS, FR_DLR, TD(SLASHES), TD(ANGLED_BRACKETS), TD(BRACKETS), TD(CURRENCY), _______, KC_BSPC, KC_P1, KC_P2, KC_P3, FR_ASTR,
    KC_ESC, KC_TAB, KC_LALT, KC_LCTRL, KC_SPC, _______, _______, _RAISE, KC_RCTRL, KC_P0, KC_LALT, KC_DEL),


  /* MACROS Layer
    ,----------------------------------.              ,----------------------------------.
    |      | QUIT |      |NEWTAB|      |              |      |      |      |      |      |
    |------+------+------+------+------|              |------+------+------+------+------|
    |SE_ALL| COPY |MACROS| PASTE|      |              |      |      |MACROS|      |      |
    |------+------+------+------+------+------.,------+------+------+------+------+------|
    |      | SAVE | CUT  |      |      |      ||      |      |      |      |      |      |
    |------+------+------+------+------+------||------+------+------+------+------+------|
    |      |      |      |      |      |      ||      |      |      |      |      |      |
    `-----------------------------------------'`-----------------------------------------' */

  [_MACROS] = LAYOUT(
    _______,  LCTL(FR_W), _______,   LCTL(FR_T),  _______,                   _______,   _______,   _______,   _______,   _______  ,
    LCTL(FR_A),  LCTL(FR_C), _MACROS, LCTL(FR_V), _______,                   _______, _______,   _MACROS,   _______,   _______  ,
    _______,   LCTL(FR_Q), _______,   _______,   _______,   _______, _______, _______,   _______,   _______,   _______,   _______  ,
    _______,   _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ ),


  /* FUNC Layer
    ,----------------------------------.              ,----------------------------------.
    |      |      |      |      |      |              |      |      |      |      |      |
    |------+------+------+------+------|              |------+------+------+------+------|
    |      |      |      |      |      |              |      |      |      |      |      |
    |------+------+------+------+------+------.,------+------+------+------+------+------|
    |      |      |      |      |      |      ||      |      |      |      |      |      |
    |------+------+------+------+------+------||------+------+------+------+------+------|
    |      |      |      |      |      |      ||      |      |      |      |      |      |
    `-----------------------------------------'`-----------------------------------------' */

  [_FUNC] = LAYOUT(
    _______,  _______, _______,   _______,  _______,                   _______,   _______,   _______,   _______,   _______  ,
    _______,  _______, _______, _______, _______,                   _______, _______,   _______,   _______,   _______  ,
    _______,   _______, _______,   _______,   _______,   _______, _______, _______,   _______,   _______,   _______,   _______  ,
    _______,   _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______ ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {


    // Disable RightCtrl+Q as it is easy to trigger it by mistake

    case FR_Q:
        // Detect the activation of only Right Ctrl
        if ((get_mods() & MOD_BIT(KC_RCTRL)) == MOD_BIT(KC_RCTRL)) { return false; }
        return true;
    }

    return true;
};
