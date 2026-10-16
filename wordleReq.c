#define CURL_STATICLIB
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
int main(void)
{
    char fullUrl[54] = "https://www.nytimes.com/svc/wordle/v2/";
    printf("Starting...\n");
    
    char dateEntered[11];
    printf("Please Enter a date (YYYY-MM-DD): ");
    fgets(dateEntered, sizeof(dateEntered), stdin);
    dateEntered[10] = '\0'; 
    CURL* curl;
    CURLcode result = curl_global_init(CURL_GLOBAL_ALL);
    
    if(result != CURLE_OK)
    {
        printf("Sorry, curl had an unexpected error!\n");
        return (int)result;
    }
    curl = curl_easy_init();
    if (!curl)
    {
        return -1;
    }
    strcat(fullUrl, dateEntered);
    strcat(fullUrl, ".json");
    curl_easy_setopt(curl, CURLOPT_URL, fullUrl);
    result = curl_easy_perform(curl);
    if(result != CURLE_OK)
    {
        printf("Sorry, curl had an unexpected error!\n");
        printf(curl_easy_strerror(result));
        return -1;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    printf("\n");
    system("PAUSE");
    return 0;
}