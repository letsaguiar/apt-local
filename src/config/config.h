#ifndef APT_LOCAL_CONFIG_H
# define APT_LOCAL_CONFIG_H

# include <jansson.h>

typedef struct s_config
{

    char    *name;
    char    *repository_url;

}   t_config;

t_config    *config_get(char *package);

void        config_destroy(t_config *config);

#endif