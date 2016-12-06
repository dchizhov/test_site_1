<?php
$plugin = array(
 'title' => t('Red Region Border'),
 'description' => t('Set red region border'),
 'render pane' => 'region_border_render_pane',
 'render region' => 'dc_contact_region_border_style_render_region',
 'hook theme' => array(
  'dc_contact_region_border' => array(
   'variables' => array('content' => NULL, 'style_attributes' => array()),
   'path' => drupal_get_path('module', 'dc_contact') . '/plugins/styles/region_border',
   'template' => 'dc_contact_region_border',
  ),
 ),
 'single' => TRUE,
);

/**
 * Render callback for a single pane
 */

function theme_region_border_render_pane($variables) {
 $output = '';

 if (!empty($variables['content']->content)) {
  $output = theme('panels_pane', array(
   'content' => $variables['content'],
   'pane' => $variables['pane'],
   'display' => $variables['display'],
  ));

  $output = theme('dc_contact_region_border', array('content' => $output));

  drupal_add_css(drupal_get_path('module', 'dc_contact') . '/plugins/styles/region_border/region_border.css');
 }

 return $output;
}


/**
 * Render callback for a region.
 */
function theme_dc_contact_region_border_style_render_region($variables) {
 $content = implode($variables['panes']);
 $output = theme('dc_contact_region_border', array('content' => $content));

 drupal_add_css(drupal_get_path('module', 'dc_contact') . '/plugins/styles/region_border/region_border.css');

 return $output;
}
