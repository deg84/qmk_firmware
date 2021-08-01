#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |   |   ]  |   Y  |   U  |   I  |   O  |   P  |   -  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Alt  |   A  |   S  |   D  |   F  |   G  |  (   |   |   )  |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Sft  |   Z  |   X  |   C  |   V  |   B  |  {   |   |   }  |   N  |   M  |   ,  |   .  |   /  |\/Sft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | GUI  |      | ESC  |EN/   |Space/|BS/   |   |Back  |Enter/|JA/   |      |=>GAME|=>SYMB|   =  |
   * |      |      |      |      |~SYMB |RCtrl |~META |   |Space |~META |~SYMB |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASE] = LAYOUT( \
    KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,              KC_T,           KC_LBRC,           KC_RBRC,    KC_Y,             KC_U,              KC_I,    KC_O,     KC_P,     KC_MINS, \
    KC_LALT,  KC_A,    KC_S,    KC_D,   KC_F,              KC_G,           S(KC_9),           S(KC_0),    KC_H,             KC_J,              KC_K,    KC_L,     KC_SCLN,  KC_QUOT, \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V,              KC_B,           S(KC_LBRC),        S(KC_RBRC), KC_N,             KC_M,              KC_COMM, KC_DOT,   KC_SLSH,  SFT_T(KC_BSLS), \
    KC_LCTRL, KC_LGUI, XXXXXXX, KC_ESC, LT(SYMB, KC_MHEN), RCTL_T(KC_SPC), LT(META, KC_BSPC), KC_BSPC,    LT(META, KC_ENT), LT(SYMB, KC_HENK), XXXXXXX, TG(GAME), TG(SYMB), KC_EQL \
  ),

  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |  [   |   |   ]  |   6  |   7  |   8  |   9  |   0  |   -  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Alt  |      |      |      |      |      |  (   |   |   )  | Left | Down |  Up  |Right |      |      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |   | F12  |  F6  |  F7  |  F8  |  F9  | F10  |\/Sft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | GUI  |      | ESC  |EN/   |Space/|BS/   |   |Back  |Enter/|JA/   |Reset |=>GAME|=>SYMB|   =  |
   * |      |      |      |      |~SYMB |RCtrl |~META |   |Space |~META |~SYMB |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, KC_6,    KC_7,    KC_8,  KC_9,    KC_0,    _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8, KC_F9,  KC_F10,  SFT_T(KC_BSLS), \
    _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, RESET, _______, _______, _______ \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |  [   |   |   ]  |   ^  |   &  |   *  |   (  |   )  |   _  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Alt  |      |      |      |      |      |  (   |   |   )  |      |      |      |      |   :  |   "  |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |      |      |      |      |      |  {   |   |   }  |      |      |   <  |   >  |   ?  |   \  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | GUI  |      | ESC  |EN/   |Space/|BS/   |   |Back  |Enter/|JA/   |      |=>GAME|=>SYMB|   +  |
   * |      |      |      |      |~SYMB |RCtrl |~META |   |Space |~META |~SYMB |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
    S(KC_GRV), S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), _______, _______, S(KC_6), S(KC_7), S(KC_8),    S(KC_9),   S(KC_0),    S(KC_MINS), \
    _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,   S(KC_SCLN), S(KC_QUOT), \
    _______,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, S(KC_COMM), S(KC_DOT), S(KC_SLSH), S(KC_BSLS), \
    _______,   _______, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX,    _______,   _______,    S(KC_EQL) \
  ),

  /* GAME
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |   |   ]  |   Y  |   U  |   I  |   O  |   P  |   -  |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Alt  |   A  |   S  |   D  |   F  |   G  |  (   |   |   )  |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | Sft  |   Z  |   X  |   C  |   V  |   B  |  {   |   |   }  |   N  |   M  |   ,  |   .  |   /  | \/Sft|
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | Ctrl | GUI  |      | ESC  | 　　  |Space |Back  |   |Back  |Enter | Del  |      |=>GAME|=>SYMB|   =  |
   * |      |      |      |      |      |      |Space |   |Space |      |      |      |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [GAME] = LAYOUT( \
    KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,   KC_LBRC,    KC_RBRC,    KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    KC_MINS, \
    KC_LALT,  KC_A,    KC_S,    KC_D,   KC_F,    KC_G,   S(KC_9),    S(KC_0),    KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT,  KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,   S(KC_LBRC), S(KC_RBRC), KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, SFT_T(KC_BSLS), \
    KC_LCTRL, KC_LGUI, XXXXXXX, KC_ESC, XXXXXXX, KC_SPC, KC_BSPC,    KC_BSPC,    KC_ENT, KC_DELT, XXXXXXX,  _______, _______, KC_EQL \
  )

};
