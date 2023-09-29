#include "config.h"
#include <stdio.h>
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

json_t  *get_config_object(FILE *file)
{
    json_t          *object;
    json_error_t    error;

    object = json_loadf(file, 0, &error);
    fclose(file);

    if (!object)
    {
        fprintf(stderr, "Unable to parse config file. Error: on line %d: %s\n", error.line, error.text);
        exit(3);
    }
    return (object);
}

char    *get_config_value(char *name, json_t *object)
{
    json_t  *config;

    config = json_object_get(object, name);
    return (strdup(json_string_value(config)));
}

t_config    *config_get(char *package)
{
    FILE    *config_file;

    json_t  *config_object;
    json_t  *config_binaries_object;

    t_config            *config;
    t_config_binaries   *binaries;

    // Get sources
    config_file = get_config_file(package);
    config_object = get_config_object(config_file);
    config_binaries_object = json_object_get(config_object, "binaries");

    // Set primary keys
    config = (t_config *) malloc(sizeof (t_config));
    config->name = get_config_value("name", config_object);
    config->repository_url = get_config_value("repository_url", config_object);

    // Set binaries
    binaries = (t_config_binaries *) malloc(sizeof (t_config_binaries));
    binaries->b_linux = get_config_value("b_linux", config_binaries_object);
    binaries->b_macos = get_config_value("b_macos", config_binaries_object);
    config->binaries = binaries;

    json_decref(config_object);
    return (config);
}