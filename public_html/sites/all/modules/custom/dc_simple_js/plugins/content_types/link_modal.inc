<?php
/**
 * @file
 * Plugin create block with link that use AJAX for showing ctools modal window
 */

$plugin = array(
  'title' => t('Modal Link ctools plugin'),
  'description' => t('Show modal window'),
  'render callback' => 'link_modal_content_type_render',
  'category' => t('Custom panes'),
  'single' => TRUE,
);

function link_modal_content_type_render() {
  drupal_add_library('system', 'drupal.ajax');

  $block = new stdClass();
  $block->content = l(t('MODAL LINK'), 'ajax-links/ajax-modal', array('attributes' => array('class' => 'use-ajax')));

  return $block;
}
