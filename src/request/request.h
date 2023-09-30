#ifndef APT_LOCAL_REQUEST_H
#define APT_LOCAL_REQUEST_H

#include <stdio.h>

int     requester_init();

void    requester_close();

FILE    *requester_perform(const char *url);

#endif