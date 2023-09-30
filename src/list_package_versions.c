#include "config/config.h"
#include "request/requester.h"
#include <string.h>
#include <stdio.h>
#include <jansson.h>

void    list_package_versions(const t_config *config)
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
    if (!root)
    {
        fprintf(stderr, "Error parsing config file");
        return;
    }

    for (size_t i = 0; i < json_array_size(root); i++)
    {
        json_t  *release, *version;

        release = json_array_get(root, i);
        version = json_object_get(release, "tag_name");
        printf("%s\n", json_string_value(version));
    }

    fclose(releases_file);
    json_decref(root);
}