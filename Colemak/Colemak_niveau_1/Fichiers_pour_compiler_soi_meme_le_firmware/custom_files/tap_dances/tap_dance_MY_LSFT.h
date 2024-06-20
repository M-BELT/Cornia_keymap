// ================= SHIFT TAPDANCE ================
static tap sft_tap_state = {
  .is_press_action = true,
  .state = 0
};
// -------------------------------------------------------
void sft_finished (tap_dance_state_t *state, void *user_data);
void sft_reset (tap_dance_state_t *state, void *user_data);
// -------------------------------------------------------
//Functions that control what our tap dance key does
void sft_finished (tap_dance_state_t *state, void *user_data) {
  sft_tap_state.state = ma_cur_dance(state);
  switch (sft_tap_state.state) {
    // case SINGLE_TAP: 
    //   tap_code(KC_QUOT);
    //   break;
    case SINGLE_TAP: 
      //check to see if the layer is already set
      if (layer_state_is(_CAPS_LOCK)) {
        //if already set, then switch it off
        layer_off(_CAPS_LOCK);
      } else { 
        //if not already set, then switch the layer on
        layer_on(_CAPS_LOCK);
      }
      break;    
    case SINGLE_HOLD: 
      layer_on(_SFT_COLEMAK_FR);
      // TODO moi
      register_mods(MOD_BIT_LSHIFT);
      // add_mods(MOD_BIT_LSHIFT);
      // tap_code(KC_PSCR);
      // TODO moi
      break;
    // case DOUBLE_TAP: 
    //   //check to see if the layer is already set
    //   if (layer_state_is(_CAPS_LOCK)) {
    //     //if already set, then switch it off
    //     layer_off(_CAPS_LOCK);
    //   } else { 
    //     //if not already set, then switch the layer on
    //     layer_on(_CAPS_LOCK);
    //   }
    //   break;
    // case DOUBLE_HOLD:
    //   tap_code(KC_M);
  }
}
// -------------------------------------------------------
void sft_reset (tap_dance_state_t *state, void *user_data) {
  //if the key was held down and now is released then switch off the layer
  if (sft_tap_state.state==SINGLE_HOLD) {
    layer_off(_SFT_COLEMAK_FR);
    unregister_mods(MOD_BIT_LSHIFT);
  }
  sft_tap_state.state = 0;
}
// ================= END SHIFT TAPDANCE ================