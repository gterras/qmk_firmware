/* Copyright 2021 Grégoire Terras

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
#include "quantum.h"

// Events
enum tap_dance_state {
    SINGLE_HOLD = 1,
    SINGLE_TAP,
    DOUBLE_SINGLE_TAP,
    TRIPLE_SINGLE_TAP,
};

// Tap State
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    }
    if (state->count == 2) return DOUBLE_SINGLE_TAP;
    if (state->count == 3) return TRIPLE_SINGLE_TAP;
    else return 4; // Any number higher than the maximum count value returned above
}

// C
// ╔═══════════════════════════╗
// ║  SINGLE_TAP:        c     ║
// ║  SINGLE_HOLD:       ç     ║
// ╚═══════════════════════════╝

static int state_c  = 0;

void c_finished(qk_tap_dance_state_t *state, void *user_data) {
    state_c = cur_dance(state);
    switch (state_c) {
        case SINGLE_TAP: register_code16(FR_C); break;
        case SINGLE_HOLD: register_code16(FR_CCED); break;
    }
}
void c_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state_c) {
        case SINGLE_TAP: unregister_code16(FR_C); break;
        case SINGLE_HOLD: unregister_code16(FR_CCED); break;
    }
    state_c = 0;
}

// E
// ╔═══════════════════════════╗
// ║  SINGLE_TAP:        e     ║
// ║  SINGLE_HOLD:       ê     ║
// ╚═══════════════════════════╝

static int state_e  = 0;

void e_finished(qk_tap_dance_state_t *state, void *user_data) {
    state_e = cur_dance(state);
    switch (state_e) {
        case SINGLE_TAP: register_code16(FR_E); break;
        case SINGLE_HOLD: register_code16(FR_CIRC); register_code16(FR_E); break;
    }
}
void e_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state_e) {
        case SINGLE_TAP: unregister_code16(FR_E); break;
        case SINGLE_HOLD: unregister_code16(FR_CIRC); unregister_code16(FR_E); break;
    }
    state_e = 0;
}

// E Acute
// ╔═══════════════════════════╗
// ║  SINGLE_TAP:        é     ║
// ║  SINGLE_HOLD:       è     ║
// ╚═══════════════════════════╝

static int state_e_acute  = 0;

void e_acute_finished(qk_tap_dance_state_t *state, void *user_data) {
    state_e_acute = cur_dance(state);
    switch (state_e_acute) {
        case SINGLE_TAP: register_code16(FR_EACU); break;
        case SINGLE_HOLD: register_code16(FR_EGRV); break;
    }
}
void e_acute_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state_e_acute) {
        case SINGLE_TAP: unregister_code16(FR_EACU); break;
        case SINGLE_HOLD: unregister_code16(FR_EGRV); break;
    }
    state_e_acute = 0;
}

// K
// ╔═══════════════════════════╗
// ║  SINGLE_TAP:        k     ║
// ║  SINGLE_HOLD:       à     ║
// ╚═══════════════════════════╝

static int state_k  = 0;

void k_finished(qk_tap_dance_state_t *state, void *user_data) {
    state_k = cur_dance(state);
    switch (state_k) {
        case SINGLE_TAP: register_code16(FR_K); break;
        case SINGLE_HOLD: register_code16(FR_AGRV); break;
    }
}
void k_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state_k) {
        case SINGLE_TAP: unregister_code16(FR_K); break;
        case SINGLE_HOLD: unregister_code16(FR_AGRV); break;
    }
    state_k = 0;
}

// U
// ╔═══════════════════════════╗
// ║  SINGLE_TAP:        u     ║
// ║  SINGLE_HOLD:       ù     ║
// ╚═══════════════════════════╝

static int state_u  = 0;

void u_finished(qk_tap_dance_state_t *state, void *user_data) {
    state_u = cur_dance(state);
    switch (state_u) {
        case SINGLE_TAP: register_code16(FR_U); break;
        case SINGLE_HOLD: register_code16(FR_UGRV); break;
    }
}
void u_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state_u) {
        case SINGLE_TAP: unregister_code16(FR_U); break;
        case SINGLE_HOLD: unregister_code16(FR_UGRV); break;
    }
    state_u = 0;
}

// Dot
// ╔═══════════════════════════╗
// ║  SINGLE_TAP:        .     ║
// ║  DOUBLE_SINGLE_TAP: ..    ║
// ║  TRIPLE_SINGLE_TAP: ...   ║
// ║  SINGLE_HOLD:       :     ║
// ╚═══════════════════════════╝

static int state_dot  = 0;

void dot_finished(qk_tap_dance_state_t *state, void *user_data) {
    state_dot = cur_dance(state);
    switch (state_dot) {
        case SINGLE_TAP: register_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_DOT); register_code16(FR_DOT); break;
        case TRIPLE_SINGLE_TAP: tap_code16(FR_DOT); tap_code16(FR_DOT); register_code16(FR_DOT); break;
        case SINGLE_HOLD: register_code16(FR_COLN); break;
    }
}

void dot_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state_dot) {
        case SINGLE_TAP: unregister_code16(FR_DOT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_DOT); break;
        case TRIPLE_SINGLE_TAP: unregister_code16(FR_DOT); break;
        case SINGLE_HOLD: unregister_code16(FR_COLN); break;
    }
    state_dot = 0;
}

// Virgules
// ╔═══════════════════════════╗
// ║  SINGLE_TAP:        ,     ║
// ║  DOUBLE_SINGLE_TAP: ,,    ║
// ║  SINGLE_HOLD:       :     ║
// ╚═══════════════════════════╝

static int state_virg  = 0;

void virg_finished(qk_tap_dance_state_t *state, void *user_data) {
    state_virg = cur_dance(state);
    switch (state_virg) {
        case SINGLE_TAP: register_code16(FR_COMM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_COMM); register_code16(FR_COMM); break;
        case SINGLE_HOLD: register_code16(FR_SCLN); break;
    }
}

void virg_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state_virg) {
        case SINGLE_TAP: unregister_code16(FR_COMM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_COMM); break;
        case SINGLE_HOLD: unregister_code16(FR_SCLN); break;
    }
    state_virg = 0;
}

// Slashes
// ╔═══════════════════════════╗
// ║  SINGLE_TAP:        /     ║
// ║  DOUBLE_SINGLE_TAP: //    ║
// ║  SINGLE_HOLD:       \     ║
// ╚═══════════════════════════╝

static int state_slashes  = 0;

void slashes_finished(qk_tap_dance_state_t *state, void *user_data) {
    state_slashes = cur_dance(state);
    switch (state_slashes) {
        case SINGLE_TAP: register_code16(FR_SLSH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_SLSH); register_code16(FR_SLSH); break;
        case SINGLE_HOLD: register_code16(FR_BSLS); break;
    }
}

void slashes_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state_slashes) {
        case SINGLE_TAP: unregister_code16(FR_SLSH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_SLSH); break;
        case SINGLE_HOLD: unregister_code16(FR_BSLS); break;
    }
    state_slashes = 0;
}

// Brackets
// ╔═══════════════════════════╗
// ║  SINGLE_TAP:        [     ║
// ║  SINGLE_HOLD:       ]     ║
// ╚═══════════════════════════╝

static int state_brackets  = 0;

void brackets_finished(qk_tap_dance_state_t *state, void *user_data) {
    state_brackets = cur_dance(state);
    switch (state_brackets) {
        case SINGLE_TAP: register_code16(FR_LBRC); break;
        case SINGLE_HOLD: register_code16(FR_RBRC); break;
    }
}
void brackets_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state_brackets) {
        case SINGLE_TAP: unregister_code16(FR_LBRC); break;
        case SINGLE_HOLD: unregister_code16(FR_RBRC); break;
    }
    state_brackets = 0;
}

// Angled Brackets
// ╔═══════════════════════════╗
// ║  SINGLE_TAP:        <     ║
// ║  SINGLE_HOLD:       >     ║
// ╚═══════════════════════════╝

static int state_angled_brackets  = 0;

void angled_brackets_finished(qk_tap_dance_state_t *state, void *user_data) {
    state_angled_brackets = cur_dance(state);
    switch (state_angled_brackets) {
        case SINGLE_TAP: register_code16(FR_LABK); break;
        case SINGLE_HOLD: register_code16(FR_RABK); break;
    }
}
void angled_brackets_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state_angled_brackets) {
        case SINGLE_TAP: unregister_code16(FR_LABK); break;
        case SINGLE_HOLD: unregister_code16(FR_RABK); break;
    }
    state_angled_brackets = 0;
}

// Curly Brackets
// ╔═══════════════════════════╗
// ║  SINGLE_TAP:        {     ║
// ║  DOUBLE_SINGLE_TAP: {{    ║
// ║  SINGLE_HOLD:       }     ║
// ╚═══════════════════════════╝

static int state_curly_brackets  = 0;

void curly_brackets_finished(qk_tap_dance_state_t *state, void *user_data) {
    state_curly_brackets = cur_dance(state);
    switch (state_curly_brackets) {
        case SINGLE_TAP: register_code16(FR_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_LCBR); register_code16(FR_LCBR); break;
        case SINGLE_HOLD: register_code16(FR_RCBR); break;
    }
}

void curly_brackets_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state_curly_brackets) {
        case SINGLE_TAP: unregister_code16(FR_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_LCBR); break;
        case SINGLE_HOLD: unregister_code16(FR_RCBR); break;
    }
    state_curly_brackets = 0;
}

// Parentheses
// ╔═══════════════════════════╗
// ║  SINGLE_TAP:        (     ║
// ║  DOUBLE_SINGLE_TAP: ((    ║
// ║  SINGLE_HOLD:       )     ║
// ╚═══════════════════════════╝

static int state_parentheses  = 0;

void parentheses_finished(qk_tap_dance_state_t *state, void *user_data) {
    state_parentheses = cur_dance(state);
    switch (state_parentheses) {
        case SINGLE_TAP: register_code16(FR_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(FR_LPRN); register_code16(FR_LPRN); break;
        case SINGLE_HOLD: register_code16(FR_RPRN); break;
    }
}

void parentheses_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state_parentheses) {
        case SINGLE_TAP: unregister_code16(FR_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(FR_LPRN); break;
        case SINGLE_HOLD: unregister_code16(FR_RPRN); break;
    }
    state_parentheses = 0;
}

// Currency
// ╔═══════════════════════════╗
// ║  SINGLE_TAP:        €     ║
// ║  SINGLE_HOLD:       £     ║
// ╚═══════════════════════════╝

static int state_currency  = 0;

void currency_finished(qk_tap_dance_state_t *state, void *user_data) {
    state_currency = cur_dance(state);
    switch (state_currency) {
        case SINGLE_TAP: register_code16(FR_EURO); break;
        case SINGLE_HOLD: register_code16(FR_PND); break;
    }
}

void currency_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state_currency) {
        case SINGLE_TAP: unregister_code16(FR_EURO); break;
        case SINGLE_HOLD: unregister_code16(FR_PND); break;
    }
    state_currency = 0;
}


// Associate tap dance with defined functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    [C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, c_finished, c_reset),
    [E] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, e_finished, e_reset),
    [K] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, k_finished, k_reset),
    [U] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, u_finished, u_reset),
    [DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dot_finished, dot_reset),
    [VIRG] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, virg_finished, virg_reset),
    [E_ACUTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, e_acute_finished, e_acute_reset),
    [SLASHES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, slashes_finished, slashes_reset),
    [BRACKETS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, brackets_finished, brackets_reset),
    [ANGLED_BRACKETS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, angled_brackets_finished, angled_brackets_reset),
    [CURLY_BRACKETS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, curly_brackets_finished, curly_brackets_reset),
    [PARENTHESES] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, parentheses_finished, parentheses_reset),
    [CURRENCY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, currency_finished, currency_reset),
};
