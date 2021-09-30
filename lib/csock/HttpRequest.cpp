//
// Created by anerruption on 9/30/21.
//

#include "../include/csock/HttpRequest.hpp"
#include "../include/csock/HttpClientSession.hpp"

char* HttpRequest::Get(char* domain, char* headers)
{
    HttpClientSession session = HttpClientSession::Create(domain);
    if (session.socket.socket.address == nullptr)
    {
        //std::cout << "Session address is null." << std::endl;
        return nullptr;
    }

    char* result = session.Get(headers);
    session.Close();

    return result;
}