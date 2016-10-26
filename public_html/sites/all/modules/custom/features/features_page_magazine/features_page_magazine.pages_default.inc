<?php
/**
 * @file
 * features_page_magazine.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function features_page_magazine_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'magazines';
  $page->task = 'page';
  $page->admin_title = 'Magazines';
  $page->admin_description = '';
  $page->path = 'magazine';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Magazines',
    'name' => 'main-menu',
    'weight' => '-101010',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_magazines__panel';
  $handler->task = 'page';
  $handler->subtask = 'magazines';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Magazine',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'twocol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left' => NULL,
      'right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Magazines';
  $display->uuid = 'bbc8ad68-ee96-4c96-929a-715d2f8fbfbb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_magazines__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6ff1bb0d-ebc8-4b76-97e0-fc5c6c92ea6b';
  $pane->panel = 'left';
  $pane->type = 'block';
  $pane->subtype = 'views-magazines-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '6ff1bb0d-ebc8-4b76-97e0-fc5c6c92ea6b';
  $display->content['new-6ff1bb0d-ebc8-4b76-97e0-fc5c6c92ea6b'] = $pane;
  $display->panels['left'][0] = 'new-6ff1bb0d-ebc8-4b76-97e0-fc5c6c92ea6b';
  $pane = new stdClass();
  $pane->pid = 'new-e55bf4c3-5868-4856-8140-70c05c74ff8d';
  $pane->panel = 'right';
  $pane->type = 'block';
  $pane->subtype = 'views-magazines-block_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'e55bf4c3-5868-4856-8140-70c05c74ff8d';
  $display->content['new-e55bf4c3-5868-4856-8140-70c05c74ff8d'] = $pane;
  $display->panels['right'][0] = 'new-e55bf4c3-5868-4856-8140-70c05c74ff8d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['magazines'] = $page;

  return $pages;

}
