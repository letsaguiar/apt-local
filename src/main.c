#include "cli/cli.h"
#include "config/config.h"
#include "request/requester.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void    list_package_versions(const t_config *config);

void    install_package_version(const t_config *config, const char *tag_name);

int main(int argc, char **argv)
{
    t_cli_options   *options;
    t_config        *config;

    options = parse_arguments(argc, argv);
    config = load_package_config(options->package);

    if (strcmp(options->operation, "list") == 0)
        list_package_versions(config);
    if (strcmp(options->operation, "install") == 0)
        install_package_version(config, NULL);

    free_package_config(config);
    free(options);
}