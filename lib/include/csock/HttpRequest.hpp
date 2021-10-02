//
// Created by anerruption on 9/30/21.
//

#ifndef WEBAX_HTTPREQUEST_HPP
#define WEBAX_HTTPREQUEST_HPP

#include "HttpClientSession.hpp"

class HttpRequest
{
public:
    static char* Get(HttpClientSession session, char* headers);
};

#endif //WEBAX_HTTPREQUEST_HPP
