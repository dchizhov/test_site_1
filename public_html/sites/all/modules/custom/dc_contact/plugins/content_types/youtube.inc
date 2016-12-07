<?php
$plugin = array(
 'title' => t('YouTube or Vimeo Video'),
 'description' => t('Show YouTube or Vimeo video.'),
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
  '#title' => t('Link on Youtube or Vimeo'),
  '#default_value' => !empty($conf['link']) ? $conf['link'] : '',
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
 $content = "Video isn't available";

 if (!empty($conf['link'])) {
  $pattern = '%(?:youtube(?:-nocookie)?\.com/(?:[^/]+/.+/|(?:v|e(?:mbed)?)/|.*[?&]v=)|youtu\.be/)([^"&?/ ]{11})%i';
  $idVideos = array();
  preg_match($pattern, $conf['link'], $idVideos);

  if (!empty($idVideos)) {
   $content = '<iframe width="420" height="315" src="https://www.youtube.com/embed/' . $idVideos[1] . '"></iframe>';
  }
  else {
   $pattern = "~https?://(?:www\.)?vimeo\.com/([0-9]{6,10})~";
   preg_match($pattern, $conf['link'], $idVideos);
   $content = '<iframe width="420" height="315" src="http://player.vimeo.com/video/' . $idVideos[1] . '"></iframe>';
  }
 }
 $block->content = $content;

 return $block;
}
