#include <curl/curl.h>

int     requester_init()
{
    return curl_global_init(CURL_GLOBAL_ALL);
}