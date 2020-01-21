//
// Created by Sapir on 19/01/2020.
//

#ifndef FLIGHTSIM_PROJECT_MYSERIALSERVER_H
#define FLIGHTSIM_PROJECT_MYSERIALSERVER_H
#include "Server.h"
using namespace server_side;

class MySerialServer:public Server{
    static ClientHandler* clientHandler;
public:
    void open(int port,ClientHandler* clientHandler);
    void stop();

};
#endif //FLIGHTSIM_PROJECT_MYSERIALSERVER_H
