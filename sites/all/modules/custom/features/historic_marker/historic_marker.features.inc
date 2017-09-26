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
 * Implements hook_eck_bundle_info().
 */
function historic_marker_eck_bundle_info() {
  $items = array(
    'points_log_points_log' => array(
      'machine_name' => 'points_log_points_log',
      'entity_type' => 'points_log',
      'name' => 'points_log',
      'label' => 'Points Log',
      'config' => array(),
    ),
    'points_ranking_points_ranking' => array(
      'machine_name' => 'points_ranking_points_ranking',
      'entity_type' => 'points_ranking',
      'name' => 'points_ranking',
      'label' => 'Points Ranking',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function historic_marker_eck_entity_type_info() {
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
    'points_ranking' => array(
      'name' => 'points_ranking',
      'label' => 'Points Ranking',
      'properties' => array(
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'rank' => array(
          'label' => 'rank',
          'type' => 'integer',
          'behavior' => 'title',
        ),
        'total_points' => array(
          'label' => 'Total Points',
          'type' => 'positive_integer',
          'behavior' => 'title',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_node_info().
 */
function historic_marker_node_info() {
  $items = array(
    'book' => array(
      'name' => t('Book page'),
      'base' => 'node_content',
      'description' => t('<em>Books</em> have a built-in hierarchical navigation. Use for handbooks or tutorials.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
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
