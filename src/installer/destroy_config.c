#include "installer.h"

void        destroy_config(t_config *config)
{
    free(config->name);
    
    free(config);
}