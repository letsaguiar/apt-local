#ifndef APT_LOCAL_INSTALLER_H
# define APT_LOCAL_INSTALLER_H
# include <stdio.h>
# include <jansson.h>

typedef struct s_config
{

    char    *name;

}   t_config;

t_config    *get_config(char *package);

void        destroy_config(t_config *config);

#endif