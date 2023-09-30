#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>

FILE    *get_config_file(const char *package_name)
{
    char    url[1024];

    strcpy(url, "configs/");
    strcat(url, package_name);
    strcat(url, ".json");
    
    return (fopen(url, "r"));
}

json_t  *get_config_object(FILE *package_file)
{
    char buffer[1024];
    size_t n;
    json_t* root;
    json_error_t error;

    n = fread(buffer, 1, sizeof(buffer), package_file);
    root = json_loadb(buffer, n, 0, &error);

    fclose(package_file);
    return (root);
}

char    *get_config_value(json_t *package_config, char *property_name)
{
    json_t  *value;

    value = json_object_get(package_config, property_name);
    if (!json_is_string(value))
    {
        fprintf(stderr, "Error: %s is not in the config file.\n", property_name);
        json_decref(package_config);
        return NULL;
    }

    return (strdup(json_string_value(value)));
}

t_config* load_package_config(const char *package_name)
{
    FILE    *file;
    file = get_config_file(package_name);
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

    config->name = get_config_value(root, "name");
    config->repository_url = get_config_value(root, "repository_url");
    config->binary = get_config_value(root, "binary");
    config->unpack_folder = get_config_value(root, "unpack_folder");
    config->unpack_binary = get_config_value(root, "unpack_binary");

    json_decref(root);

    return config;
}