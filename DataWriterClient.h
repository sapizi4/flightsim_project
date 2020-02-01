//
// Created by maor on 24/01/2020.
//

#ifndef FLIGHTSIM_DATAWRITERCLIENT_H
#define FLIGHTSIM_DATAWRITERCLIENT_H

#include <cstdio>
#include <cstdlib>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "Command.h"
#include <cstring>
using namespace std;


class DataWriterClient {
    static string message;
    static int socketFd;
public:
    //static because its depend on state
    static void setMessage(const string &message1);

    static void createConnection(int port, const string& address);

    inline static int getSocketFD(){
        return socketFd;
    }

};
#endif //FLIGHTSIM_DATAWRITERCLIENT_H
