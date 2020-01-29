#ifndef FLIGHTSIM_PROJECT_CLIENTHANDLER_H
#define FLIGHTSIM_PROJECT_CLIENTHANDLER_H
#define BUFFER_SIZE 1024

#include <istream>
#include <ostream>
#include <thread>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
using namespace std;

//interface that holds all the different clients

class ClientHandler{
public:

    virtual void handleClient(int sockFd)=0;
    ~ClientHandler(){};
};

#endif //FLIGHTSIM_PROJECT_CLIENTHANDLER_H
