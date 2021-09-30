//
// Created by anerruption on 9/29/21.
//

#include "../../../include/IO.hpp"
#include "../../../lib/include/csock/Request.hpp"

char* NetworkManager::GetResponse(char *address, int port, char *buffer)
{
    return Request::Send(address, port, buffer);
}