#include QMK_KEYBOARD_H

void dance_123_finished(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_1);
            break;
        case 2:
            register_code(KC_2);
            break;
        case 3:
            register_code(KC_3);
            break;
    }
}

void dance_123_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            unregister_code(KC_1);
            break;
        case 2:
            unregister_code(KC_2);
            break;
        case 3:
            unregister_code(KC_3);
            break;
    }
}

enum {
    TD_123,
    TD_DRAW_MODE,
    TD_EXTRUDE_INSET,
    TD_TOPOLOGY,
};

qk_tap_dance_action_t tap_dance_actions[] = {
        [TD_123] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_123_finished, dance_123_reset),
        [TD_DRAW_MODE] = ACTION_TAP_DANCE_DOUBLE(KC_Z, S(KC_Z)),
        [TD_EXTRUDE_INSET] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_I),
        [TD_TOPOLOGY] = ACTION_TAP_DANCE_DOUBLE(C(KC_R), KC_K),
};

#define _OBJECT 0
#define _EDIT 1
#define _NUMPAD 2
#define _SETTINGS 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_OBJECT] = LAYOUT_main(
        TO(_EDIT),   KC_KP_7,   C(KC_KP_1),
        C(KC_KP_3),   KC_KP_0,   KC_KP_3,
        KC_KP_1,   C(KC_KP_7),   TO(_EDIT),
        LT(_SETTINGS, KC_TAB),   KC_G,   KC_R,   KC_S,   KC_A,   S(KC_A),   KC_M,   S(KC_D),   TD(TD_DRAW_MODE),   KC_F12,   KC_KP_5,
        KC_LSFT,   KC_LCTL,   KC_LALT,   KC_NO,   MO(_NUMPAD),   KC_NO,   KC_W,   KC_X,   KC_Y,   KC_Z
    ),
    [_EDIT] = LAYOUT_main(
        TO(_OBJECT),   KC_KP_7,   C(KC_KP_1),
        C(KC_KP_3),   KC_KP_0,   KC_KP_3,
        KC_KP_1,   C(KC_KP_7),   TO(_OBJECT),
        LT(_SETTINGS, KC_TAB),   KC_G,   KC_R,   KC_S,   KC_A,   TD(TD_EXTRUDE_INSET),   TD(TD_TOPOLOGY),   S(KC_D),   TD(TD_DRAW_MODE),   KC_NO,   KC_KP_5,
        KC_LSFT,   KC_LCTL,   KC_LALT,   TD(TD_123),   MO(_NUMPAD),   KC_NO,   KC_W,   KC_X,   KC_Y,   KC_Z
    ),
    [_NUMPAD] = LAYOUT_main(
        KC_KP_7,   KC_KP_8,   KC_KP_9,
        KC_KP_4,   KC_KP_5,   KC_KP_6,
        KC_KP_1,   KC_KP_2,   KC_KP_3,
        LT(_SETTINGS, KC_TAB),   KC_KP_0,   KC_KP_DOT,   KC_KP_ENTER,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_KP_PLUS,   KC_KP_PMNS,   KC_KP_PAST,   KC_KP_PSLS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
    [_SETTINGS] = LAYOUT_main(
        KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    )
};
