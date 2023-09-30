#include "requester.h"
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

FILE    *requester_perform(const char *url, const char *filename)
{
    // Verify if url is NULL
    if (!url || !filename)
    {
        fprintf(stderr, "Request url is NULL\n");
        return NULL;
    }

    // Init temp file
    FILE    *response_file;

    response_file = fopen(filename, "wb");
    if (!response_file) {
        perror("Error creating response file");
        return NULL;
    }

    // Init curl handle
    CURL        *curl;
    CURLcode    status;

    curl = curl_easy_init();
    if (!curl)
    {
        fprintf(stderr, "Error initializing libcurl\n");
        return NULL;
    }

    // Init curl headers
    struct curl_slist   *headers;

    headers = NULL;
    headers = curl_slist_append(headers, "User-Agent: Apt-Local");

    
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_file);

    status = curl_easy_perform(curl);
    if (status != CURLE_OK)
    {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(status));
        fclose(response_file);
        curl_easy_cleanup(curl);
        return NULL;
    }

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    fclose(response_file);
    return (fopen(filename, "r"));
}