#include "installer/installer.h"
#include <string.h>

int main(int argc, char **argv)
{
    json_t    *config;

    if (argc < 3)
        return 1;
    
    if (strcmp(argv[1], "list") == 0)
    {
        config = get_config(argv[2]);
        
        json_t  *name;
        name = json_object_get(config, "name");
        printf("%s", json_string_value(name));
        json_decref(config);
    }
    return 0;
}