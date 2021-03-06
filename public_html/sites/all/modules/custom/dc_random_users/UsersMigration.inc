<?php

/**
 * @file
 * Class UsersMigration
 */
class UsersMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $path = drupal_get_path('module', 'dc_random_users') . '/data_sources/MOCK_DATA.csv';
    $this->description = t('Import a CSV-file');

    $columns = array(
      0 => array('id', t('User ID')),
      1 => array('username', t('UserName')),
      2 => array('email', t('User Email')),
      3 => array('password', t('User Password')),
      4 => array('first_name', t('First Name')),
      5 => array('last_name', t('Last Name')),
    );

    $this->source = new MigrateSourceCSV($path, $columns, array('header_rows' => 1));

    $this->destination = new MigrateDestinationUser();

    $this->map = new MigrateSQLMap($this->machineName, array(
      'id' => array(
        'type' => 'varchar',
        'length' => 6,
        'not null' => TRUE,
      )
    ), MigrateDestinationUser::getKeySchema());

    $this->addFieldMapping('name', 'username')->defaultValue('12345');
    $this->addFieldMapping('mail', 'email')->defaultValue('');
    $this->addFieldMapping('init')->defaultValue('');
    $this->addFieldMapping('pass', 'password')->defaultValue('asdf');
    $this->addFieldMapping('is_new')->defaultValue(TRUE);
    $this->addFieldMapping('roles')->defaultValue(DRUPAL_AUTHENTICATED_RID);
    $this->addFieldMapping('created')->defaultValue(time());
    $this->addFieldMapping('field_full_name', 'full_name');
  }

  public function prepareRow($row) {
    $row->full_name = $row->first_name . ' ' . $row->last_name;

    return parent::prepareRow($row); // TODO: Change the autogenerated stub
  }
}
