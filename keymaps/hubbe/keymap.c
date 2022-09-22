#include QMK_KEYBOARD_H

// Layers
enum layers {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _SYSTEM,
};

// Custom keycode declarations
enum custom_keycodes {
    KC_PREV_WORD = SAFE_RANGE,  // ensure macro codes get unique numbers internally
    KC_NEXT_WORD,
    QWERTY,
    COLEMAK
};

// Custom keycode definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // navigation macros
        case KC_PREV_WORD:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));   // ctrl + left
            }
            return false;
        case KC_NEXT_WORD:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));  // ctrl + right
            }
            return false;
        // layout macros
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
    }
    return true;
}

// Layer shortcuts
#define RAISE MO(_RAISE)            // hold for _RAISE
#define LOWER MO(_LOWER)            // hold for _LOWER

// Mod-tap shortcuts, left hand
#define MT_A LGUI_T(KC_A)
#define MT_S LALT_T(KC_S)
#define MT_D LSFT_T(KC_D)
#define MT_F LCTL_T(KC_F)
#define MT_X RALT_T(KC_X)

// Mod-tap shortcuts, right hand
#define MT_J RCTL_T(KC_J)
#define MT_K RSFT_T(KC_K)
#define MT_L LALT_T(KC_L)
#define MT_SCLN RGUI_T(KC_SCLN)
#define MT_DOT RALT_T(KC_DOT)

// Macro shortcuts
#define PRV_WRD KC_PREV_WORD
#define NXT_WRD KC_NEXT_WORD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.   ___        ___   .-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |  | O |      | O |  |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|  | L |      | L |  |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  | E |      | E |  |   Y  |   U  |   I  |   O  |   P  |   =  |
 * |------+------+------+------+------+------|  |_D_|      |_D_|  |------+------+------+------+------+------|
 * |LCtrl |   A  |   S  |   D  |   F  |   G  |-------.    .-------|   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| Del  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_QWERTY] = LAYOUT(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
    KC_LCTRL, MT_A,    MT_S,    MT_D,    MT_F,    KC_G,                       KC_H,    MT_J,    MT_K,    MT_L,    MT_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,    MT_X,    KC_C,    KC_V,    KC_B,   KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, MT_DOT,  KC_SLSH, KC_BSLS,
                                KC_LALT, KC_LGUI, LOWER,  KC_SPC,   KC_ENT,   RAISE,   KC_BSPC, KC_DEL
),


/* COLEMAK-DH
 * ,-----------------------------------------.   ___        ___   .-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |  | O |      | O |  |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|  | L |      | L |  |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |  | E |      | E |  |   J  |   L  |   U  |   Y  |   ;  |   =  |
 * |------+------+------+------+------+------|  |_D_|      |_D_|  |------+------+------+------+------+------|
 * |LCtrl |   A  |   R  |   S  |   T  |   G  |-------.    .-------|   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| Del  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_COLEMAK] = LAYOUT(
    KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL,
    KC_LCTRL,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_LBRC,  KC_RBRC,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                 KC_LALT, KC_LGUI, LOWER,  KC_SPC,   KC_ENT,   RAISE,   KC_BSPC, KC_DEL
),

/*LOWER
 * ,-----------------------------------------.   ___        ___   .-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |  | O |      | O |  |   ^  |   &  |   *  |   (  |   )  |   _  |
 * |------+------+------+------+------+------|  | L |      | L |  |------+------+------+------+------+------|
 * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |  | E |      | E |  |      |      |      |      |   `  |   +  |
 * |------+------+------+------+------+------|  |_D_|      |_D_|  |------+------+------+------+------+------|
 * |LCtrl |  F6  |  F7  |  F8  |  F9  |  F10 |-------.    .-------|      |      |      |      |   :  |   "  |
 * |------+------+------+------+------+------|   {   |    |   }   |------+------+------+------+------+------|
 * |LShift|  F11 |  F12 |      |      |      |-------|    |-------|      |      |   <  |   >  |   ?  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| Del  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  KC_PLUS,
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COLN, KC_DQUO,
    _______, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_QUES, KC_PIPE,
                               _______, _______, _______, _______, _______, _______, _______, _______
),

/* RAISE
 * ,-----------------------------------------.   ___        ___   .-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  | O |      | O |  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|  | L |      | L |  |------+------+------+------+------+------|
 * | Tab  |      |      |      |      |      |  | E |      | E |  | PgUp |PrvWrd|  Up  |NxtWrd|      |  F12 |
 * |------+------+------+------+------+------|  |_D_|      |_D_|  |------+------+------+------+------+------|
 * |LCtrl | LGUI | LAlt |LShift|LCtrl |      |-------.    .-------| PgDn | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|      | Home |      | End  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| Del  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PGUP, PRV_WRD, KC_UP,   NXT_WRD, XXXXXXX, KC_F12,
    _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX, XXXXXXX,
                               _______, _______, _______, _______, _______, _______, _______, _______
),

/* SYSTEM
 * ,------------------------------------------.   ___        ___   .-----------------------------------------.
 * |QK_BOOT|      |      |      |      |PrnScr|  | O |      | O |  |      |NumLck|  /   |  *   |  -   |      |
 * |-------+------+------+------+------+------|  | L |      | L |  |------+------+------+------+------+------|
 * |NK_TOGG|QWERTY|      |      |      |      |  | E |      | E |  |      |  7   |  8   |  9   |  +   |  =   |
 * |-------+------+------+------+------+------|  |_D_|      |_D_|  |------+------+------+------+------+------|
 * |       |      |      |      |      |      |-------.    .-------|      |  4   |  5   |  6   |  +   |      |
 * |-------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |CapsLK |      |      |COLEMK|      |      |-------|    |-------|  0   |  1   |  2   |  3   |  .   |      |
 * `-----------------------------------------/       /     \       \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | / Space /       \ Enter \  |RAISE |BackSP| Del  |
 *                   |      |      |      |/       /         \ (KP)  \ |      |      |      |
 *                   `----------------------------'           '-------''--------------------'
 */

// QK_BOOT = Put the keyboard into bootloader mode for flashing
// NK_TOGG = Toggle USB N-key rollover (for better BIOS compatibility)

  [_SYSTEM] = LAYOUT(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,                   XXXXXXX, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,
  NK_TOGG, QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_PEQL,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX,
  KC_CAPS, XXXXXXX, XXXXXXX, COLEMAK, XXXXXXX, XXXXXXX, _______, _______, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PDOT, XXXXXXX,
                             _______, _______, _______, _______, KC_PENT, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // if _RAISE and _LOWER are both on, go to _SYSTEM layer
    state = update_tri_layer_state(state, _RAISE, _LOWER, _SYSTEM);
    return state;
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }
}

void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    oled_write_P(qmk_logo, false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR(" "), false);
    switch (get_highest_layer(layer_state)) {
        case _LOWER:
            oled_write_P(PSTR("LOW "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("HIGH"), false);
            break;
        case _SYSTEM:
            oled_write_P(PSTR("SYS "), false);
            break;
        default:
            // for some reason, get_highest_layer(layer_state) returns _QWERTY
            // even if the default layer has been changed with DH() or set_single_persistent_default_layer()
            // default_layer_state should update properly in all cases
            if (default_layer_state == 1) {
                oled_write_P(PSTR("QRTY"), false);
                break;
            }
            else if (default_layer_state == 2) {
                oled_write_P(PSTR("CLMK"), false);
                break;
            }
            else {
                oled_write_P(PSTR("????"), false);
                break;
            }
    }
}

void render_keylock_status(led_t led_state) {
    oled_write_ln_P(PSTR("Lock"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_ln_P(PSTR("S"), led_state.scroll_lock);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_kro_status(void) {
    oled_write_P(PSTR(" "), false);
    if (keymap_config.nkro) {
        oled_write_P(PSTR("NKRO"), true);
    }
    else {
        oled_write_P(PSTR("6KRO"), false);
    }
}

void render_status_main(void) {
    // Show keyboard layout
    render_default_layer_state();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show host keyboard led status
    render_keylock_status(host_keyboard_led_state());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show modifier status
    render_mod_status(get_mods() | get_oneshot_mods());  // or together mods and oneshots to get accurate status
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Render NKRO status
    render_kro_status();
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_logo();
  }
    return false;
}

#endif // OLED_ENABLE

