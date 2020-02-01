
//
// Created by maor on 24/01/2020.
//

#ifndef UNTITLED5_MYPARALLELSERVER_H
#define UNTITLED5_MYPARALLELSERVER_H
#define WAIT_FOR_CLIENT 1
#define WAIT_FOREVER 0
#define MAX_CLIENTS 5
#include "Server.h"
#include "vector"
using namespace std;
using namespace server_side;

class MyParallelServer:public Server{
    static ClientHandler* clientHandler;
    //stateful
    static int sockFd;
    static bool is_open;
    vector<pthread_t>threads_created;
public:
    ~MyParallelServer();
    static void* handle(void *args);
    void open(int port,ClientHandler* clientHandler) override;
    void stop() override;
    //static void* connection(void *args);
    inline static bool isOpen(){
        return is_open;
    }
};
#endif //UNTITLED5_MYPARALLELSERVER_H
