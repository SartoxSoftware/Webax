//
// Created by anerruption on 9/29/21.
//

#ifndef WEBAX_CLIENTSESSION_HPP
#define WEBAX_CLIENTSESSION_HPP

#include "BaseSocket.hpp"

#include <cstddef>

class ClientSession
{
public:
    BaseSocket socket;

    static ClientSession Create(char* address, int port);

    bool Close();

    char* Send(char* buffer, size_t bytes);
    char* Send(char* buffer);
};

#endif //WEBAX_CLIENTSESSION_HPP
