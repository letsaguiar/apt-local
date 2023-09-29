#include "installer.h"
#include "../requester/requester.h"
#include <string.h>
#include <stdlib.h>

void    installer_list_versions(t_config  *config)
{
    json_t  *package_releases;

    package_releases = installer_get_package_releases(config);
    for (size_t i = 0; i < json_array_size(package_releases); i++)
    {
        json_t  *release, *version;

        release = json_array_get(package_releases, i);
        version = json_object_get(release, "tag_name");
        printf("%s\n", json_string_value(version));
    }

    // free objects
    json_decref(package_releases);
}