//
// Created by anerruption on 9/29/21.
//

#ifndef WEBAX_NETWORKTEST1_HPP
#define WEBAX_NETWORKTEST1_HPP

#include <sys/socket.h>

class NetworkTest1
{
public:
    static int server_fd, new_socket, opt, addrlen, status;
    static struct sockaddr_in address;

    static bool Execute();

    static void LaunchClient();
    static void FinishServerLaunch();
};

#endif //WEBAX_NETWORKTEST1_HPP
