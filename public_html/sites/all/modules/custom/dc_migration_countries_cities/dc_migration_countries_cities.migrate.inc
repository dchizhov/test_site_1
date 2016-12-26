<?php
/**
 * @file
 * Implements hook_migrate_api().
 */

function dc_migration_countries_cities_migrate_api() {
  return array(
    'api' => 2,
    'groups' => array(
      'cc' => array(
        'title' => 'Countries and Cities',
      ),
    ),
    'migrations' => array(
      'Countries' => array(
        'class_name' => 'CountriesMigration',
        'group_name' => 'cc'
      ),
      'Cities' => array(
        'class_name' => 'CitiesMigration',
        'group_name' => 'cc',
      ),
    ),
  );
}
