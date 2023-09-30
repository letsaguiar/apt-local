#include "config/config.h"
#include "request/requester.h"
#include <string.h>
#include <stdio.h>
#include <jansson.h>
#include <stdlib.h>

void    install_package_version(const t_config *config, const char *tag_name)
{
    // Build Github API Url
    char    url[1024];
    strcpy(url, config->repository_url);
    strcat(url, "/releases");

    // Fetch Github API
    FILE    *releases_file;
    releases_file = requester_perform(url, "package_releases.txt");
    if (!releases_file)
    {
        perror("Unable to fetch Github API");
        return;
    }

    // Parse response;
    json_t          *root;
    json_error_t    error;
    root = json_loadf(releases_file, 0, &error);
    fclose(releases_file);
    if (!root)
    {
        fprintf(stderr, "Error parsing config file");
        return;
    }
    
    // Find the desired tag_name
    json_t  *release;
    if (!tag_name)
        release = json_array_get(root, 0);
    else
    {
        for (size_t i = 0; i < json_array_size(root); i++)
        {
            json_t  *curr_release, *version;

            curr_release = json_array_get(root, i);
            version = json_object_get(curr_release, "tag_name");
            if (strcmp(tag_name, json_string_value(version)) == 0)
            {
                release = curr_release;
                break;
            }
        }
    }
    if (!release)
    {
        json_decref(root);
        fprintf(stderr, "Package version not found");
        return;
    }

    // Find the desired binary
    json_t  *assets = json_object_get(release, "assets");
    if (!assets || !json_is_array(assets))
    {
        json_decref(root);
        fprintf(stderr, "Package assets not found");
        return;
    }

    json_t  *release_asset;
    for (size_t i = 0; i < json_array_size(root); i++)
    {
        json_t  *curr_asset, *name;

        curr_asset = json_array_get(assets, i);
        name = json_object_get(curr_asset, "name");
        if (strcmp(config->binary, json_string_value(name)) == 0)
        {
            release_asset = curr_asset;
            break;
        }
    }
    if (!release_asset)
    {
        json_decref(root);
        fprintf(stderr, "Package asset not found");
        return;
    }

    // Download binary
    char    command[1024];
    strcpy(command, "wget ");
    strcat(command, json_string_value(json_object_get(release_asset, "browser_download_url")));
    system(command);

    // Unpack binary
    strcpy(command, "tar -xf ");
    strcat(command, config->binary);
    strcat(command, " -C sources");
    system(command);

    // Create hard link
    strcpy(command, "ln sources/");
    strcat(command, config->unpack_binary);
    strcat(command, " bin/");
    strcat(command, config->name);
    system(command);

    json_decref(root);
}