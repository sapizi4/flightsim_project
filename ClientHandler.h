#ifndef FLIGHTSIM_PROJECT_CLIENTHANDLER_H
#define FLIGHTSIM_PROJECT_CLIENTHANDLER_H
#define BUFFER_SIZE 1024

#include <istream>
#include <ostream>
#include <thread>
#include <cstdlib>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <sys/socket.h>
using namespace std;

//interface that holds all the different clients

class ClientHandler{
public:

    virtual void handleClient(int sockFd)=0;
    ~ClientHandler()= default;;
};

#endif //FLIGHTSIM_PROJECT_CLIENTHANDLER_H
