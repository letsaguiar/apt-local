#include "requester.h"

void    requester_close()
{
    curl_global_cleanup();
}