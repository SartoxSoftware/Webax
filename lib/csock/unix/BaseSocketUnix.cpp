//
// Created by anerruption on 9/29/21.
//

#include "../../include/csock/unix/BaseSocketUnix.hpp"

#include <sys/socket.h>
#include <unistd.h>
#include <cstdlib>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>

bool BaseSocketUnix::Open()
{
    struct sockaddr_in serv_addr{};

    int domain = AF_INET;

    serv_addr.sin_family = domain;
    serv_addr.sin_port = htons(port);

    // Convert the text address into binary
    if (inet_pton(domain, address, &serv_addr.sin_addr) <= 0)
    {
        serv_addr.sin_family = AF_INET6;
        
        // Maybe address is IPv6?
        if (inet_pton(AF_INET6, address, &serv_addr.sin_addr) == 1)
        {
            domain = AF_INET6;
            goto connect;
        }

        // If not then it's really invalid
        std::cout << "Address not supported or invalid!" << std::endl;
        return false;
    }

    connect:
    if ((sock = socket(domain, SOCK_STREAM, 0)) < 0)
    {
        //std::cout << "An error occured while trying to create the socket." << std::endl;
        return false;
    }

    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        //std::cout << "Connection failed!" << std::endl;
        return false;
    }

    return true;
}

bool BaseSocketUnix::Close()
{
    close(sock);

    return true;
}

bool BaseSocketUnix::Send(char *buffer, size_t bytes)
{
    ssize_t sent = send(sock, buffer, bytes, 0);

    if (sent < bytes)
    {
        //std::cout << "Could not send all bytes: sent " << sent << ", specified " << bytes << std::endl;
        return false;
    }

    return true;
}

char* BaseSocketUnix::Receive(size_t bytes)
{
    char* buffer = (char*)malloc(bytes);
    ssize_t received = read(sock, buffer, bytes);

    if (received > bytes)
    {
        //std::cout << "More bytes were read than specified: received " << received << ", specified " << bytes << std::endl;
    }

    return buffer;
}

char* BaseSocketUnix::ReceiveAll()
{
    size_t size = 4096;
    size_t bytes = size;
    char* buffer = (char*)malloc(size);

    while (true)
    {
        char* tmp = (char*)malloc(size);

        ssize_t received = read(sock, tmp, size);

        if (received == -1) // Error
        {
            //std::cout << "An error occurred while trying to read bytes." << std::endl;
            continue;
        }

        if (received == 0) // EOF
            break;

        char* oldbuf = buffer;
        buffer = (char*)malloc(bytes += size);

        strncpy(buffer, oldbuf, bytes - size);
        strncat(buffer, tmp, received);

        free(oldbuf);
    }

    return buffer;
}