#include "json.h"
#include <stdlib.h>

t_map   *json_build(int size)
{
    t_map   *json;

    json = (t_map *) malloc(sizeof (t_map));
    json->table = malloc(size * sizeof (void *));
    json->size = size;
    return (json);
}