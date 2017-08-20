<?php
/**
 * @file
 * historic_marker.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function historic_marker_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function historic_marker_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function historic_marker_node_info() {
  $items = array(
    'historic_marker' => array(
      'name' => t('Historic Marker'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Marker Name'),
      'help' => t('All new markers submitted, will be verified for their accuracy.  Any deemed inappropriate will be removed.'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
