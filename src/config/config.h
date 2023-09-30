#ifndef APT_LOCAL_CONFIG_H
# define APT_LOCAL_CONFIG_H

typedef struct
{

    char    *name;
    char    *repository_url;
    char    *binary;
    char    *unpack_folder;
    char    *unpack_binary;

}   t_config;

t_config    *load_package_config(const char *package_name);

void        free_package_config(t_config *config);

#endif