//
// Created by anerruption on 9/29/21.
//

#ifndef WEBAX_IO_HPP
#define WEBAX_IO_HPP

class NetworkManager
{
public:
    static char* GetResponse(char* address, int port, char* buffer);
};

#endif //WEBAX_IO_HPP
