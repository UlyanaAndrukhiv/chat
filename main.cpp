#include <iostream>
#include <string>
#include <exception>
#include "ClientSocket.hpp"
#include "ServerSocket.hpp"
#include <memory>

int chooseServerOrClient()
{
    std::cout << "Run your program (server (1) / client (2)). Please enter a number: ";
    int answer;
    std::cin >> answer;
    while(answer >= 3 || answer <= 0)
    {
        std::cout << "Incorrect data. Please repeat.";
        std::cin >> answer;
    }
    return answer;
}

void runServer()
{
    std::unique_ptr<ServerSocket> server = ServerSocket::Create();
    server->bind(10000);
    auto client = server->accept();

    while(true)
    {
        auto messege = client->read();
        client->write(messege);
    }
}

void runClient()
{
   std::unique_ptr<ClientSocket> client = ClientSocket::Create();
   client->connectToHost("127.0.0.1", 10000);

    std::string messege;
    while(std::cin >> messege)
    {
        client->write(messege);
        std::cout << client->read() << std::endl;
    }
}

int main()
{
    try
    {
        char buff[1024];
        if (WSAStartup(0x202,(WSADATA *) &buff[0]))
        {
            std::cout << "WSAStart error" <<  WSAGetLastError() << std::endl;
        }

        if(chooseServerOrClient() == 1 )
        {
            runServer();
        }
        else
        {
            runClient();
        }
    }
    catch(std::runtime_error& re)
    {
        std::cout << re.what() << '\n';
    }
    WSACleanup();
    return 0;
}
