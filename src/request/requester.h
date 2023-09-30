#ifndef APT_LOCAL_REQUESTER_H
# define APT_LOCAL_REQUESTER_H

#include <stdio.h>

void    requester_init();

void    requester_close();

FILE    *requester_perform(const char *url, const char *filename);

#endif