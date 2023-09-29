#include "cli/cli.h"
#include "installer/installer.h"
#include "requester/requester.h"
#include "config/config.h"
#include <string.h>

int main(int argc, char **argv)
{
    t_cli       *args;
    t_config    *config;

    if (argc < 3)
        return 1;
    
    requester_init();
    args = cli_parse(argv);
    config = config_get(args->package);
    
    if (strcmp(args->operation, "list") == 0)
        installer_list_versions(config);

    cli_destroy(args);
    config_destroy(config);
    requester_close();
    return 0;
}