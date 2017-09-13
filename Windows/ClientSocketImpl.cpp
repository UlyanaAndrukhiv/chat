#include "ClientSocketImpl.hpp"
#include "ClientSocket.hpp"
#include <iostream>
#include <exception>
#include <functional>
#include <memory>

ClientSocketImpl::ClientSocketImpl()
{

}
ClientSocketImpl::ClientSocketImpl(size_t socket)
{
    _clientSocket = static_cast<SOCKET>(socket);
}

void ClientSocketImpl::connectToHost(std::string hostName, int port)
{
    _clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(_clientSocket < 0)
    {
        throw std::runtime_error("A runtime error");
    }

    sockaddr_in destAddr;
    destAddr.sin_family = AF_INET;
    destAddr.sin_port = htons(port);
    HOSTENT *hst;

    if (inet_addr(hostName.c_str()) != INADDR_NONE)
        destAddr.sin_addr.s_addr = inet_addr(hostName.c_str());
    else
        if (hst = gethostbyname(hostName.c_str()))
            (reinterpret_cast <unsigned long *>(&destAddr.sin_addr)[0])=
                (reinterpret_cast <unsigned long **>(hst->h_addr_list)[0][0]);
        else
        {
            throw std::runtime_error("Invalid address");
        }

    int iResult = connect(_clientSocket, reinterpret_cast <sockaddr *> (&destAddr), sizeof(destAddr));
    if (iResult == SOCKET_ERROR)
    {
        throw  std::runtime_error("Invalid socket");
    }
    std::cout << "Connect " << hostName.c_str() <<" successfull" << std::endl
              << "Type quit for quit" << std::endl;
}

std::string ClientSocketImpl::read()
{
    static const int BUFLEN  = 512;
    char buff[BUFLEN];
    int nSize;

    while((nSize = recv(_clientSocket, &buff[0], sizeof(buff) - 1, 0)) != SOCKET_ERROR)
    {
        buff[nSize] = 0;
        return std::string(buff);
    }
}

void ClientSocketImpl::write(std::string sendBuffer)
{
    int iResult = send(_clientSocket, sendBuffer.c_str(), (int)sendBuffer.length(), 0);
    if (iResult == SOCKET_ERROR)
    {
        throw std::runtime_error("A runtime error");
    }
}

ClientSocketImpl::~ClientSocketImpl()
{
    closesocket(_clientSocket);
}


