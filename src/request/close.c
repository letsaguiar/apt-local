#include <curl/curl.h>

void     requester_close()
{
    curl_global_cleanup();
}