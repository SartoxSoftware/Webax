//
// Created by anerruption on 9/30/21.
//

#ifndef WEBAX_HTTPCLIENTSESSION_HPP
#define WEBAX_HTTPCLIENTSESSION_HPP

#include "BaseSocket.hpp"

#include <cstddef>

class HttpClientSession
{
public:
    BaseSocket socket;
    char** headers;

    static HttpClientSession Create(char* domain);

    bool Close();

    char* Get(char* headers);
};

#endif //WEBAX_HTTPCLIENTSESSION_HPP
