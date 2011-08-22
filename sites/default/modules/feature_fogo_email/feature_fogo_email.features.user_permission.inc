<?php
/**
 * @file
 * feature_fogo_email.features.user_permission.inc
 */

/**
 * Implementation of hook_user_default_permissions().
 */
function feature_fogo_email_user_default_permissions() {
  $permissions = array();

  // Exported permission: create email_notice content
  $permissions['create email_notice content'] = array(
    'name' => 'create email_notice content',
    'roles' => array(
      0 => 'administrator',
      1 => 'board exec comm',
      2 => 'board member',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any email_notice content
  $permissions['delete any email_notice content'] = array(
    'name' => 'delete any email_notice content',
    'roles' => array(
      0 => 'administrator',
      1 => 'board exec comm',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own email_notice content
  $permissions['delete own email_notice content'] = array(
    'name' => 'delete own email_notice content',
    'roles' => array(
      0 => 'administrator',
      1 => 'board member',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any email_notice content
  $permissions['edit any email_notice content'] = array(
    'name' => 'edit any email_notice content',
    'roles' => array(
      0 => 'administrator',
      1 => 'board exec comm',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own email_notice content
  $permissions['edit own email_notice content'] = array(
    'name' => 'edit own email_notice content',
    'roles' => array(
      0 => 'administrator',
      1 => 'board member',
    ),
    'module' => 'node',
  );

  return $permissions;
}
