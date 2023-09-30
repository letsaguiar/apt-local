#include "cli/cli.h"
#include "config/config.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    t_cli_options   *options;

    options = parse_arguments(argc, argv);

    free(options);
}