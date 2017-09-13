#include "ServerSocketImpl.hpp"
#include "ServerSocket.hpp"
#include <memory>

ServerSocketImpl::ServerSocketImpl()
{

}

void ServerSocketImpl::bind(int port)
{
    if ((_serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        throw std::runtime_error("A socket error");
    }

    sockaddr_in localAddr;
    localAddr.sin_family = AF_INET;
    localAddr.sin_port = htons(port);
    localAddr.sin_addr.s_addr = 0;

    if (::bind(_serverSocket, reinterpret_cast <sockaddr *> (&localAddr), sizeof(localAddr)))
    {
        throw std::runtime_error("A bind error");
    }

    if (listen(_serverSocket, 20))
    {
        throw std::runtime_error("A listen error");
    }
}

std::unique_ptr<ClientSocket> ServerSocketImpl::accept()
{
    SOCKET clientSocket;
    sockaddr_in clientAddr;

    int clientAddrSize = sizeof(clientAddr);
    clientSocket = ::accept(_serverSocket, reinterpret_cast <sockaddr *> (&clientAddr), &clientAddrSize);

    return std::unique_ptr<ClientSocket>(new ClientSocketImpl(clientSocket));
}

ServerSocketImpl::~ServerSocketImpl()
{
    closesocket(_serverSocket);
}
