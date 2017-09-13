#ifndef CLIENTSOCKETIMPL_HPP
#define CLIENTSOCKETIMPL_HPP

#define WIN32_LEAN_AND_MEAN
#include "ClientSocket.hpp"
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

class ClientSocketImpl : public ClientSocket
{
public:
    ClientSocketImpl();
    ClientSocketImpl(size_t socket);
    virtual void connectToHost(std::string hostName, int port) override;
    virtual std::string read() override;
    virtual void write(std::string) override;
    ~ClientSocketImpl();

private:
    SOCKET _clientSocket;
};

#endif // CLIENTSOCKETIMPL_HPP
