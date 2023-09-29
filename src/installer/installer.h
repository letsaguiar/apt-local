#ifndef APT_LOCAL_INSTALLER_H
# define APT_LOCAL_INSTALLER_H

#include "../config/config.h"
#include "../requester/requester.h"

json_t  *installer_get_package_releases(t_config *config);

void    installer_list_versions(t_config *config);

#endif