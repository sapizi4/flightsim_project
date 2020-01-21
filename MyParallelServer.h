//
// Created by Sapir on 19/01/2020.
//

#ifndef FLIGHTSIM_PROJECT_MYPARALLELSERVER_H
#define FLIGHTSIM_PROJECT_MYPARALLELSERVER_H
#include "Server.h"

using namespace std;
using namespace server_side;

class MyParallelServer:public Server{
    static ClientHandler* clientHandler;

public:
    ~MyParallerServer();
    void open(int port,ClientHandler* clientHandler);
    void stop();

};
#endif //FLIGHTSIM_PROJECT_MYPARALLELSERVER_H
