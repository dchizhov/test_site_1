<?php

$plugin = array(
 'title' => t('Even minutes'),
 'description' => t('Show content at even minutes'),
 'required context' => array(new ctools_context_required(t('User'), 'user')),
 'callback' => 'access_example_callback',
);

function access_example_callback() {
 $minute = format_date(REQUEST_TIME, 'custom', 'i');

 if (($minute % 2 == 0)) {
  return TRUE;
 }

 return FALSE;
}
