#include "json/json.h"
#include <stdio.h>

int main(void)
{
    t_map   *json = json_build(7);
    json_destroy(json);
}