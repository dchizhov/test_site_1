<?php
$plugin = array(
 'title' => t('YouTube Video'),
 'description' => t('Show YouTube video.'),
 'render callback' => 'youtube_content_type_render',
 'edit form' => 'youtube_content_type_edit_form',
 'category' => t('Custom panes'),
 'single' => TRUE,
);

/**
 * Ctools Edit form
 */
function youtube_content_type_edit_form($form, &$form_state) {
 $conf = $form_state['conf'];

 $form['link'] = array(
  '#type' => 'textfield',
  '#title' => t('Link on Youtube'),
  '#default_value' => !empty($conf['text']) ? $conf['text'] : '',
 );

 return $form;
}

/**
 * Submit callback for the ctools Edit form.
 */
function youtube_content_type_edit_form_submit($form, &$form_state) {
 $form_state['conf'] = array(
  'link' => $form_state['values']['link'],
 );
}

/**
 * Render callback for the content type.
 */
function youtube_content_type_render($subtype, $conf, $args, $context) {
 $block = new stdClass();
 $block->content = "Video isn't available";

 if (!empty($conf['link'])) {
  $pattern = "#(?<=v=)[a-zA-Z0-9-]+(?=&)|(?<=v\/)[^&\n]+|(?<=v=)[^&\n]+|(?<=youtu.be/)[^&\n]+#";

  $idVideos = array();
  preg_match($pattern, $conf['link'], $idVideos);

  $block->content = '<iframe width="420" height="315" src="https://www.youtube.com/embed/' . $idVideos[0] . '"></iframe>';
 }

 return $block;
}
