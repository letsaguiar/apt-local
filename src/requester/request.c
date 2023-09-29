#include "requester.h"
#include <stdlib.h>
#include <string.h>

size_t write(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t total_size;
    char *response_buffer;

    total_size = size * nmemb;
    response_buffer = (char *) userp;
    strncat(
        response_buffer, (char *) contents, total_size
    );
    return (total_size);
}

char    *requester_request(char *url)
{
    CURL                *curl;
    CURLcode            status;
    char                *buffer;
    struct curl_slist   *headers;

    buffer = (char *) malloc(1024000 * sizeof(char));

    headers = NULL;
    headers = curl_slist_append(headers, "User-Agent: Apt-Local");

    curl = curl_easy_init();
    if (!curl)
    {
        fprintf(stderr, "Unable to init curl and make requests");
        exit(4);
    }
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);

    status = curl_easy_perform(curl);
    if (status != CURLE_OK)
    {
        fprintf(stderr, "Curl request failed");
        exit(5);
    }
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    return (buffer);
}