#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "vector.h"

#include "value.h"
#include "attribute.h"
#include "schema.h"
#include "select.h"
#include "statement.h"

typedef enum {
    UNDEFINED,
    OPEN,
    CREATE,
    CLOSE,
    ADD_SCHEMA,
    DELETE_SCHEMA,
    ADD_NODE,
    SELECT_REQ
} request_type_t;

typedef struct {
    char *filename;
} file_work_struct_t;

typedef struct {
    request_type_t type;
    char* schema_name;
    union {
        file_work_struct_t file_work;
        add_schema_t add_schema;
        delete_schema_t delete_schema;
        add_node_t add_node;
        vector *statements;
    };
} request_t;

request_t get_request_tree();
