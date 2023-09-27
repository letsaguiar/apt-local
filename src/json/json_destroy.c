#include "json.h"
#include <stdlib.h>

void    json_destroy(t_map *json)
{
    for (int i = 0; json->table[i]; i++)
        free(json->table[i]);
    free(json->table);
    free(json);
}