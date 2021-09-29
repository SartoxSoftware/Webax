//
// Created by anerruption on 9/29/21.
//

#ifndef WEBAX_BASESOCKETUNIX_HPP
#define WEBAX_BASESOCKETUNIX_HPP

#include <cstddef>

class BaseSocketUnix
{
public:
    char* address;
    int port, sock;

    bool Open();
    bool Close();

    bool Send(char* buffer, size_t bytes);
    char* Receive(size_t count);
    char* ReceiveAll();
};

#endif //WEBAX_BASESOCKETUNIX_HPP
