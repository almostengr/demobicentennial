<?php
/**
 * @file
 * historic_marker.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function historic_marker_user_default_roles() {
  $roles = array();

  // Exported role: content admin.
  $roles['content admin'] = array(
    'name' => 'content admin',
    'weight' => 4,
  );

  // Exported role: content reviewer.
  $roles['content reviewer'] = array(
    'name' => 'content reviewer',
    'weight' => 3,
  );

  // Exported role: educator.
  $roles['educator'] = array(
    'name' => 'educator',
    'weight' => 2,
  );

  // Exported role: site admin.
  $roles['site admin'] = array(
    'name' => 'site admin',
    'weight' => 5,
  );

  return $roles;
}
