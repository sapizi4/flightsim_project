#ifndef FLIGHTSIM_PROJECT_SERVER_H
#define FLIGHTSIM_PROJECT_SERVER_H
#define BUFFER_SIZE 1024
#include "ClientHandler.h"
#include <iostream>
using namespace std;
//creating new namespace
namespace server_side{
    //Client struct
    struct client_params{
        ClientHandler *clientHandler;
        int newSockFd;

    };

    //server interface
    class Server{
    public:
        virtual void open(int port,ClientHandler* clientHandler)=0;
        virtual void stop()=0;
        ~Server()= default;
    };
}
#endif //FLIGHTSIM_PROJECT_SERVER_H
