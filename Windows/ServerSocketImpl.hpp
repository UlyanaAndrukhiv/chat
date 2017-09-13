#ifndef SERVERSOCKETIMPL_HPP
#define SERVERSOCKETIMPL_HPP
#define WIN32_LEAN_AND_MEAN

#include "ServerSocket.hpp"
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <memory>

#pragma comment(lib, "Ws2_32.lib")

class ServerSocketImpl : ServerSocket
{
public:
    ServerSocketImpl();
    virtual void bind(int port) override;
    virtual std::unique_ptr<ClientSocket> accept() override;
    ~ServerSocketImpl();

private:
    SOCKET _serverSocket;
};

#endif // SERVERSOCKETIMPL_HPP
