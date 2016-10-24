<?php

function dc_places_admin_settings ($form, &$form_state) {
 $form['setting_first'] = array(
  '#title' => 'Setting First',
  '#type' => 'textfield',
  '#default_value' => variable_get('setting_first'),
 );

 $form['setting_second'] = array(
  '#title' => 'Setting Second',
  '#type' => 'textfield',
  '#default_value' => variable_get('setting_second'),
 );
 
 return system_settings_form($form);
}