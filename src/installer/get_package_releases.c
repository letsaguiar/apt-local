#include "installer.h"
#include <string.h>

json_t  *installer_get_package_releases(t_config *config)
{
    char    url[1024];
    char    *response_str;

    // build url
    strcpy(url, config->repository_url);
    strcat(url, "/releases");
    response_str = requester_request(url);

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
    return (response_obj);
}