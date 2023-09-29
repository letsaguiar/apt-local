#ifndef APT_LOCAL_CONFIG_H
#define APT_LOCAL_CONFIG_H

typedef struct {

    char* repository_url;

} t_config;

t_config*   load_package_config(const char* package);

void        free_package_config(t_config* config);

#endif