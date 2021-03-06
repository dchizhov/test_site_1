<?php

/**
 * @file
 * Class CitiesMigration
 */
class CitiesMigration extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $path = drupal_get_path('module', 'dc_migration_countries_cities') . '/data_sources/cities.csv';
    $this->description = t('Import a Cities CSV-file');

    $columns = array(
      0 => array('id', t('City ID')),
      1 => array('cities', t('Name City')),
      2 => array('country_id', t('Country ID')),
    );

    $this->source = new MigrateSourceCSV($path, $columns, array('header_rows' => 1));

    $this->destination = new MigrateDestinationTerm('cities');

    $this->map = new MigrateSQLMap($this->machineName, array(
      'id' => array(
        'type' => 'varchar',
        'length' => 6,
        'not null' => TRUE,
      )
    ), MigrateDestinationUser::getKeySchema());

    $this->addFieldMapping('name', 'cities')->defaultValue('City');
    $this->addFieldMapping('field_country', 'country_id')
      ->sourceMigration('Countries');
  }

  function prepareRow($row) {
    $row->cities = $row->cities . ' - ' . $row->id;

    return parent::prepareRow($row); // TODO: Change the autogenerated stub
  }
}
