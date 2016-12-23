<?php
/**
 * @file
 * Implements hook_migrate_api().
 */
function dc_random_users_migrate_api() {
  return array(
    'api' => 2,
    'groups' => array(
      'example' => array(
        'title' => 'Create Users',
      ),
    ),
    'migrations' => array(
      'Users' => array(
        'class_name' => 'UsersMigration',
        'group_name' => 'example'
      ),
    ),
  );
}
