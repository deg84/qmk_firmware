#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _META 1
#define _GAME 2
#define _ADJUST 16

enum custom_keycodes {
  BASE = SAFE_RANGE,
  META,
  GAME,
  ADJUST,
};

#define KC_SCTL RCTL_T(KC_SPC)
#define KC_ETMT LT(_META, KC_ENT)
#define KC_BSST SFT_T(KC_BSLS)
#define KC_LRBC S(KC_9)
#define KC_RRBC S(KC_0)
#define KC_LCBC S(KC_LBRC)
#define KC_RCBC S(KC_RBRC)
#define KC_TGGM TG(_GAME)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  `   |   1  |   2  |   3  |   4  |   5  |  ESC |                    |      |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |                    |      |   Y  |   U  |   I  |   O  |   P  |  =   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Alt  |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Game |                    |Adjust|   N  |   M  |   ,  |   .  |   /  |\/Sft |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  Alt |  ESC ||||||||  EN  |Space/| Back |||||||| Back |Enter/|  JA  ||||||||      |      |      |      |
   * |      |      |      |      ||||||||      |RCtrl | Space|||||||| Space|~META |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_BASE] = LAYOUT( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC,                           XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,                          XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL , \
    KC_LALT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                          KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TGGM,                          ADJUST , KC_N,    KC_M,    KC_COMM, KC_DOT , KC_SLSH, KC_BSST, \
    KC_LCTL, KC_LGUI, KC_LALT, KC_ESC,           KC_MHEN, KC_SCTL, KC_BSPC,        KC_BSPC, KC_ETMT, KC_HENK,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
  ),

  /* META
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      | Left | Down |  Up  |Right |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  Alt |  ESC ||||||||  EN  |Space/| DELT |||||||| Back |Enter/|  JA  ||||||||      |      |      |      |
   * |      |      |      |      ||||||||      |RCtrl |      |||||||| Space|~META |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_META] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______, KC_DELT,      _______, _______, _______,          _______, _______, _______, _______  \
  ),

  /* GAME
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |  ESC |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |   Y  |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |      |      |      |      |      |   H  |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |  Alt |||||||| Space|      | Back ||||||||      |      |      ||||||||      |      |      |      |
   * |      |      |      |      ||||||||      |      | Space||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_GAME] = LAYOUT(
    _______, _______, _______, _______, _______, _______, KC_ESC ,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, KC_Y   ,                        _______, _______, _______, _______, _______, _______, _______, \
    KC_LCTL, _______, _______, _______, _______, _______, KC_H   ,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, KC_LALT,          KC_SPC , _______, KC_BSPC,      _______, _______, _______,          _______, _______, _______, _______  \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|   INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
    case META:
      if (record->event.pressed) {
        layer_on(_META);
      } else {
        layer_off(_META);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        layer_on(_GAME);
      } else {
        layer_off(_GAME);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _GAME:
        rgblight_enable_noeeprom();
        rgblight_sethsv_noeeprom(100, 255, 50);
        backlight_enable();
        backlight_level(4);
        break;
    case _ADJUST:
        rgblight_enable_noeeprom();
        backlight_enable();
        break;
    default:
        rgblight_disable_noeeprom();
        backlight_disable();
        break;
    }
  return state;
}
