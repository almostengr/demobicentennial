<?php
/**
 * @file
 * bicentennial_points.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function bicentennial_points_default_rules_configuration() {
  $items = array();
  $items['rules_points_create_a_marker'] = entity_import('rules_config', '{ "rules_points_create_a_marker" : {
      "LABEL" : "POINTS: Create A Marker",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--historic_marker" : { "bundle" : "historic_marker" } },
      "DO" : [
        { "entity_create" : {
            "USING" : { "type" : "points_log", "param_type" : "points_log" },
            "PROVIDE" : { "entity_created" : { "points_entry" : "points entry" } }
          }
        },
        { "data_set" : { "data" : [ "points-entry:title" ], "value" : "Submitted marker" } },
        { "data_set" : { "data" : [ "points-entry:uid" ], "value" : [ "site:current-user" ] } },
        { "data_set" : { "data" : [ "points-entry:points" ], "value" : "5" } },
        { "entity_save" : { "data" : [ "points-entry" ] } }
      ]
    }
  }');
  $items['rules_points_create_account'] = entity_import('rules_config', '{ "rules_points_create_account" : {
      "LABEL" : "POINTS: Create Account",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "DO" : [
        { "entity_create" : {
            "USING" : { "type" : "points_log", "param_type" : "points_log" },
            "PROVIDE" : { "entity_created" : { "points_entry" : "points entry" } }
          }
        },
        { "data_set" : { "data" : [ "points-entry:title" ], "value" : "Created account" } },
        { "data_set" : { "data" : [ "points-entry:uid" ], "value" : [ "account" ] } },
        { "data_set" : { "data" : [ "points-entry:points" ], "value" : "50" } },
        { "entity_save" : { "data" : [ "points-entry" ] } }
      ]
    }
  }');
  return $items;
}
