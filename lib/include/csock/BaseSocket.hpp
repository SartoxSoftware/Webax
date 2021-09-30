//
// Created by anerruption on 9/29/21.
//

#ifndef WEBAX_BASESOCKET_HPP
#define WEBAX_BASESOCKET_HPP

#include <cstddef>

#include "windows/BaseSocketWindows.hpp"
#include "unix/BaseSocketUnix.hpp"

class BaseSocket
{
public:
#if defined(_WIN32) || defined(_WIN64)
    BaseSocketWindows socket;
#else
    BaseSocketUnix socket;
#endif

    bool Open();
    bool Close();

    bool Send(char* buffer, size_t bytes);
    char* Receive(size_t count);
    char* ReceiveAll();
};

#endif //WEBAX_BASESOCKET_HPP
