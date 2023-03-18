#pragma once

typedef enum {
    INT,
    BOOL,
    FLOAT,
    STR,
    REFERENCE
} attr_type_t;

typedef struct {
    char *attr_name;
    attr_type_t type;
    char *schema_ref_name;
} attribute_declaration_t;

typedef struct {
    char *attr_name;
    attr_type_t type;
    base_value_t value;
} attr_value_t;
