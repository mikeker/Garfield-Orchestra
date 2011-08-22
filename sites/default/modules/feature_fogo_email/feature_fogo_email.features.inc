<?php
/**
 * @file
 * feature_fogo_email.features.inc
 */

/**
 * Implementation of hook_node_info().
 */
function feature_fogo_email_node_info() {
  $items = array(
    'email_notice' => array(
      'name' => t('Email Notice'),
      'base' => 'node_content',
      'description' => t('A mass email notice sent to some or all FOGO parents and students'),
      'has_title' => '1',
      'title_label' => t('Subject'),
      'help' => '',
    ),
  );
  return $items;
}
