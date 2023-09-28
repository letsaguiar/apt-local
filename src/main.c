#include "installer/installer.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE    *config;

    if (argc < 3)
        return 1;
    
    if (strcmp(argv[1], "list") == 0)
    {
        config = get_config(argv[2]);
        fclose(config);
    }
    return 0;
}