<?php

$plugin = array(
 'title' => t('Example content type plugin'),
 'description' => t('The output a custom text.'),
 'render callback' => 'example_text_content_type_render',
 'category' => t('Custom panes'),
 'single' => TRUE,
);

/**
 * Render callback for the content type.
 */
function example_text_content_type_render($subtype, $conf, $args, $context) {
 $block = new stdClass();
 $block->content = drupal_get_form('dc_contact_form');

 return $block;
}
