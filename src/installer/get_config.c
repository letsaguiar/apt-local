#include "installer.h"
#include <stdlib.h>
#include <string.h>

FILE    *get_config(char *raw_path)
{
    char    path[1024];
    FILE    *config;

    strcpy(path, "configs/");
    strcat(path, raw_path);
    strcat(path, ".json");
    config = fopen(path, "r");
    if (!config)
    {
        printf("Config file not found!");
        exit(2);
    }
    return (config); 
}