#include "cli.h"
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>

t_cli_options   *create_options()
{
    t_cli_options   *options;

    options = (t_cli_options *) malloc(sizeof (t_cli_options));
    if (!options)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    options->operation = NULL;
    options->package = NULL;

    return (options);
}

t_cli_options   *parse_arguments(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <operation> <package>\n", argv[0]);
        exit(EXIT_FAILURE);  
    }

    t_cli_options   *options;

    options = create_options();
    options->operation = argv[1];
    options->package = argv[2];
    return (options);
}