//
// Created by anerruption on 9/29/21.
//

#include "../include/csock/ClientSession.hpp"

ClientSession ClientSession::Create(char *address, int port)
{
    ClientSession session = ClientSession();

    session.socket = BaseSocket();

    session.socket.socket.address = address;
    session.socket.socket.port = port;

    session.socket.Open();

    return session;
}

bool ClientSession::Close()
{
    return socket.Close();
}

char* ClientSession::Send(char* buffer, size_t bytes)
{
    bool sent = socket.Send(buffer, bytes);
    char* response = nullptr;

    if (!sent)
    {
        //std::cout << "Could not send buffer." << std::endl;
        return response;
    }

    response = socket.ReceiveAll();

    return response;
}

char* ClientSession::Send(char* buffer, size_t bytes, size_t receive)
{
    bool sent = socket.Send(buffer, bytes);
    char* response = nullptr;

    if (!sent)
    {
        //std::cout << "Could not send buffer." << std::endl;
        return response;
    }

    response = socket.Receive(receive);

    return response;
}
