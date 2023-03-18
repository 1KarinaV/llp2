#pragma once

#include <json.h>

#include "request.h"

#define TRANSFER "transfer_data.json"

typedef struct transfer_creator transfer_creator_t;

transfer_creator_t * create_transfer_format();

void prepare_data_to_transferm(const request_t *, transfer_creator_t *);

const char * get_json_format_string(const transfer_creator_t *);
