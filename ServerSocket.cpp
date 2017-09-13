#include "ServerSocket.hpp"
#include "Windows/ServerSocketImpl.hpp"

std::unique_ptr<ServerSocket> ServerSocket::Create()
{
    return std::unique_ptr<ServerSocket>(new ServerSocketImpl);
}
