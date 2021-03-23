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

enum custom_keycodes {
    CIRC_A = SAFE_RANGE,
    CIRC_E,
    CIRC_I,
    CIRC_O,
    CIRC_U,
    TREMA_E,
    TREMA_I,
    TREMA_U,
    TREMA_Y,
    FUNC_ACCENT,
}; 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BÉPO Layer - Tap
,----------------------------------.              ,----------------------------------.
|   B  |   É  |   P  |   O  |   W  |              |   J  |   V  |   D  |   L  |   M  |
|------+------+------+------+------|              |------+------+------+------+------|
|   A  |   U  |   I  |   E  |   ,  |              |   C  |   T  |   S  |   R  |   N  |
|------+------+------+------+------+------.,------+------+------+------+------+------|
|   K  |   Y  |   X  |   .  |   Z  |   ?  ||   !  |   '  |   Q  |   G  |   H  |   F  |
|------+------+------+------+------+------||------+------+------+------+------+------|
| Ctrl | Alt  | Tab  |  Esc | Space|      ||      | Entr |      |      |  Alt | Ctrl |
`-----------------------------------------'`-----------------------------------------' */

/* BÉPO Layer - Hold
,----------------------------------.              ,----------------------------------.
|      |      |      |      |      |              |      |      |      |      |      |
|------+------+------+------+------|              |------+------+------+------+------|
|      |      |      |      |   ;  |              |      |      |      |      |      |
|------+------+------+------+------+------.,------+------+------+------+------+------|
|Shift |      |      |      |   :  |      ||ACCENT|   "  |      |      |      | Shift|
|------+------+------+------+------+------||------+------+------+------+------+------|
|      |      | FUNC |MACRO1|RAISE |TILING||TILING| RAISE|MACRO2| FUNC |      |      |
`-----------------------------------------'`-----------------------------------------' */

    [_BEPO] = LAYOUT(
        FR_B, FR_EACU, FR_P, FR_O, FR_W, FR_J, FR_V, FR_D, FR_L, FR_M,
        FR_A, FR_U, FR_I, FR_E, TD(VIRG), FR_C, FR_T, FR_S, FR_R, FR_N,
        MT(MOD_LSFT, FR_K), FR_Y, FR_X, TD(DOT), FR_Z, FR_QUES, TD(ACCENT), TD(QUOTE), FR_Q, FR_G, FR_H, MT(MOD_RSFT, FR_F),
        KC_LCTRL, KC_LALT, LT(_FUNC, KC_TAB), LT(_LMACRO, KC_ESC), LT(_RAISE, KC_SPC), LT(_TILING, KC_NO), LT(_TILING, KC_NO), LT(_RAISE, KC_ENT), LT(_RMACRO, KC_NO), TD(ACCENT), KC_LALT, KC_LCTRL ),


/* RAISE Layer
,----------------------------------.              ,----------------------------------.
|   &  |   #  |  Up  |  { } | @ |  |              |   `  |   7  |   8  |   9  |   +  |
|------+------+------+------+------|              |------+------+------+------+------|
|   -  | Left |  Dwn | Rght | ( )  |              |   %  |   4  |   5  |   6  |   =  |
|------+------+------+------+------+------.,------+------+------+------+------+------|
|   _  |   $  |  / \ |  < > | [ ]  |  €£  ||  Del | Corr |   1  |   2  |   3  |   *  |
|------+------+------+------+------+------||------+------+------+------+------+------|
| Ctrl | Alt  | Tab  |  Esc | Space|      ||      | Enter|      |   0  |  Alt | Ctrl |
`-----------------------------------------'`-----------------------------------------' */

    [_RAISE] = LAYOUT(
        FR_AMPR, FR_HASH, KC_UP, TD(CURLY_BRACKETS), FR_AT, FR_GRV, KC_P7, KC_P8, KC_P9, FR_PLUS,
        FR_MINS, KC_LEFT, KC_DOWN, KC_RGHT, TD(PARENTHESES), FR_PERC, KC_P4, KC_P5, KC_P6, FR_EQL,
        MT(MOD_LSFT, FR_UNDS), FR_DLR, TD(SLASHES), TD(ANGLED_BRACKETS), TD(BRACKETS), TD(CURRENCY), KC_DEL, KC_BSPC, KC_P1, KC_P2, KC_P3, MT(MOD_LSFT, FR_ASTR),
        _______, _______, _______, _______, _______, KC_ENT, _______, _______, _______, KC_P0, _______, _______),


/* FUNC Layer
,----------------------------------.              ,----------------------------------.
| Mute | Vol- | Vol+ | Lum- | Lum+ |              | PgUp |  F7  |  F8  |  F9  |  F10 |
|------+------+------+------+------|              |------+------+------+------+------|
| Play | Prev | Next |NumLck|CapLck|              | PgDw |  F4  |  F5  |  F6  |  F11 |
|------+------+------+------+------+------.,------+------+------+------+------+------|
|      |      |      |      |      |      || Home |  End |  F1  |  F2  |  F3  |  F12 |
|------+------+------+------+------+------||------+------+------+------+------+------|
|      |      |      |      |      |      ||      |      |      |      |      |      |
`-----------------------------------------'`-----------------------------------------' */

    [_FUNC] = LAYOUT(
        KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_PGUP, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_MEDIA_PLAY_PAUSE,  KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_NLCK, KC_CAPS, KC_PGDOWN, KC_F4, KC_F5,  KC_F6, KC_F11,
        KC_LSHIFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_END, KC_F1, KC_F2, KC_F3, MT(MOD_LSFT, KC_F12),
        _______, _BEPO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),


/* MACROS Left Layer
,----------------------------------.              ,----------------------------------.
| QUIT | NEW  |RELOAD| SAVE |  URL |              |      |      |      |      |      |
|------+------+------+------+------|              |------+------+------+------+------|
|SELALL| COPY |CLPBD |PASTE |NEWTAB|              |      |      |      |      |      |
|------+------+------+------+------+------.,------+------+------+------+------+------|
|LINDEL| REDO | CUT  | COPY | UNDO |  DUP ||      |      |      |      |      |      |
|------+------+------+------+------+------||------+------+------+------+------+------|
|      |      |      |      |      |      ||      |      |      |      |      |      |
`-----------------------------------------'`-----------------------------------------' */

    [_LMACRO] = LAYOUT(
        LCTL(FR_W), LCTL(FR_N), LCTL(FR_R), LCTL(FR_S), LCTL(FR_L),                                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        LCTL(FR_A), KC_NO, LCTL(LCA(FR_R)), LCTL(FR_V), LCTL(FR_T),                                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        LSFT(LCTL(FR_K)), LCTL(FR_Y), LCTL(FR_X), LCTL(FR_C), LCTL(FR_Z), LSFT(LCTL(FR_D)), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                           KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),


/* MACROS Right Layer
,----------------------------------.              ,----------------------------------.
|      |      |      |      |      |              |      |      |      |      |      |
|------+------+------+------+------|              |------+------+------+------+------|
|      |      |      |      |      |              |      |      |  Up  |      |      |
|------+------+------+------+------+------.,------+------+------+------+------+------|
|      |      |      |      |      |      ||  Del | Corr | Left | Down | Rght |      |
|------+------+------+------+------+------||------+------+------+------+------+------|
|      |      |      |      |      |      ||      | Enter|      |      |      |      |
`-----------------------------------------'`-----------------------------------------' */

    [_RMACRO] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_UP, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_DEL, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_ENT, KC_NO, KC_NO, KC_NO, KC_NO),


/* ACCENT Layer
,----------------------------------.              ,----------------------------------.
|      |   È  |      |   Ô  |      |              |      |      |      |      |      |
|------+------+------+------+------|              |------+------+------+------+------|
|   Â  |   Û  |   Î  |   Ê  |      |              |   Ç  |      |      |      |      |
|------+------+------+------+------+------.,------+------+------+------+------+------|
|   À  |   Ù  |   Ï  |   Ë  |      |      ||ACCENT|      |      |      |      |      |
|------+------+------+------+------+------||------+------+------+------+------+------|
|      |   Ü  |   Ÿ  |      |      |      ||      |      |      |      |      |      |
`-----------------------------------------'`-----------------------------------------' */

    [_ACCENT] = LAYOUT(
        KC_NO, FR_EGRV, KC_NO, CIRC_O, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        CIRC_A, CIRC_U, CIRC_I, CIRC_E, KC_NO,                     FR_CCED, KC_NO, KC_NO, KC_NO, KC_NO,
        FR_AGRV, FR_UGRV, TREMA_I, TREMA_E, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, TREMA_U, TREMA_Y, KC_NO, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),


/* TILING Layer
,----------------------------------.              ,----------------------------------.
|      |      |      |      |      |              |      |      |      |      |      |
|------+------+------+------+------|              |------+------+------+------+------|
|      |      |      |      |      |              |      |      |      |      |      |
|------+------+------+------+------+------.,------+------+------+------+------+------|
|      |      |      |      |      |      ||      |      |      |      |      |      |
|------+------+------+------+------+------||------+------+------+------+------+------|
|      |      |      |      |      |      ||      |      |      |      |      |      |
`-----------------------------------------'`-----------------------------------------' */

    [_TILING] = LAYOUT(
        KC_NO, KC_NO, KC_NO, LCTL(LGUI(FR_F)), LCTL(LGUI(FR_G)), LCTL(LGUI(FR_B)), LCTL(LGUI(FR_T)), LCTL(LGUI(FR_W)), KC_NO, KC_NO  ,
        KC_NO, KC_NO, KC_NO, KC_NO, LCTL(LGUI(KC_UP)), LCAG(FR_K), KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_DOWN)), LCTL(LGUI(KC_RGHT)),  LCAG(FR_H), LCAG(FR_J), LCAG(FR_L), KC_NO, KC_NO, KC_NO  ,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, _TILING, _TILING, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

   switch (keycode) {

    // Disable RightCtrl+Q as it is easy to trigger by mistake
    case FR_Q:
    // Detect the activation of RightCtrl
    if ((get_mods() & MOD_BIT(KC_RCTRL)) == MOD_BIT(KC_RCTRL)) { return false; }
    return true;

   case CIRC_A: 
   if (record->event.pressed) { register_code16(FR_CIRC); register_code16(FR_A); }
   else { unregister_code16(FR_CIRC); unregister_code16(FR_A); } break;

   case CIRC_E: 
   if (record->event.pressed) { register_code16(FR_CIRC); register_code16(FR_E); }
   else { unregister_code16(FR_CIRC); unregister_code16(FR_E); } break;

   case CIRC_I:
   if (record->event.pressed) { register_code16(FR_CIRC); register_code16(FR_I); }
   else { unregister_code16(FR_CIRC); unregister_code16(FR_I); } break;

   case CIRC_O: 
   if (record->event.pressed) { register_code16(FR_CIRC); register_code16(FR_O); }
   else { unregister_code16(FR_CIRC); unregister_code16(FR_O); } break;

   case CIRC_U: 
   if (record->event.pressed) { register_code16(FR_CIRC); register_code16(FR_U); }
   else { unregister_code16(FR_CIRC); unregister_code16(FR_U); } break;

   case TREMA_E: 
   if (record->event.pressed) { register_code16(FR_DIAE); unregister_code16(FR_DIAE); register_code16(FR_E); }
   else { unregister_code16(FR_E); } break;

   case TREMA_I: 
   if (record->event.pressed) { register_code16(FR_DIAE); unregister_code16(FR_DIAE); register_code16(FR_I); }
   else { unregister_code16(FR_I); } break;

   case TREMA_U: 
   if (record->event.pressed) { register_code16(FR_DIAE); unregister_code16(FR_DIAE); register_code16(FR_U); }
   else { unregister_code16(FR_U); } break;  

   case TREMA_Y: 
   if (record->event.pressed) { register_code16(FR_DIAE); unregister_code16(FR_DIAE); register_code16(FR_Y); }
   else { unregister_code16(FR_Y); } break;

}

return true;
};
