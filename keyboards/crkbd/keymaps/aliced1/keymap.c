/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


// Compile using 
// qmk compile -e CONVERT_TO=BLOK -kb crkbd/r2g -km aliced1

#include QMK_KEYBOARD_H

enum combos { 
  Y_U_RPRN,
  H_J_RBRC,
  N_M_RCBR,
  R_T_LPRN,
  F_G_LBRC,
  V_B_LCBR,
  J_K_ESC,
  
};

const uint16_t PROGMEM y_u_rprn[] = { KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM h_j_rbrc[] = { KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM n_m_rcbr[] = { KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM r_t_lprn[] = { KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM f_g_lbrc[] = { KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM v_b_lcbr[] = { KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM j_k_esc[] = { KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [Y_U_RPRN] = COMBO(y_u_rprn, KC_RPRN),
  [H_J_RBRC] = COMBO(h_j_rbrc, KC_RBRC),
  [N_M_RCBR] = COMBO(n_m_rcbr, KC_RCBR),
  [R_T_LPRN] = COMBO(r_t_lprn, KC_LPRN),
  [F_G_LBRC] = COMBO(f_g_lbrc, KC_LBRC),
  [V_B_LCBR] = COMBO(v_b_lcbr, KC_LCBR),
  [J_K_ESC] = COMBO(j_k_esc, KC_ESC),
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OS_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OS_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, OS_LCTL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                OS_LALT, KC_ENT, LT(1,KC_TAB),             LT(2,KC_BSPC),KC_SPC,OS_LALT
                                      //`--------------------------'  `--------------------------'

  ),

    // Num/Navigation Layer
    [1] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------           ,-----------------------------------------------------.
      KC_TRNS, KC_HOME, LCS(KC_TAB), KC_UP ,       LCTL(KC_TAB),  KC_PGUP,                QK_REP,  KC_7,    KC_8,    KC_9,    KC_PMNS,  KC_TRNS,
  //|--------+--------+-------------+-------------+--------------+--------------|        |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_END,  KC_LEFT,     KC_DOWN,      KC_RIGHT,      KC_PGDN,                KC_0,    KC_4,    KC_5,    KC_6,    KC_PPLS,  KC_TRNS,
  //|--------+--------+-------------+-------------+--------------+--------------|        |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_NO,   C(KC_X),     C(KC_C),      C(KC_V),       C(KC_SLSH),             KC_DOT,  KC_1,    KC_2,    KC_3,    KC_EQL,   KC_TRNS,
  //|--------+--------+-------------+-------------+--------------+--------------|        |--------+--------+--------+--------+--------+--------|
                                                          KC_TRNS,KC_TRNS,KC_TRNS,      LT(3,KC_BSPC),KC_TRNS,KC_TRNS
                                                      //`--------------------------'  `--------------------------'
  ),

    // Symbol Layer
    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TRNS, KC_NO,  KC_CIRC, KC_EQL,  KC_GRAVE, KC_NO,                       KC_TILD, KC_EXLM, KC_BSLS, KC_CIRC, KC_NO,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_NO,  KC_AT,   KC_ASTR, KC_MINS,  KC_HASH,                     KC_DLR,  KC_QUOT, KC_PIPE, KC_PERC,  KC_NO,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_NO,  KC_NO,   KC_PLUS, KC_UNDS,  KC_NO,                       KC_NO,   KC_DQT,  KC_AMPR, KC_NO,   KC_NO,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                     KC_TRNS,KC_TRNS,LT(3,KC_TAB),      KC_TRNS,KC_TRNS,KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

    // Function/Media Layer
    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6,                          KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_NO,   KC_MRWD, KC_MFFD, KC_MPLY, KC_VOLU,                      KC_BRIU, LCS(KC_V),LSFT(KC_INS), DM_REC2, DM_RSTP, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TRNS, OS_LGUI, KC_NO,   KC_NO,   KC_MSTP, KC_VOLD,                      KC_BRID, LSG(KC_S),KC_NO, DM_PLY2, KC_NO, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_TRNS,KC_TRNS,KC_TRNS,      KC_TRNS,KC_TRNS,KC_TRNS
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
