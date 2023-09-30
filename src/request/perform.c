#include "request.h"
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

static size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t total_size = size * nmemb;
    fwrite(contents, 1, total_size, (FILE*)userp);
    return total_size;
}

FILE* requester_perform(const char *url) {
    if (!url) {
        fprintf(stderr, "Request url is NULL\n");
        return NULL;
    }

    CURL* curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error initializing libcurl\n");
        return NULL;
    }

    CURLcode res;

    FILE* response_file = tmpfile();
    if (!response_file) {
        perror("Error creating response file");
        curl_easy_cleanup(curl);
        return NULL;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_file);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        fclose(response_file);
        curl_easy_cleanup(curl);
        return NULL;
    }

    curl_easy_cleanup(curl);

    return response_file;
}