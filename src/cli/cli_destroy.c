#include "cli.h"
#include <stdlib.h>

void    cli_destroy(t_cli *cli)
{
    free(cli->operation);
    free(cli->package);
    free(cli->version);

    free(cli);
}