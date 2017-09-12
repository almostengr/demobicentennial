<?php
/**
 * @file
 * bicentennial_points.features.inc
 */

/**
 * Implements hook_views_api().
 */
function bicentennial_points_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function bicentennial_points_eck_bundle_info() {
  $items = array(
    'points_log_points_log' => array(
      'machine_name' => 'points_log_points_log',
      'entity_type' => 'points_log',
      'name' => 'points_log',
      'label' => 'Points Log',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function bicentennial_points_eck_entity_type_info() {
  $items = array(
    'points_log' => array(
      'name' => 'points_log',
      'label' => 'Points Log',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'points' => array(
          'label' => 'points',
          'type' => 'integer',
          'behavior' => 'title',
        ),
      ),
    ),
  );
  return $items;
}
