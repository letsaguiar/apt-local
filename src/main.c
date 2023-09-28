#include "installer/installer.h"
#include <string.h>

int main(int argc, char **argv)
{
    t_config    *config;

    if (argc < 3)
        return 1;
    
    if (strcmp(argv[1], "list") == 0)
    {
        config = get_config(argv[2]);
        printf("%s", config->name);
        destroy_config(config);
    }
    return 0;
}