#include "cli.h"
#include <stdlib.h>
#include <string.h>

t_cli   *cli_parse(char **args)
{
    t_cli   *cli;

    cli = (t_cli *) malloc(sizeof (t_cli));
    cli->operation = args[1];
    cli->package = args[2];
    for (int i = 3; args[i]; i++)
    {
        if (strcmp(args[i], "--version") == 0)
            cli->version = args[++i];
    }
    return (cli);
}