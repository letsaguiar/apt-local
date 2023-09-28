#include "installer.h"
#include "../requester/requester.h"
#include <string.h>
#include <stdlib.h>

void    list_versions(t_config  *config)
{
    char    url[1024];
    char    *response_str;

    // build url
    strcpy(url, config->repository_url);
    strcat(url, "/releases");
    response_str = request(url);

    // convert to json
    json_t          *response_obj;
    json_error_t    response_obj_error;

    response_obj = json_loads(response_str, 0, &response_obj_error);
    free(response_str);
    if (!response_obj)
    {
        fprintf(stderr, "Unable to parse Github API response");
        exit(5);
    }

    // print versions
    for (size_t i = 0; i < json_array_size(response_obj); i++)
    {
        json_t  *data, *version;

        data = json_array_get(response_obj, i);
        version = json_object_get(data, "tag_name");
        printf("%s\n", json_string_value(version));
    }

    // free objects
    json_decref(response_obj);
}