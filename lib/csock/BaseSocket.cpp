//
// Created by anerruption on 9/29/21.
//

#include "../include/csock/BaseSocket.hpp"

bool BaseSocket::Open()
{
    return socket.Open();
}

bool BaseSocket::Close()
{
    return socket.Close();
}

bool BaseSocket::Send(char *buffer, size_t bytes)
{
    return socket.Send(buffer, bytes);
}

char* BaseSocket::Receive(size_t bytes)
{
    return socket.Receive(bytes);
}

char* BaseSocket::ReceiveAll()
{
    return socket.ReceiveAll();
}