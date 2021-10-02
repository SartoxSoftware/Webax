//
// Created by anerruption on 9/30/21.
//

#include "../include/csock/HttpClientSession.hpp"
#include "../../include/Util.hpp"

#include <cstring>
#include <cstdlib>
#include <cctype>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <sstream>

HttpClientSession HttpClientSession::Create(char* domain)
{
    HttpClientSession session = HttpClientSession();

    session.socket = BaseSocket();

    char* address = domain;
    int port = 80;
    char* protocol = "https";
    bool isname = false;

    std::stringstream subdomain;
    std::stringstream page;

    page << "/";

    // Protocol
    if (strstr(address, "://") != nullptr)
    {
        char** split = Util::Split(address, "://");
        protocol = split[0];
        address = split[1];
        free(split);
    }

    // Check if the address is an actual domain, not an IPv4 address for instance
    if (strstr(address, ".") != nullptr)
    {
        // Find any dot in the address
        char* end = address + strlen(address);
        char* match = std::find(address, end, '.');
        size_t index = (end == match) ? -1 : (match - address);

        if (isalpha(address[index - 1])) // Then we are sure it is an actual domain
        {
            isname = true;

            // Subdomain
            // TODO: Better check for subdomain
            char** split = Util::Split(address, ".");
            std::string addr(address);

            if (addr.ends_with(split[1]))
                subdomain << "www";
            else
                subdomain << split[0];

            session.subdomain = subdomain.str();
            free(split);
        }
    }

    // Page
    if (strstr(address, "/") != nullptr)
    {
        char** split = Util::Split(address, "/");
        address = split[0];
        // We are efficient, so we parse the pages at the same time
        page << split[1];
        free(split);
    }

    // Port
    if (strstr(address, ":") != nullptr)
    {
        char** split = Util::Split(address, ":");
        address = split[0];
        port = atoi(split[1]);
        free(split);
    }

    // Host
    subdomain << ".";

    char** spl = Util::Split(address, (char*)subdomain.str().c_str());
    session.host = spl[1];
    free(spl);

    if (isname) // If it's a domain name then we can transform it into an IPv4 address
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

    session.protocol = protocol;
    session.page = page.str();

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