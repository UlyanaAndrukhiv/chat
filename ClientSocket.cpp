#include "ClientSocket.hpp"
#include "Windows/ClientSocketImpl.hpp"
#include <memory>

std::unique_ptr<ClientSocket> ClientSocket::Create()
{
    return std::unique_ptr<ClientSocket>(new ClientSocketImpl);
}
