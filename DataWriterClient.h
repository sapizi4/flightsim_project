//
// Created by Sapir on 10/01/2020.
//

#ifndef FLIGHTSIM_PROJECT_DATAWRITERCLIENT_H
#define FLIGHTSIM_PROJECT_DATAWRITERCLIENT_H
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include "Command.h"

#include <string.h>
using namespace std;


class DataWriterClient {
    static string message;
    static int socketFd;
public:
    //static because its depend on state
    static void setMessage(const string &message1);

    static void createConnection(int port, string address);

    inline static int getSocketFD(){
        return socketFd;
    }

};
#endif //FLIGHTSIM_PROJECT_DATAWRITERCLIENT_H
