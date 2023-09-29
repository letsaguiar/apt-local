#include "config.h"

void        config_destroy(t_config *config)
{
    // Free primary keys
    free(config->name);
    free(config->repository_url);

    // Free binaries
    free(config->binaries->b_linux);
    free(config->binaries->b_macos);
    free(config->binaries);

    free(config);
}