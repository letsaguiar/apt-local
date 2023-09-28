#ifndef APT_LOCAL_INSTALLER_H
# define APT_LOCAL_INSTALLER_H
# include <stdio.h>
# include <jansson.h>

json_t    *get_config(char *package);

#endif