<?php
/**
 * @file
 * Class CountriesMigration
 */

class CountriesMigration extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $path = drupal_get_path('module', 'dc_migration_countries_cities') . '/data_sources/countries.csv';
    $this->description = t('Import a Countries CSV-file');

    $columns = array(
      0 => array('country_id', t('Country ID')),
      1 => array('countries', t('Name Country')),
    );

    $this->source = new MigrateSourceCSV($path, $columns, array('header_rows' => 1));

    $this->destination = new MigrateDestinationTerm('countries');

    $this->map = new MigrateSQLMap($this->machineName, array(
      'country_id' => array(
        'type' => 'varchar',
        'length' => 6,
        'not null' => TRUE,
      )
    ), MigrateDestinationUser::getKeySchema());

    $this->addFieldMapping('name', 'countries')->defaultValue('Country');
  }
}
