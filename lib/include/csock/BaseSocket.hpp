//
// Created by anerruption on 9/29/21.
//

#ifndef WEBAX_BASESOCKET_HPP
#define WEBAX_BASESOCKET_HPP

#include <cstddef>

class BaseSocket
{
public:
#if defined(_WIN32) || defined(_WIN64)

#include "unix/BaseSocketWindows.hpp"
    BaseSocketWindows socket;

#else

#include "unix/BaseSocketUnix.hpp"
"cstddef"

    BaseSocketUnix socket;

#endif

    bool Open();
    bool Close();

    bool Send(char* buffer, size_t bytes);
    char* Receive(size_t count);
    char* ReceiveAll();
};

#endif //WEBAX_BASESOCKET_HPP
