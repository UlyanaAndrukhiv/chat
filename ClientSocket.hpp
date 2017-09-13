#ifndef CLIENTSOCKET_HPP
#define CLIENTSOCKET_HPP

#include <string>
#include <memory>

class ClientSocket
{
public:
    virtual void connectToHost(std::string hostName, int port) = 0;
    virtual std::string read() = 0;
    virtual void write(std::string) = 0;

    static std::unique_ptr<ClientSocket> Create();
};

#endif // CLIENTSOCKET_HPP
