#include QMK_KEYBOARD_H


// NICOLA親指シフト
#include "nicola.h"
NGKEYS nicola_keys;
// NICOLA親指シフト

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum keymap_layers {
  _QWERTY,
// NICOLA親指シフト
  _NICOLA, // NICOLA親指シフト入力レイヤー
// NICOLA親指シフト
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  KC_QWERTY = NG_SAFE_RANGE,
  KC_EISU,
  KC_LOWER,
  KC_RAISE,
  KC_ADJUST,
  KC_KANA2,
  KC_MACRO,
  RGBRST
};

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define _____ KC_TRNS
#define XXXXX KC_NO
#define KC_RST   RESET
#define KC_CTLTB CTL_T(KC_TAB)
#define KC_SFMN SFT_T(KC_MINS)
#define KC_GUIUP GUI_T(KC_UP)
#define KC_RESET RESET
#define KC_ALTDN RALT(KC_DOWN)

#define KC_C(A) C(KC_##A)
#define KC_S(A) S(KC_##A)
#define KC_G(A) G(KC_##A)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LPRN,    KC_RPRN,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
     KC_CTLTB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LEFT,   KC_RIGHT,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_SFMN,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         KC_GUIUP,KC_LOWER, KC_PENT,     KC_SPC,KC_RAISE, KC_ALTDN
//            KC_GUIUP, MT(KC_LOWER,KC_EISU), KC_PENT,     KC_SPC, MT(KC_RAISE,KC_KANA2), KC_ALTDN
                              //`----------------------------------'  `------------------------------------'

  ),
  
// NICOLA親指シフト
  // デフォルトレイヤーに関係なくQWERTYで
  [_NICOLA] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        _____,    NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,   NG_LU,      NG_RU,    NG_Y,    NG_U,    NG_I,    NG_O,    NG_P,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _____,    NG_A,    NG_S,    NG_D,    NG_F,    NG_G,   _____,      _____,    NG_H,    NG_J,    NG_K,    NG_L, NG_SCLN, NG_COLN,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _____,    NG_Z,    NG_X,    NG_C,    NG_V,    NG_B,                         NG_N,    NG_M, NG_COMM,  NG_DOT, NG_SLSH,   _____,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            _____,   _____,NG_SHFTL,   NG_SHFTR,   _____,   _____ 
                              //`----------------------------------'  `------------------------------------'
  ),
// NICOLA親指シフト




  [_LOWER] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        _____,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_LPRN,    KC_RPRN,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _____,    KC_4,    KC_5,    KC_6,KC_MACRO,   KC_UP,   _____,      _____,   KC_AT,    KC_4,    KC_5,    KC_6, KC_ASTR, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        _____,    KC_7,    KC_8,    KC_9,    KC_0, KC_DOWN,                         KC_0,    KC_1,    KC_2,    KC_3, KC_SLSH, KC_MINS,

  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        _____, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_LCTL,    KC_RCTL, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, // この行はこれでよい。
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _____, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT,    KC_RALT, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        _____, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

void matrix_init_user(void) {
  // NICOLA親指シフト
  set_nicola(_NICOLA);
  // NICOLA親指シフト
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

      switch (keycode) {
        case KC_EISU:
        if (record->event.pressed) {
            // NICOLA親指シフト
            nicola_off();
            // NICOLA親指シフト
        }
            return false;
            break;
        case KC_KANA2:
        if (record->event.pressed) {
            // NICOLA親指シフト
            nicola_on();
            // NICOLA親指シフト
        }
            return false;
            break;
        case KC_ADJUST:
        if (record->event.pressed) {
           layer_on(_ADJUST);
        } else {
           layer_off(_ADJUST);
        }
        return false;
        break;
        case KC_LOWER:
        if (record->event.pressed) {
          layer_on(_LOWER);
            } else {
          layer_off(_LOWER);
        }
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
          return false;
          break;
        case KC_RAISE:
        if (record->event.pressed) {
          layer_on(_RAISE);
           } else {
          layer_off(_RAISE);
        }
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
          return false;
          break;
        case KC_MACRO:
        if (record->event.pressed) {
            // マクロで入力
            user_macro();

        }
            return false;
            break;


      }
    

  // NICOLA親指シフト
  bool a = true;
  if (nicola_state()) {
    nicola_mode(keycode, record);
    a = process_nicola(keycode, record);
  }
  if (a == false) return false;
  // NICOLA親指シフト

    return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [1] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [2] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
  [3] = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_HUI, RGB_HUD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(RGB_SAI, RGB_SAD), },
};
#endif
