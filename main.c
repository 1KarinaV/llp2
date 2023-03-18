#define YYDEBUG 1

#include <stdio.h>
#include "parser.h"
#include "request.h"
#include "transfer_creator.h"
int yyparse();

int main() {
    int yydebug=1;
    int x = yyparse();
    request_t tree = get_request_tree();
    transfer_creator_t * t = create_transfer_format();
    prepare_data_to_transferm(&tree, t);
    printf("%s\n", get_json_format_string(t));

    FILE * fl;
    fl = fopen(TRANSFER, "a+");
    if (fl == NULL) {
        printf("cannot create or open target\n");
        return -1;
    }
    fprintf(fl, "%s\n",get_json_format_string(t));
    fclose(fl);
    return 0;
}
