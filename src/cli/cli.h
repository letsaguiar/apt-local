#ifndef APT_LOCAL_CLI_H
#define APT_LOCAL_CLI_H

typedef struct {

    char    *operation;
    char    *package;

}   t_cli_options;

t_cli_options   *parse_arguments(int argc, char **argv);

#endif