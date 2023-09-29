#ifndef APT_LOCAL_REQUESTER_H
# define APT_LOCAL_REQUESTER_H

#include <curl/curl.h>

void    requester_init();

void    requester_close();

char    *requester_request(char *url);

#endif