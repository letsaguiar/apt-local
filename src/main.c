#include "installer/installer.h"
#include "requester/requester.h"
#include <string.h>

int main(int argc, char **argv)
{
    t_config    *config;

    if (argc < 3)
        return 1;
    
    requester_init();

    if (strcmp(argv[1], "list") == 0)
    {
        config = get_config(argv[2]);
        list_versions(config);
        destroy_config(config);
    }

    requester_close();
    return 0;
}