#ifndef CLIENTSOCKETPIMPL_HPP
#define CLIENTSOCKETPIMPL_HPP


#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

class ClientSocketPimpl
{
public:
    ClientSocketPimpl();
    ~ClientSocketPimpl();
private:
    SOCKET _clientSocket;
};

#endif // CLIENTSOCKETPIMPL_HPP
