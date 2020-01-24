//
// Created by Sapir on 19/01/2020.
//

#ifndef FLIGHTSIM_PROJECT_MYSERIALSERVER_H
#define FLIGHTSIM_PROJECT_MYSERIALSERVER_H
#include "Server.h"
using namespace server_side;

class MySerialServer:public Server{
    static ClientHandler* clientHandler;
    thread myThread;
    static int sockFd;
    static bool is_open;
public:
    static void connection(int port,int s);
    void open(int port,ClientHandler* clientHandler);
    void stop();
    inline static bool isOpen(){
        return is_open;
    }

};
#endif //FLIGHTSIM_PROJECT_MYSERIALSERVER_H
