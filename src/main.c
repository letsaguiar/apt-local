#include "cli/cli.h"
#include "config/config.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    t_cli_options   *options;
    t_config        *config;

    options = parse_arguments(argc, argv);
    config = load_package_config(options->package);

    printf("%s", config->repository_url);
}