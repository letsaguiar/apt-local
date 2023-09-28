#include "installer/installer.h"
#include "requester/requester.h"
#include <string.h>
#include <stdio.h>

int main()
{
    requester_init();

    char *foo = request("https://api.github.com/repos/neovim/neovim/releases");
    printf("%s", foo);
    free(foo);
    requester_close();
    return 0;
}