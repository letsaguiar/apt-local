#ifndef APT_LOCAL_CLI_H
# define APT_LOCAL_CLI_H

typedef struct s_cli
{
    char    *operation;
    char    *package;
    char    *version;
}   t_cli;

t_cli   *cli_parse(char **args);

void    cli_destroy(t_cli *cli);

#endif