<?php
function fogo_add_charges(&$form_state) {
  $form = array();
  
  // Multi-state form: build different parts based on the #fogo_action param
  if (empty($form_state['values']['#fogo_action'])) {
    $form['#fogo_action'] = 'select items';
    $form['#fogo_next_action'] = 'confirm';

    // Possible student groups
    $classes = taxonomy_get_tree(1);
    $options = array();
    foreach ($classes as $class) {
      if ('Alumni' != $class->name) {
        $options[$class->tid] = $class->name;
      }
    }
    $form['class'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Select a class to add a charge to'),
      '#options' => $options,
    );
    
    
  }
  
  return $form;
}

function fogo_settings_form() {
  $form = array();
  $limits = variable_get('messaging_process_limit', array());

  $form['fogo_max_emails'] = array(
    '#type' => 'textfield',
    '#title' => 'Maximum number of emails to send on each cron run',
    '#description' => t(
      'Set to 0 to use a time-based limit to the number of emails sent on each cron run.  The
       site will send as many messages as possible without timing out.'
    ),
    '#required' => TRUE,
    '#maxlength' => 8,
    '#default_value' => isset($limits['message']) ? $limits['message'] : 0,
  );
  $form['#submit'][] = 'fogo_settings_form_submit';
  
  return system_settings_form($form);
}

function fogo_settings_form_submit($form, &$form_state) {
  $limits = variable_get('messaging_process_limit', array());
  $limits['message'] = $form_state['values']['fogo_max_emails'];
  variable_set('messaging_process_limit', $limits);
}