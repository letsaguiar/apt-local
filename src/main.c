#include "cli/cli.h"
#include "config/config.h"
#include "request/requester.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    t_cli_options   *options;
    t_config        *config;

    options = parse_arguments(argc, argv);
    config = load_package_config(options->package);

    FILE    *response;

    response = requester_perform("https://api.github.com/repos/neovim/neovim/releases");
    if (!response)
    {
        fprintf(stderr, "Failed to retrieve response\n");
        return 1;
    }

    fclose(response);
    free_package_config(config);
    free(options);
}