//
// Created by Sapir on 19/01/2020.
//

#ifndef FLIGHTSIM_PROJECT_MYPARALLELSERVER_H
#define FLIGHTSIM_PROJECT_MYPARALLELSERVER_H
#include "Server.h"
#include "vector"
using namespace std;
using namespace server_side;

class MyParallelServer:public Server{
    static ClientHandler* clientHandler;
    static int sockFd;
    static bool is_open;
    vector<pthread_t>threads_created;
public:
    ~MyParallerServer();
    void open(int port,ClientHandler* clientHandler);
    void stop();
    static void* handle(void *args);
    static void* connection(void *args);
    inline static bool isOpen(){
        return is_open;
    }

};
#endif //FLIGHTSIM_PROJECT_MYPARALLELSERVER_H
