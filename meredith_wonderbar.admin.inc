<?php

/**
 * @file
 * Administrative configurable settings for the wonderbar.
 */

/**
 * Implements hook_admin()
 */
function meredith_wonderbar_admin() {
  $form = array();

  // This should be exlcuded from features, quickly allows the module to be
  // enabled or disabled.
  $form['meredith_wonderbar_enabled'] = array(
    '#type' => 'radios',
    '#title' => t('Wonderbar Enabled?'),
    '#options' => array(
      1 => t('Yes'),
      0 => t('No'),
    ),
    '#default_value' => variable_get('meredith_wonderbar_enabled', 0),
  );

  // Originally documented @
  // http://www.sitepoint.com/building-drupal-7-module-show-latest-nodes/.
  $types = node_type_get_types();
  foreach ($types as $node_type) {
    $nodetypes[$node_type->type] = $node_type->name;
  }

  $form['meredith_wonderbar_shownodes_nodes_toshow'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Show on Content Types'),
    '#description' => t('Places the wonderbar js on all selected node types. Primarily video stories.'),
    '#options' => $nodetypes,
    '#default_value' => variable_get('meredith_wonderbar_shownodes_nodes_toshow', array('')),
  );


  $form['meredith_wonderbar_url_source'] = array(
    '#type' => 'textfield',
    '#title' => t('Wonderbar Script URL Source'),
    '#default_value' => variable_get('meredith_wonderbar_url_source', '//embed.ramp.com/amd.js'),
    '#description' => t('The url script source. Taken from "<" script data-ramp-target="" data-ramp-widget="10649" data-ramp-api-key="" data-ramp-playlist-ids="" data-ramp-item-id="" src="//embed.ramp.com/amd.js">'),
    '#required' => TRUE,
  );

  $form['meredith_wonderbar_url_source_dev'] = array(
    '#type' => 'textfield',
    '#title' => t('Wonderbar Script URL Source - Staging'),
    '#default_value' => variable_get('meredith_wonderbar_url_source_dev', '//stage-embed.ramp.com/amd.js'),
    '#description' => t('For use in test and dev environments.  Typically this will be something like src="//stage-embed.ramp.com/amd.js">'),
    '#required' => TRUE,
  );

  $form['meredith_wonderbar_data_ramp_widget_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Wonderbar Data Ramp Widget ID'),
    '#default_value' => variable_get('meredith_wonderbar_data_ramp_widget_id', '10649'),
    '#description' => t('ID of wonderbar widget. Must stay the same unless RAMP provides a new one, default is set as "10649".'),
    '#required' => TRUE,
  );

  $form['meredith_wonderbar_data_ramp_target_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Wonderbar Data Ramp Target ID'),
    '#default_value' => variable_get('meredith_wonderbar_data_ramp_target_id', '#rampEmbedPlayer'),
    '#description' => t('ID of embed iframe player. Provided via Audience Development. Typically "#rampEmbedPlayer".'),
    '#required' => TRUE,
  );

  $form['meredith_wonderbar_data_ramp_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('Wonderbar Data Ramp API Key'),
    '#default_value' => variable_get('meredith_wonderbar_data_ramp_api_key', ''),
    '#description' => t('RAMP provided api key.'),
    '#required' => TRUE,
  );

  $form['meredith_wonderbar_data_ramp_playlist_ids'] = array(
    '#type' => 'textfield',
    '#title' => t('Wonderbar Data Ramp Playlist Ids'),
    '#default_value' => variable_get('meredith_wonderbar_data_ramp_playlist_ids', ''),
    '#description' => t('Comma delimited string of playlist IDs. Typically only one will be used per site.'),
    '#required' => FALSE,
  );

  $form['meredith_wonderbar_weight'] = array(
    '#type' => 'textfield',
    '#title' => t('Wonderbar Javascript Weight'),
    '#default_value' => variable_get('meredith_wonderbar_weight', ''),
    '#description' => t('Drupal weight, determines where the script loads in Page Bottom.'),
    '#required' => FALSE,
  );

  return system_settings_form($form);
}
