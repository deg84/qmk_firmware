#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define MAC  1 // macOS default layer
#define FN   2 // functions layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ` ~   |  1 ! |  2 @ |  3 # |  4 $ |  5 % | ESC  |           |      |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |  - _   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |  [ {   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | L2     |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ; : |  ' "   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  , < |  . > |  / ? | ] }/SFT|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | LAlt | LGui | LAlt | Ctrl |                                       | Ctrl | RAlt |      |  \ | |  = + |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |  L1  |       |  L2  |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space| Back |------|       |------|      | Enter|
 *                                 |      | Space|  [   |       |   ]  |      | /fn  |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
  // left hand
  KC_GRV,         KC_1,     KC_2,     KC_3,     KC_4,     KC_5,  KC_ESC,
  KC_TAB,         KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,  KC_NO,
  LT(FN, KC_NO),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
  KC_LSFT,        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,  KC_NO,
  KC_LCTL,        KC_LALT,  KC_LGUI,  KC_LALT,  KC_LCTL,

                                              KC_NO,    TG(MAC),
                                                        KC_NO,
                                     KC_SPC,  KC_BSPC,  KC_LBRC,

                                                                    // right hand
                                                                            KC_NO,  KC_6,   KC_7,     KC_8,     KC_9,     KC_0,         KC_MINS,
                                                                            KC_NO,  KC_Y,   KC_U,     KC_I,     KC_O,     KC_P,         KC_LBRC,
                                                                                    KC_H,   KC_J,     KC_K,     KC_L,  KC_SCLN,         KC_QUOT,
                                                                            KC_NO,  KC_N,   KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  SFT_T(KC_RBRC),
                                                                                         KC_RCTL,  KC_RALT,    KC_NO,  KC_BSLS,          KC_EQL,

                                                                      TG(FN),    KC_NO,
                                                                       KC_NO,
                                                                       KC_RBRC,  KC_NO,  LT(FN, KC_ENT)
),
/* Keymap 1: macOS layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | LGUI |                                       | RGUI |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[MAC] = KEYMAP(
  // left hand
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LGUI,

                                                    KC_TRNS,  KC_TRNS,
                                                              KC_TRNS,
                                          KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                                    // right hand
                                                                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                                                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                                            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                                                                KC_RGUI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,

                                                                            KC_TRNS,  KC_TRNS,
                                                                            KC_TRNS,
                                                                            KC_TRNS,  KC_TRNS,  KC_TRNS
),
/* Keymap 1: Functions Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |Teensy|           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |  Up  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      | Left | Down | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      | DEL  |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// FUNCTIONS
[FN] = KEYMAP(
       // left hand
        KC_ESC,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    RESET,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                               KC_TRNS,  KC_TRNS,
                                                         KC_TRNS,
                                     KC_TRNS,  KC_DELT,  KC_TRNS,
                                                                                // right hand
                                                                                  KC_F7,    KC_F8,    KC_F9,   KC_F10,    KC_F11,   KC_F12,   KC_TRNS,
                                                                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,
                                                                                          KC_LEFT,  KC_DOWN,    KC_UP,  KC_RIGHT,  KC_TRNS,   KC_TRNS,
                                                                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_UP,   KC_TRNS,
                                                                                                    KC_TRNS,  KC_TRNS,   KC_LEFT,  KC_DOWN,  KC_RIGHT,
                                                                                KC_TRNS,  KC_TRNS,
                                                                                KC_TRNS,
                                                                                KC_TRNS,  KC_TRNS,  KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_led_all_set(LED_BRIGHTNESS_LO);
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
