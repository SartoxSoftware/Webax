//
// Created by anerruption on 9/30/21.
//

#include "../include/csock/HttpClientSession.hpp"

#include <cstring>
#include <cstdlib>
#include <cctype>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

HttpClientSession HttpClientSession::Create(char* domain)
{
    HttpClientSession session = HttpClientSession();

    session.socket = BaseSocket();

    char* address = domain;
    int port = 80;

    // Remove protocol first
    if (strstr(domain, "http://") != nullptr)
    {
        size_t length = strlen(domain) - 7;
        char* tmp = (char*)malloc(length);

        for (size_t i = 0; i < length; i++)
            tmp[i] = domain[length - 1 + i];

        address = tmp;
        free(tmp);
    }
    else if (strstr(domain, "https://") != nullptr)
    {
        size_t length = strlen(domain) - 8;
        char* tmp = (char*)malloc(length);

        for (size_t i = 0; i < length; i++)
            tmp[i] = domain[length - 1 + i];

        address = tmp;
        free(tmp);
    }

    // Parse domain into address and port
    if (strstr(domain, ":") != nullptr)
    {
        address = strtok(domain, ":");
        port = atoi(strtok(nullptr, ":"));
    }

    // Check if the domain is an actual domain name and not an IP address
    // TODO: Better detection (because of IPv6 addresses)
    for (size_t i = 0; i < strlen(address); i++)
        if (isalpha(address[i]))
        {
            hostent* record = gethostbyname(address);
            if (record == nullptr)
            {
                //std::cout << address << " is unavailable" << std::endl;
                session.socket.socket.address = nullptr;
                return session;
            }
            address = inet_ntoa(*(in_addr*)record->h_addr);
        }

    session.socket.socket.address = address;
    session.socket.socket.port = port;

    session.socket.Open();

    return session;
}

bool HttpClientSession::Close()
{
    return socket.Close();
}

char* HttpClientSession::Get(char* requestHeaders)
{
    bool sent = socket.Send(requestHeaders, strlen(requestHeaders));
    char* response = nullptr;

    if (!sent)
    {
        //std::cout << "Could not send buffer." << std::endl;
        return response;
    }

    response = socket.ReceiveAll();

    // Parse response headers
    // TODO: Remove the response headers from the response itself
    // TODO: Fix
    /*size_t headersIndex = 0;
    headers = (char**)malloc(1);

    while (true)
    {
        size_t index = 0;
        char header[1];

        for (size_t i = 0; i < strlen(response); i++)
        {
            char c = response[i];

            // We've reached the end of the response headers
            if (c == '\n' && (i > 0 && response[i - 1] == '\n' || (response[i - 1] == '\r' && (i > 1 && response[i - 2] == '\n'))))
                goto endloop;

            // We've reached the end of the response header
            if (c == '\r' || c == '\n')
            {
                headers[headersIndex++] = header;
                break;
            } else header[index++] = c; // We are in a response header
        }
    }

    endloop:*/
    return response;
}