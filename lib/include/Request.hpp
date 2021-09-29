//
// Created by anerruption on 9/29/21.
//

#ifndef WEBAX_REQUEST_HPP
#define WEBAX_REQUEST_HPP

#include <cstddef>

class Request
{
    static char* Send(char* address, int port, char* buffer);
    static char* Send(char* address, int port, char* buffer, size_t bytes);
};

#endif //WEBAX_REQUEST_HPP
