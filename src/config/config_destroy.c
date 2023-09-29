#include "config.h"

void        config_destroy(t_config *config)
{
    free(config->name);
    free(config->repository_url);

    free(config);
}