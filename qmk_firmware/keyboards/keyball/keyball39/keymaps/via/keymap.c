/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q      , KC_W     , KC_F     , KC_P     , KC_G     ,                                   KC_Y     , KC_U     , KC_U     , KC_Y     , KC_SCLN  ,
    KC_A      , KC_R     , KC_S     , KC_T     , KC_D     ,                                   KC_H     , KC_N     , KC_E     , KC_I     , KC_O     ,
    KC_Z      , KC_X     , KC_C     , KC_V     , KC_B     ,                                   KC_J     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    MO(3)     ,KC_MS_BTN2,KC_MS_BTN1, MO(1)    ,LSFT_T(KC_SPC),LCTL_T(KC_TAB),RCTL_T(KC_BSPC),LSFT_T(KC_ENT),_______,_______,_______,KC_LGUI
  ),

  [1] = LAYOUT_universal(
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  , _______  ,              _______  , _______  , _______  , _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  , _______  ,              _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  , _______  ,              _______  , _______  , _______  , _______  , _______  , _______
  ),

  [4] = LAYOUT_universal(
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  , _______  ,              _______  , _______  , _______  , _______  , _______  , _______
  ),

  [5] = LAYOUT_universal(
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  , _______  ,              _______  , _______  , _______  , _______  , _______  , _______
  ),

  [6] = LAYOUT_universal(
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  , _______  ,              _______  , _______  , _______  , _______  , _______  , _______
  ),

  [7] = LAYOUT_universal(
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  ,                                    _______  , _______  , _______  , _______  , _______  ,
    _______   , _______ , _______  , _______  , _______  , _______  ,              _______  , _______  , _______  , _______  , _______  , _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_layerinfo();
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
}
#endif
