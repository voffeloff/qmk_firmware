#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYM1 1 // symbols
#define SYM2 2 // symbols 2
#define MDIA 3 // media
#define HYPE 4 // media

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ` ~    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | Alt  |           | Alt  |   Y  |   U  |   I  |   O  |   P  |   -    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc/Ctl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | Ent/Cmd|
 * |--------+------+------+------+------+------| Ctrl |           | Ctrl |------+------+------+------+------+--------|
 * | Shift  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,   |  .   |   /  | Hyper  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   /  |  \   |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space| BSpc |------|       |------| Sym1   | Shift|
 *                                 |      |      | Sym2 |       | Media|        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // laltayer 0 : default
        // left hand
        KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_NO,
        KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_LALT,
        CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,
        KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_LCTL,
        KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,

                         KC_NO,           KC_NO,
                                          KC_NO, 
        KC_SPC,          KC_BSPC,         LT(SYM2, KC_NO),

        // right hand
        KC_NO,          KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_NO,
        KC_RALT,        KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_MINS,
                        KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, GUI_T(KC_ENT),
        KC_RCTL,        KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, LT(HYPE, KC_NO),
                                 KC_SLSH, KC_BSLS, KC_NO,  KC_NO,   KC_NO,

                         KC_NO,           KC_NO,
                         KC_NO,
        LT(MDIA, KC_NO), LT(SYM1, KC_NO), KC_RSFT
),

/* Keymap 1: Symbol Layer 1
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   #  |   {  |   }  |      |      |           |      |      |  <   |  >   |  =   |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   @  |   $  |   (  |   )  |   `  |------|           |------|   |  |  "   |  '   |  \   |  ?   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |      |      |           |      |      |      |      |      |  \   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYM1] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
       KC_TRNS,KC_EXLM,KC_HASH,KC_LCBR,KC_RCBR,KC_NO,KC_TRNS,
       KC_TRNS,KC_AT,  KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LABK, KC_RABK, KC_EQL, KC_NO,  KC_F12,
                KC_PIPE, KC_DQT, KC_QUOT, KC_BSLS, KC_QUES,   KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Symbol Layer 2
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  Up  |      |      |      |           |      |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down | Right|      |------|           |------|      |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |   0  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS 2
[SYM2] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_UP,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_LEFT,KC_DOWN,KC_RGHT,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_7,   KC_8,    KC_9,    KC_TRNS, KC_TRNS,
                KC_TRNS, KC_4,   KC_5,    KC_6,    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_1,   KC_2,    KC_3,    KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_TRNS,  KC_0,    KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 3: Media layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | Vol+ |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Prev | Vol- | Next |      |------|           |------|      | Play |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | Mute |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA
[MDIA] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_VOLU,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_MPRV,KC_VOLD,KC_MNXT,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
                KC_TRNS, KC_MPLY,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MUTE,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

// HYPER
[HYPE] = KEYMAP(
       // left hand
        HYPR(KC_GRV),HYPR(KC_1),HYPR(KC_2),HYPR(KC_3),HYPR(KC_4),HYPR(KC_5),HYPR(KC_NO),
        KC_TRNS,HYPR(KC_Q),HYPR(KC_W),HYPR(KC_UP),HYPR(KC_R),HYPR(KC_T),KC_TRNS,
        KC_TRNS,HYPR(KC_A),HYPR(KC_LEFT),HYPR(KC_DOWN),HYPR(KC_RGHT),HYPR(KC_G),
        KC_TRNS,HYPR(KC_Z),HYPR(KC_X),HYPR(KC_C),HYPR(KC_V),HYPR(KC_B),KC_TRNS,
        KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,        HYPR(KC_6),    HYPR(KC_7),    HYPR(KC_8),    HYPR(KC_9),   HYPR(KC_0),    KC_TRNS,
       KC_TRNS,        HYPR(KC_Y),    HYPR(KC_U),    HYPR(KC_I),    HYPR(KC_O),   HYPR(KC_P),    HYPR(KC_MINS),
                       HYPR(KC_H),    HYPR(KC_J),    HYPR(KC_K),    HYPR(KC_L),   HYPR(KC_SCLN), KC_TRNS,
       KC_TRNS,        HYPR(KC_N),    HYPR(KC_M),    HYPR(KC_COMM), HYPR(KC_DOT), HYPR(KC_SLSH), KC_TRNS,
       HYPR(KC_SLSH), HYPR(KC_BSLS), KC_TRNS,  KC_TRNS,   KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
};

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

    switch (layer) {
        case SYM1:
            break;
        case SYM2:
            break;
        case MDIA:
            break;
        case HYPE:
            break;
        default:
            // none
            break;
    }

};
