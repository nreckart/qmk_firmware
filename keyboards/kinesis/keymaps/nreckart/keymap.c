#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum kinesis_layers {
  _QWERTY,    // QWERTY
  _NUMBERS,   // Numbers & Symbols
  _FUNCTION,  // Function
  _NUMPAD,    // Numpad
  _ADJUST,    // Adjust layer (accessed via tri-layer feature)
};

enum kinesis_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  GAMING
};

//Tap Dance Declarations
enum {
  ADJ = 0,
  LBCB,
  RBCB,
  EQPL,
  PLEQ,
  MNUN,
  SLAS,
  GVTL,
  PPEQ,
  PMUN,
  PSPA,
  ESCP,
};

qk_tap_dance_action_t tap_dance_actions[] = {
//[ADJ]  = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_LAYER_finished, dance_LAYER_reset),  //  Double-tap to activate Adjust layer via oneshot layer
[ESCP] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS), // Esc on single-tap, toggle CAPS WORD on a double-tap
[LBCB] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),  // Left bracket on a single-tap, left brace on a double-tap
[RBCB] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),  // Right bracket on a single-tap, right brace on a double-tap
[EQPL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),   // Plus sign on a single-tap, equal sign on a double-tap
[PLEQ] = ACTION_TAP_DANCE_DOUBLE(KC_PLUS, KC_EQL),   // Equal sign on a single-tap, plus sign on a double-tap
[MNUN] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),  // Minus sign on a single-tap, underscore on a double-tap
[SLAS] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_ASTR),  // Slash in a single-tap, asterisk in a double-tap
[GVTL] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),   // Grave on a single-tap, tilde on a double-tap
[PPEQ] = ACTION_TAP_DANCE_DOUBLE(KC_PPLS, KC_EQL),   // Numpad plus sign on a single-tap, equal sign on a double-tap
[PMUN] = ACTION_TAP_DANCE_DOUBLE(KC_PMNS, KC_UNDS),  // Numpad minus sign on a single-tap, underscore on a double-tap
[PSPA] = ACTION_TAP_DANCE_DOUBLE(KC_PSLS, KC_PAST)   // Numpad slash on a single-tap, numpad asterisk on a double-tap
};

//Aliases for longer keycodes
#define ADJUST  MO(_ADJUST)
#define NUMPAD  TG(_NUMPAD)
#define SEMIFNC LT(_FUNCTION, KC_SCLN)
//#define BSPCFN  LT(_FUNCTION, KC_BSPC)
#define SPCSHFT LSFT_T(KC_SPC)
#define INSSHFT LSFT_T(KC_INS)
#define ENTNUM  LT(_NUMBERS, KC_ENT)
//#define DELNS   LT(_NUMBERS2, KC_DEL)
#define CTLESC  CTL_T(KC_ESC)
#define CTLBSPC CTL_T(KC_BSPC)
#define ALTRBRC ALT_T(KC_RBRC)
#define CTL_BSP LCTL(KC_BSPC)
#define CTL_A   LCTL(KC_A)
#define CTL_C   LCTL(KC_C)
#define CTL_V   LCTL(KC_V)
#define CTL_X   LCTL(KC_X)
#define CTL_Z   LCTL(KC_Z)
#define CTL_Y   LCTL(KC_Y)
#define CA_TAB  LCA(KC_TAB)
#define HYPER   ALL_T(KC_NO)
#define TD_ESCP TD(ESCP)
#define TD_ADJ  TD(ADJ)
#define TD_LBCB TD(LBCB)
#define TD_RBCB TD(RBCB)
#define TD_EQPL TD(EQPL)
#define TD_PLEQ TD(PLEQ)
#define TD_MNUN TD(MNUN)
#define TD_SLAS TD(SLAS)
#define TD_GVTL TD(GVTL)
#define TD_PPEQ TD(PPEQ)
#define TD_PMUN TD(PMUN)
#define TD_PSPA TD(PSPA)
#define WS_UP   LCTL(LGUI(KC_UP))
#define WS_DWN  LCTL(LGUI(KC_DOWN))
#define NKROTG  MAGIC_TOGGLE_NKRO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
QWERTY
(Keys separated by "/" tap for first, hold for second; uses Space Cadet Shifts)
,--------------------------------------------------------------.                                     ,--------------------------------------------------------------.
|  ESC |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |                                     |  F9  |  F10 |  F11 |  F12 |PrtScr|ScrLck| Pause|Numpad|Adjust|
`--------------------------------------------------------------'                                     `--------------------------------------------------------------'
,------------------------------------------------------.                                                     ,------------------------------------------------------.
|    =    |    1   |    2   |    3   |    4   |    5   |                                                     |    6   |    7   |    8   |    9   |    0   |    -    |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
|   Tab   |    Q   |    W   |    E   |    R   |    T   |                                                     |    Y   |    U   |    I   |    O   |    P   |    \    |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
| ESC/Caps|    A   |    S   |    D   |    F   |    G   |                                                     |    H   |    J   |    K   |    L   |    ;   |    '    |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
| Ins/Shft|    Z   |    X   |    C   |    V   |    B   |                                                     |    N   |    M   |    ,   |    .   |    /   | SC Shift|
`---------+--------+--------+--------+--------+--------'                                                     `--------+--------+--------+--------+--------+---------'
          |   `    |   Ins  |    [   |Alt / ] |                                                                       |  Tab   |  Down  |   Up   |  Right |
          `-----------------------------------'                                                                       `-----------------------------------'
	                                                   ,-----------------.                 ,-----------------.
	                                                   | Delete |  Hyper |                 |  RAlt  |  RCtl  |
	                                          ,--------+--------+--------|                 |--------+--------+--------.
	                                          |  Bspc  |        |  Left  |                 |   Up   | Enter  |  Space |
	                                          |    /   |   GUI  |--------|                 |--------|    /   |    /   |
	                                          |   Fn   |        |  Right |                 |  Down  | Number |  Shift |
	                                          `--------------------------'                 `--------------------------'
*/
[_QWERTY] = LAYOUT_pretty(
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SCRL, KC_PAUS, NUMPAD,  ADJUST,
  KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  TD_ESCP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                          KC_H,    KC_J,    KC_K,    KC_L,    SEMIFNC, KC_QUOT,
  INSSHFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SC_RSPC,
           KC_GRV,  KC_INS,  KC_LBRC, ALTRBRC,                                                                         KC_TAB,  KC_DOWN, KC_UP,   KC_RGHT,
                                                        KC_DEL,  HYPER,                     KC_RALT, KC_RCTL,
                                                                 KC_LEFT,                   KC_UP,
                                          CTLBSPC,   KC_LGUI,   KC_RIGHT,                   KC_DOWN,  ENTNUM,   SPCSHFT
),

/*
Numbers/Symbols layer
(Multiple characters: single-tap for first, double-tap for second)
,--------------------------------------------------------------.                                     ,--------------------------------------------------------------.
|      |      |      |      |      |      |      |      |      |                                     |      |      |      |      | Mute | V Dn | V Up |      |      |
`--------------------------------------------------------------'                                     `--------------------------------------------------------------'
,------------------------------------------------------.                                                     ,------------------------------------------------------.
|   F12   |   F1   |   F2   |   F3   |   F4   |   F5   |                                                     |   F6   |   F7   |   F8   |   F9   |   F10  |   F11   |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
|         |    =   |    {   |    }   |    -   |    +   |                                                     |    ^   |    &   |    *   |    (   |    )   |         |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
|         |    1   |    2   |    3   |    4   |    5   |                                                     |    6   |    7   |    8   |    9   |    0   |         |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
|         |    @   |    [   |    ]   |    (   |    )   |                                                     |   ` ~  |   [ {  |   ] }  |        |        |         |
`---------+--------+--------+--------+--------+--------'                                                     `--------+--------+--------+--------+--------+---------'
          |    (   |    )   |   [ {  |   ] }  |                                                                       |        |        |        |        |
          `-----------------------------------'                                                                       `-----------------------------------'
	                                                   ,-----------------.                 ,-----------------.
	                                                   |        |        |                 |        |        |
	                                          ,--------+--------+--------|                 |--------+--------+--------.
	                                          |   Ctrl  |        |        |                 |        |        |        |
	                                          |    +    |        |--------|                 |--------|        |        |
	                                          |   Bksp  |        |        |                 |        |        |        |
	                                          `--------------------------'                 `--------------------------'
*/
[_NUMBERS] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, QK_BOOT,
  KC_F12,  KC_F1,   KC_F2,   KC_F4,   KC_F4,   KC_F5,                                                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_EQL,  KC_LCBR, KC_RCBR, KC_MINS, KC_PLUS,                                                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F11,
  CAPS_WORD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_F12,
  _______, KC_AT,   KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN,                                                       TD_GVTL, TD_LBCB, TD_RBCB, _______, _______, _______,
           KC_LPRN, KC_RPRN, KC_LPRN, KC_RPRN,                                                                         _______, _______, _______, _______,
                                                        _______, _______,                   _______, _______,
                                                                  WS_UP ,                   _______,
                                               CTL_BSP, _______, WS_DWN ,                   _______, _______, _______
),
/*
Function layer
,--------------------------------------------------------------.                                     ,--------------------------------------------------------------.
|      |      |      |      |      |      |      |      |      |                                     |      |      |      |      |      |      |      |      |      |
`--------------------------------------------------------------'                                     `--------------------------------------------------------------'
,------------------------------------------------------.                                                     ,------------------------------------------------------.
|   F12   |   F1   |   F2   |   F3   |   F4   |   F5   |                                                     |   F6   |   F7   |   F8   |   F9   |   F10  |   F11   |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
|         |        | WhLeft |  M Up  |  WhRgt |  WhUp  |                                                     |  PgUp  |  Home  |   Up   |  End   |        |         |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
|         | Ctrl+A | M Left | M Down | M Rght |  WhDn  |                                                     |  PgDn  |  Left  |  Down  |  Right |  Home  |         |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
|         | Ctrl+Z | Ctrl+X | Ctrl+C | Ctrl+V |  Bspc  |                                                     |        |  L Clk |  M Clk |  R Clk |   End  |         |
`---------+--------+--------+--------+--------+--------'                                                     `--------+--------+--------+--------+--------+---------'
          |        |        |        |        |                                                                       |  Prev  |  Play  |  Next  |  Stop  |
          `-----------------------------------'                                                                       `-----------------------------------'
	                                                   ,-----------------.                 ,-----------------.
	                                                   |        |        |                 |        |        |
	                                          ,--------+--------+--------|                 |--------+--------+--------.
	                                          |        |        |        |                 |        |        |        |
	                                          |        |        |--------|                 |--------|        |        |
	                                          |        |        |        |                 |        |        |        |
	                                          `--------------------------'                 `--------------------------'
*/
[_FUNCTION] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                                         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                                                       KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_END, _______,
  _______, CTL_A,   KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                                                        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  _______, CTL_Z,   CTL_X,   CTL_C,   CTL_V,   KC_BSPC,                                                       _______, KC_BTN1, KC_BTN3, KC_BTN2, _______,  _______,
           _______, _______, _______, _______,                                                                         KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP,
                                                        _______, _______,                   _______, _______,
                                                                 _______,                   _______,
                                               _______, _______, _______,                   _______, _______, _______
),
/*
Numpad layer
(Left side duplicates layout from the Numbers layer, just with numpad output; right side layout close to PC numpad layout)
,--------------------------------------------------------------.                                     ,--------------------------------------------------------------.
|      |      |      |      |      |      |      |      |      |                                     |      |      |      |      |      |      |      |      |      |
`--------------------------------------------------------------'                                     `--------------------------------------------------------------'
,------------------------------------------------------.                                                     ,------------------------------------------------------.
|         | NumLock|        |        |        |        |                                                     |   Tab  | NumLock|  KP /  |  KP *  |  KP -  |         |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
|         |  KP 6  |  KP 7  |  KP 8  |  KP 9  |  KP 0  |                                                     |        |  KP 7  |  KP 8  |  KP 9  |  KP +  |         |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
|         |  KP 1  |  KP 2  |  KP 3  |  KP 4  |  KP 5  |                                                     |        |  KP 4  |  KP 5  |  KP 6  |   =    |         |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
|         |        |  KP .  | KP/KP* |  KP- _ |  KP+ = |                                                     |        |  KP 1  |  KP 2  |  KP 3  | KP Ent |         |
`---------+--------+--------+--------+--------+--------'                                                     `--------+--------+--------+--------+--------+---------'
          |    (   |    )   |   [ {  |   ] }  |                                                                       |        |  KP 0  |  KP .  | KP Ent |
          `-----------------------------------'                                                                       `-----------------------------------'
	                                                   ,-----------------.                 ,-----------------.
	                                                   |        |        |                 |        |        |
	                                          ,--------+--------+--------|                 |--------+--------+--------.
	                                          |        |        |        |                 |        |        |        |
	                                          |        |        |--------|                 |--------|        |        |
	                                          |        |        |        |                 |        |        |        |
	                                          `--------------------------'                 `--------------------------'
*/
[_NUMPAD] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_NUM,  _______, _______, _______, _______,                                                       KC_TAB,  KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, _______,
  _______, KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,                                                         _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
  _______, KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,                                                         _______, KC_P4,   KC_P5,   KC_P6,   KC_EQL,  _______,
  _______, _______, KC_PDOT, TD_PSPA, TD_MNUN, TD_PPEQ,                                                       _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
           KC_LPRN, KC_RPRN, TD_LBCB, TD_RBCB,                                                                         _______, KC_P0,   KC_PDOT, KC_PENT,
                                                        _______, _______,                   _______, _______,
                                                                 _______,                   _______,
                                               _______, _______, _______,                   _______, _______, _______
),
/*
Adjust layer
(Press and hold Adjust key on the function row or Enter/Number + Delete/Number2 to access; Numpad and NKRO are on toggle)
,--------------------------------------------------------------.                                     ,--------------------------------------------------------------.
|      |      |      |      |      |      |      |      |      |                                     |      |      |      |      |      |      |      |      |      |
`--------------------------------------------------------------'                                     `--------------------------------------------------------------'
,------------------------------------------------------.                                                     ,------------------------------------------------------.
|         |        |        |        |        |        |                                                     | Numpad |        |        |        |        |  QK_BOOT  |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
|         |        |        |        |        |        |                                                     |        |        |        |        |        |         |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
|         |        |        |        |        |        |                                                     |        |  NKRO  |        |        |        |         |
|---------+--------+--------+--------+--------+--------|                                                     |--------+--------+--------+--------+--------+---------|
|         |        |        |        |        |        |                                                     |        |        |        |        |        |         |
`---------+--------+--------+--------+--------+--------'                                                     `--------+--------+--------+--------+--------+---------'
          |        |        |        |        |                                                                       |        |        |        |        |
          `-----------------------------------'                                                                       `-----------------------------------'
	                                                   ,-----------------.                 ,-----------------.
	                                                   |        |        |                 |        |        |
	                                          ,--------+--------+--------|                 |--------+--------+--------.
	                                          |        |        |        |                 |        |        |        |
	                                          |        |        |--------|                 |--------|        |        |
	                                          |        |        |        |                 |        |        |        |
	                                          `--------------------------'                 `--------------------------'
*/
[_ADJUST] = LAYOUT_pretty(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______,  _______, _______,  _______,                                                       NUMPAD,  _______, _______, _______, _______, QK_BOOT,
  _______, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                                       _______, NKROTG , _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                                                       _______, _______, _______, _______, _______, _______,
           _______, _______, _______, _______,                                                                         _______, _______, _______, _______,
                                                        _______, _______,                   _______, _______,
                                                                 _______,                   _______,
                                               _______, _______, _______,                   _______, _______, _______
)};


