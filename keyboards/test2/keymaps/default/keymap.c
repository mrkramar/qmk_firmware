#include <stdio.h>
#include QMK_KEYBOARD_H
#include "oled.c"

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT( \
  QK_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, \
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
            KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,     KC_MUTE,    KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
        	        KC_LCTL, KC_LALT, KC_LGUI, KC_LOWER, KC_SPC,     KC_SPC,  KC_RAISE,KC_RCTRL,KC_HOME, KC_END \
),

[_LOWER] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, KC_DEL,\
  KC_CAPS,  RGB_HUI  , RGB_SAI,  RGB_VAI ,  RGB_SPI ,RGB_MODE_FORWARD,                      RGB_TOG, XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, KC_F12 , \
  KC_LSFT, KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, KC_PSCR, \
           KC_EQL,   KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, \
                       _______, _______, _______, _______, _______,       _______, _______, _______, KC_PGUP, KC_PGDOWN\
),

[_RAISE] = LAYOUT( \
  KC_GRAVE, _______ , _______ , _______ , _______ , _______,                         _______,  _______  , _______,  KC_MINS, KC_UNDERSCORE   , KC_EQL,   \
  KC_CAPS,  _______, _______, _______, _______, _______,                         _______,  _______  , _______,  KC_LEFT_CURLY_BRACE ,  KC_RIGHT_CURLY_BRACE ,KC_PLUS, \
  KC_LSFT, _______, _______, _______, _______, _______,                        _______,  _______  , KC_UP,  KC_LEFT_BRACKET ,KC_RIGHT_BRACKET, KC_PIPE,\
           _______, _______, _______, _______, _______,  _______,       _______,   _______,  KC_LEFT  , KC_DOWN,  KC_RIGHT ,  KC_BACKSLASH , \
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ \
)
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {

        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case _RAISE:
                if (clockwise) {
                    if (!is_alt_tab_active) {
                        is_alt_tab_active = true;
                        register_code(KC_LALT);
                    }
                    alt_tab_timer = timer_read();
                    tap_code16(KC_TAB);
                    } else {
                    if (!is_alt_tab_active) {
                        is_alt_tab_active = true;
                        register_code(KC_LALT);
                    }
                    alt_tab_timer = timer_read();
                    tap_code16(S(KC_TAB));
                    }
                break;
            case _LOWER:
                if (clockwise) {
                    tap_code(KC_RIGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
        }

    } else if (index == 1) {

        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
                break;
            case _RAISE:
                if (clockwise) {
                    tap_code(KC_LEFT);
                } else {
                    tap_code(KC_RIGHT);
                }
                break;
            case _LOWER:
                if (clockwise) {
                    tap_code(KC_RIGHT);
                } else {
                    tap_code(KC_LEFT);
                }
                break;
        }

    }
    return true;
}

#endif

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 750) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
    }
    return true;
}
