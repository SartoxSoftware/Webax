//
// Created by anerruption on 9/29/21.
//

#include "../include/csock/Request.hpp"
#include "../include/csock/ClientSession.hpp"

char* Request::Send(char *address, int port, char *buffer)
{
    ClientSession session = ClientSession::Create(address, port);
    return session.Send(buffer);
}

char* Request::Send(char *address, int port, char *buffer, size_t bytes)
{
    ClientSession session = ClientSession::Create(address, port);
    return session.Send(buffer, bytes);
}