<?php
/**
 * @file
 * features_page_magazine.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_page_magazine_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
