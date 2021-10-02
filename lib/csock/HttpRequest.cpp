//
// Created by anerruption on 9/30/21.
//

#include "../include/csock/HttpRequest.hpp"

char* HttpRequest::Get(HttpClientSession session, char* headers)
{
    if (session.socket.socket.address == nullptr)
    {
        //std::cout << "Session address is null." << std::endl;
        return nullptr;
    }

    char* result = session.Get(headers);
    session.Close();

    return result;
}