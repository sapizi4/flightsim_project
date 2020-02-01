//
// Created by maor on 24/01/2020.
//

#ifndef FLIGHTSIM_MYSERIALSERVER_H
#define FLIGHTSIM_MYSERIALSERVER_H
#include "Server.h"
using namespace server_side;

class MySerialServer:public Server{
    static ClientHandler* clientHandler;
    thread myThread;
    static int sockFd;
    static bool is_open;
public:
    static void connection(int port,int s);
    void open(int port,ClientHandler* clientHandler) override;
    void stop() override;
    inline static bool isOpen(){
        return is_open;
    }

};

#endif //FLIGHTSIM_MYSERIALSERVER_H
