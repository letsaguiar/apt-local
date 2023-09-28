#ifndef APT_LOCAL_INSTALLER_H
# define APT_LOCAL_INSTALLER_H

# include <jansson.h>
# include <curl/curl.h>

typedef struct s_config
{

    char    *name;
    char    *repository_url;

}   t_config;

t_config    *get_config(char *package);

void        destroy_config(t_config *config);

void        list_versions(t_config  *config);

#endif