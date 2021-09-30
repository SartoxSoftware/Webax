//
// Created by anerruption on 9/29/21.
//

#include "include/NetworkTest1.hpp"
#include "../include/IO.hpp"

#include <thread>
#include <unistd.h>
#include <sys/socket.h>
#include <cstdlib>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>

#define PORT 1035

bool NetworkTest1::Execute()
{
    address = sockaddr_in();
    addrlen = sizeof(address);
    opt = 1;
       
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        std::cout << "Failed to create socket." << std::endl;
        return false;
    }
       
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        std::cout << "setsockopt() error." << std::endl;
        return false;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
       
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        std::cout << "Failed to bind socket." << std::endl;
        return false;
    }
    
    std::thread serverThread(FinishServerLaunch);
    std::thread clientThread(LaunchClient);

    while (status < 2);

    return true;
}

void NetworkTest1::LaunchClient()
{
    char* buffer = NetworkManager::GetResponse("127.0.0.1", PORT, "Test1234 5678 ù^$*éé");
    char* compare = "Hello, World!";

    if (strcmp(buffer, compare) != 0)
    {
        std::cout << "Received buffer is invalid (client)." << std::endl;
    }

    free(buffer);

    status++;
}

void NetworkTest1::FinishServerLaunch()
{
    if (listen(server_fd, 3) < 0)
    {
        std::cout << "Can't listen to upcoming sockets." << std::endl;
        return;
    }
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address,(socklen_t*)&addrlen)) < 0)
    {
        std::cout << "Can't accept upcoming sockets." << std::endl;
        return;
    }

    char* buffer = (char*)malloc(20);

    read(new_socket, buffer, 20);
    char* compare = "Test1234 5678 ù^$*éé";

    if (strcmp(buffer, compare) != 0)
    {
        std::cout << "Received buffer is invalid (server)." << std::endl;
    }

    free(buffer);
    send(new_socket, "Hello, World!", 13, 0);

    status++;
}