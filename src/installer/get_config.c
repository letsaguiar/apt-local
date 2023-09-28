#include "installer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE    *get_config_file(char *package)
{
    char    path[1024];
    FILE    *config;

    strcpy(path, "configs/");
    strcat(path, package);
    strcat(path, ".json");
    config = fopen(path, "r");
    if (!config)
    {
        fprintf(stderr, "Config file not found!");
        exit(2);
    }
    return (config); 
}

json_t  *get_config_object(FILE *config_file)
{
    json_t          *config_object;
    json_error_t    config_error;

    config_object = json_loadf(config_file, 0, &config_error);
    fclose(config_file);

    if (!config_object)
    {
        fprintf(stderr, "Unable to parse config file. Error: on line %d: %s\n", config_error.line, config_error.text);
        exit(3);
    }
    return (config_object);
}

char    *extract_config(char *name, json_t *object)
{
    json_t  *config;

    config = json_object_get(object, name);
    return (strdup(json_string_value(config)));
}

t_config    *get_config(char *package)
{
    FILE        *config_file;
    json_t      *config_object;
    t_config    *config;

    config_file = get_config_file(package);
    config_object = get_config_object(config_file);
    
    config = (t_config *) malloc(sizeof (t_config));
    config->name = extract_config("name", config_object);
    config->repository_url = extract_config("repository_url", config_object);

    json_decref(config_object);
    return (config);
}