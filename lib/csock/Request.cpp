//
// Created by anerruption on 9/29/21.
//

#include "../include/csock/Request.hpp"
#include "../include/csock/ClientSession.hpp"

#include <cstring>

char* Request::Send(char *address, int port, char *buffer)
{
    return Send(address, port, buffer, strlen(buffer));
}

char* Request::Send(char *address, int port, char *buffer, size_t bytes)
{
    ClientSession session = ClientSession::Create(address, port);
    char* result = session.Send(buffer, bytes);
    session.Close();

    return result;
}

char* Request::Send(char *address, int port, char *buffer, size_t bytes, size_t receive)
{
    ClientSession session = ClientSession::Create(address, port);
    char* result = session.Send(buffer, bytes, receive);
    session.Close();

    return result;
}