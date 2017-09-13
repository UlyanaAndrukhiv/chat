#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP
#include "ClientSocket.hpp"
#include "Windows/ClientSocketImpl.hpp"

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <memory>

#pragma comment(lib, "Ws2_32.lib")

class ServerSocket
{
public:
    virtual void bind(int port) = 0;
    virtual std::unique_ptr<ClientSocket> accept() = 0;

    static std::unique_ptr<ServerSocket> Create();
};
#endif // SERVERSOCKET_HPP
