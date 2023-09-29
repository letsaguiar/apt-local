#include "cli.h"
#include <stdlib.h>
#include <string.h>

t_cli   *cli_parse(char **args)
{
    t_cli   *cli;

    cli = (t_cli *) malloc(sizeof (t_cli));
    for (int i = 1; args[i]; i++)
    {
        if (strcmp(args[i], "--version") == 0)
            cli->version = args[i];
        else if (!cli->operation)
            cli->operation = args[i];
        else if (!cli->package)
            cli->package = args[i];
    }
    return (cli);
}