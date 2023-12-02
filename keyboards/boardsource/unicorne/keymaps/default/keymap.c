#include QMK_KEYBOARD_H

#define BSPC_NAV LT(1, KC_BSPC)
#define SPC_NUM LT(2, KC_SPC)
#define DEL_FUN1 LT(3, KC_DEL)
#define TAB_FUN2 LT(4, KC_TAB)

enum layers {
    _MAIN,
    _NAV,
    _NUM,
    _FUN1,
    _FUN2
};

// For ComboMods
enum combos {
    COMBO_LCTL_L,
    COMBO_LGUI_L,
    COMBO_LALT_L,
    COMBO_RALT_L,
    COMBO_LCTL_R,
    COMBO_LGUI_R,
    COMBO_LALT_R,
    COMBO_RALT_R,
    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos
const uint16_t PROGMEM fd_combo[]   = {KC_F, KC_R, COMBO_END};
const uint16_t PROGMEM de_combo[]   = {KC_D, KC_E, COMBO_END};
const uint16_t PROGMEM sw_combo[]   = {KC_S, KC_W, COMBO_END};
const uint16_t PROGMEM ju_combo[]   = {KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM ki_combo[]   = {KC_K, KC_I, COMBO_END};
const uint16_t PROGMEM lo_combo[]   = {KC_L, KC_O, COMBO_END};
const uint16_t PROGMEM colp_combo[] = {KC_SCLN, KC_P, COMBO_END};
const uint16_t PROGMEM az_combo[]   = {KC_A, KC_Z, COMBO_END};

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    [COMBO_LCTL_L] = COMBO(fd_combo,   KC_LCTL),
    [COMBO_LGUI_L] = COMBO(de_combo,   KC_LGUI),
    [COMBO_LALT_L] = COMBO(sw_combo,   KC_LALT),
    [COMBO_RALT_L] = COMBO(az_combo,   KC_RALT),
    [COMBO_LCTL_R] = COMBO(ju_combo,   KC_LCTL),
    [COMBO_LGUI_R] = COMBO(ki_combo,   KC_LGUI),
    [COMBO_LALT_R] = COMBO(lo_combo,   KC_LALT),
    [COMBO_RALT_R] = COMBO(colp_combo, KC_RALT)
};

//For ModTap
// Add case if you want to add a unique tapping term to a specific key
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case KC_GRV:
        //     return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_MAIN] = LAYOUT_split_3x6_3
    (
                KC_EQL,  KC_Q, KC_W, KC_E,   KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSLS,
                KC_MINS, KC_A, KC_S, KC_D,   KC_F,    KC_G,           KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
                KC_ESC,  KC_Z, KC_X, KC_C,   KC_V,    KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_ENT,
                                     DEL_FUN1, KC_LSFT, BSPC_NAV,       SPC_NUM, KC_LSFT, TAB_FUN2
    ),
	[_NAV] = LAYOUT_split_3x6_3
    (
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_LBRC, KC_RBRC,
                XXXXXXX, KC_RALT, KC_LALT, KC_LGUI, KC_LCTL, XXXXXXX,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_LPRN, KC_RPRN,
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_LCBR, KC_RCBR,
                                           XXXXXXX, XXXXXXX, XXXXXXX,   KC_SPC,  KC_LSFT, KC_TAB
    ),
    [_NUM] = LAYOUT_split_3x6_3
    (
                KC_EQL,  KC_PLUS, KC_7, KC_8,   KC_9,    KC_GRV,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                KC_MINS, KC_0,    KC_4, KC_5,   KC_6,    KC_DOT,       XXXXXXX, KC_LCTL, KC_LGUI, KC_LALT, KC_RALT, XXXXXXX,
                KC_SLSH, KC_ASTR, KC_1, KC_2,   KC_3,    KC_TILD,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        KC_DEL, KC_LSFT, KC_BSPC,      XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_FUN1] = LAYOUT_split_3x6_3
    (
                XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_INS,  KC_F9, KC_F10, KC_F11, KC_F12, KC_SCRL,
                XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_CAPS, KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_NUM,
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_PSCR, KC_F1, KC_F2,  KC_F3,  KC_F4,  XXXXXXX,
                                           QK_BOOT, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_FUN2] = LAYOUT_split_3x6_3
    (
                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
                XXXXXXX, RGB_VAI, RGB_HUI, RGB_SAI, RGB_MOD,  RGB_TOG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
                XXXXXXX, RGB_VAD, RGB_HUD, RGB_SAD, RGB_RMOD, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                           XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, QK_BOOT
    )
};
