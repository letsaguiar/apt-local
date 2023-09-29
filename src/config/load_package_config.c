#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>

FILE    *get_config_file(const char *package)
{
    char    url[1024];

    strcpy(url, "configs/");
    strcat(url, package);
    strcat(url, ".json");
    
    return (fopen(url, "r"));
}

json_t  *get_config_object(FILE *file)
{
    char buffer[1024];
    size_t n;
    json_t* root;
    json_error_t error;

    n = fread(buffer, 1, sizeof(buffer), file);
    root = json_loadb(buffer, n, 0, &error);

    fclose(file);
    return (root);
}

char    *get_config_value(json_t *config, char *name)
{
    json_t  *value;

    value = json_object_get(config, name);
    if (!json_is_string(value))
    {
        fprintf(stderr, "Error: %s is not in the config file.\n", name);
        json_decref(config);
        return NULL;
    }

    return (strdup(json_string_value(value)));
}

t_config* load_package_config(const char *package)
{
    FILE    *file;
    file = get_config_file(package);
    if (!file)
    {
        perror("Error opening config file");
        return NULL;
    }

    json_t  *root;
    root = get_config_object(file);
    if (!root) {
        fprintf(stderr, "Error parsing config file");
        return NULL;
    }

    t_config* config = (t_config *) malloc(sizeof (t_config));
    if (!config) {
        perror("Memory allocation error");
        json_decref(root);
        return NULL;
    }

    config->repository_url = get_config_value(root, "repository_url");

    json_decref(root);

    return config;
}