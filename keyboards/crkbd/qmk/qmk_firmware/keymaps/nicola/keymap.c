#include QMK_KEYBOARD_H

// NICOLA親指シフト
#include "nicola.h"
NGKEYS nicola_keys;
// NICOLA親指シフト

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum keymap_layers
{
  _QWERTY,
  // NICOLA親指シフト
  _NICOLA, // NICOLA親指シフト入力レイヤー
  // NICOLA親指シフト
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes
{
  KC_QWERTY = NG_SAFE_RANGE,
  KC_EISU,
  KC_LOWER,
  KC_RAISE,
  KC_ADJUST,
  KC_KANA2,
  KC_MACRO,
//  RGBRST,
};

// レイヤーキータップ、長押し判定
static bool lower_pressed = false;
static bool raise_pressed = false;
static bool ctrl_pressed = false;
static bool rsft_pressed = false;
static uint8_t modifier = 0; // 押しているmodifierキーの数

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define _____ KC_TRNS
#define XXXXX KC_NO
#define KC_RESET RESET
#define KC_RST RESET
#define KC_ALTDN ALT_T(KC_DOWN)
// #define KC_CTLTB CTL_T(KC_TAB)
#define KC_GUIUP GUI_T(KC_UP)
// #define KC_SFMN SFT_T(KC_INT1)

#define KC_C(A) C(KC_##A)
#define KC_S(A) S(KC_##A)
#define KC_G(A) G(KC_##A)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_S(8),    KC_S(9),    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LEFT,   KC_RIGHT,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                         KC_GUIUP,KC_LOWER, KC_PENT,     KC_SPC,KC_RAISE, KC_ALTDN
                              //`----------------------------------'  `------------------------------------'

  ),
  
// NICOLA親指シフト
  // デフォルトレイヤーに関係なくQWERTYで
  [_NICOLA] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        _____,    NG_Q,    NG_W,    NG_E,    NG_R,    NG_T,   NG_LU,      NG_RU,    NG_Y,    NG_U,    NG_I,    NG_O,    NG_P, KC_BSPC,
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
        _____,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_S(8),    KC_S(9),    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _____,    KC_4,    KC_5,    KC_6,KC_MACRO,   KC_UP,   _____,      _____, KC_LBRC,    KC_4,    KC_5,    KC_6,KC_S(QUOT),KC_S(SCLN),
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        _____,    KC_7,    KC_8,    KC_9,    KC_0, KC_DOWN,                         KC_0,    KC_1,    KC_2,    KC_3, KC_SLSH, KC_MINS,

  //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.  ,--------------------------------------------------------------.
        _____, KC_EXLM, KC_LBRC, KC_HASH,  KC_DLR, KC_PERC, KC_S(2),    KC_S(7),  KC_EQL, KC_AMPR,KC_S(QUOT),KC_S(8),KC_S(9),  KC_DEL, // この行はこれでよい。
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        _____, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_UP,   _____,      _____, KC_MINS,  KC_EQL, KC_INT1, KC_RBRC, KC_BSLS,KC_S(LBRC),
  //|--------+--------+--------+--------+--------+--------+--------'  `--------+--------+--------+--------+--------+--------+--------|
        _____, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOWN,                      KC_UNDS, KC_PLUS,KC_S(INT3),KC_RCBR,KC_PIPE,KC_S(EQL),
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

void matrix_init_user(void)
{
  // NICOLA親指シフト
  set_nicola(_NICOLA);
  // NICOLA親指シフト
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3)
{
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2))
  {
    layer_on(layer3);
  }
  else
  {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{

  switch (keycode)
  {
  case KC_EISU:
    if (record->event.pressed)
    {
      // NICOLA親指シフト
      nicola_off();
      // NICOLA親指シフト
    }
    return false;
    break;
  case KC_KANA2:
    if (record->event.pressed)
    {
      // NICOLA親指シフト
      nicola_on();
      // NICOLA親指シフト
    }
    return false;
    break;
    
  case KC_ADJUST:
    if (record->event.pressed)
    {
      layer_on(_ADJUST);
    }
    else
    {
      layer_off(_ADJUST);
    }
    return false;
    break;
    
  case KC_LOWER:
    if (record->event.pressed)
    {
      lower_pressed = true;
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    else
    {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      if (lower_pressed)
      {
        nicola_off();
      }
      lower_pressed = false;
    }
    return false;
    break;

  case KC_RAISE:
    if (record->event.pressed)
    {
      raise_pressed = true;
      layer_on(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    else
    {
      layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      if (raise_pressed)
      {
        nicola_on();
      }
      raise_pressed = false;
    }
    return false;
    break;

  case KC_LCTL:
    if (record->event.pressed)
    {
      ctrl_pressed = true;
      register_code(KC_LCTL);
      modifier = get_n_modifier(); // `n_modifier`の値を取得
      set_n_modifier(modifier + 1);        // `n_modifier`を更新
    }
    else
    {
      unregister_code(KC_LCTL);
      modifier = get_n_modifier(); // `n_modifier`の値を取得
      set_n_modifier(modifier - 1);        // `n_modifier`を更新
      if (ctrl_pressed)
      {
        register_code(KC_TAB);
        unregister_code(KC_TAB);
      }
      ctrl_pressed = false;
    }
    return false;
    break;
 
  case KC_RSFT:
    if (record->event.pressed)
    {
      rsft_pressed = true;
      register_code(KC_RSFT);
      modifier = get_n_modifier(); // `n_modifier`の値を取得
      set_n_modifier(modifier + 1);        // `n_modifier`を更新
    }
    else
    {
      unregister_code(KC_RSFT);
      modifier = get_n_modifier(); // `n_modifier`の値を取得
      set_n_modifier(modifier - 1);        // `n_modifier`を更新
      if (rsft_pressed)
      {
        register_code(KC_INT1);
        unregister_code(KC_INT1);
      }
      rsft_pressed = false;
    }
    return false;
    break;

    
    
  case KC_MACRO:
    if (record->event.pressed)
    {
      // マクロで入力
      tap_code(KC_INT5); // Win
      send_string("xxxxxx");
    }
    return false;
    break;

  default:
    if (record->event.pressed)
    {
      // reset the flag
      lower_pressed = false;
      raise_pressed = false;
      ctrl_pressed = false;
      rsft_pressed = false;
    }
    break;
  }

  // NICOLA親指シフト
  bool a = true;
  if (nicola_state())
  {
    nicola_mode(keycode, record);
    a = process_nicola(keycode, record);
  }
  if (a == false)
    return false;
  // NICOLA親指シフト

  return true;
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [1] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [2] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [3] = {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
};
#endif
