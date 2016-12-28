<?php
/**
 * @file
 * Plugin create block with link that use AJAX for alert
 */

$plugin = array(
  'title' => t('Ajax Link plugin'),
  'description' => t('Sending ajax query that call alert.'),
  'render callback' => 'link_ajax_content_type_render',
  'category' => t('Custom panes'),
  'single' => TRUE,
);

function link_ajax_content_type_render() {
  drupal_add_library('system', 'drupal.ajax');

  $block = new stdClass();
  $block->content = l(t('AJAX LINK'), 'ajax-links/ajax', array('attributes' => array('class' => 'use-ajax')));

  return $block;
}
