#include "config.h"
#include <stdlib.h>

void free_package_config(t_config *config) {
    if (config) {
        free(config->repository_url);
        free(config);
    }
}