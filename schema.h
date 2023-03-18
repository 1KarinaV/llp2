#pragma once


typedef struct {
    char *schema_name;
    vector *attribute_declarations;
} add_schema_t;

typedef struct {
    char *schema_name;
} delete_schema_t;

typedef struct {
    char* schema_name;
    vector *attribute_values;
} add_node_t;
