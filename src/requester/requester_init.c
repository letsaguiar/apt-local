#include "requester.h"

void    requester_init()
{
    curl_global_init(CURL_GLOBAL_ALL);
}