#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-------------------------------.
 * |       |       |       |       |
 * |-------+-------+-------+-------|
 * |       |       |       |       |
 * |-------+-------+-------+-------|
 * |       |       |       |       |
 * |-------+-------+-------+-------|
 * |       |       |       |       |
 * `-------------------------------'
 */
[0] = LAYOUT(
  KC_A,       KC_B,      KC_C,      KC_D,
  KC_E,       KC_F,      KC_G,      KC_H,
  KC_I,       KC_J,      KC_K,      KC_L,
  RGB_MOD,    KC_NO,     KC_NO,     KC_NO
),
/* LAYER 2-4
 * ,-------------------------------.
 * |       |       |       |       |
 * |-------+-------+-------+-------|
 * |       |       |       |       |
 * |-------+-------+-------+-------|
 * |       |       |       |       |
 * |-------+-------+-------+-------|
 * |       |       |       |       |
 * `-------------------------------'
 */
[1] = LAYOUT(
  KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,
  KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,
  KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,
  KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS
),
[2] = LAYOUT(
  KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,
  KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,
  KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,
  KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS
),
[3] = LAYOUT(
  KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,
  KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,
  KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS,
  KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_TRNS
)
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (get_highest_layer(layer_state|default_layer_state) > 0) {
          if (clockwise) {
              rgblight_decrease_val();
          } else {
              rgblight_increase_val();
          }
        } else {
          if (clockwise) {
              rgblight_decrease_val();
          } else {
              rgblight_increase_val();
          }
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    }
    return false;
};

