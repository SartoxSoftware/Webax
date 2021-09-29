//
// Created by anerruption on 9/29/21.
//

#include "../../include/unix/BaseSocketUnix.hpp"

#include <sys/socket.h>
#include <unistd.h>
#include <cstdlib>
#include <netinet/in.h>
#include <arpa/inet.h>

bool BaseSocketUnix::Open()
{
    struct sockaddr_in serv_addr{};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        //std::cout << "An error occured while trying to create the socket." << std::endl;
        return false;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    // Convert the text address into binary
    if (inet_pton(AF_INET, address, &serv_addr.sin_addr) <= 0)
    {
        //std::cout << "Address not supported or invalid!" << std::endl;
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
    ssize_t bytes = 1;
    char* buffer = (char*)malloc(bytes);

    while (true)
    {
        buffer[bytes++] = ' ';
        ssize_t received = read(sock, buffer, 1);

        if (received == -1) // An error occured
        {
            //std::cout << "An error occured while reading all bytes." << std::endl;
            continue;
        }

        if (received == 0) // EOF
            break;
    }

    return buffer;
}