//
// Created by Sapir on 19/01/2020.
//

#include "MySerialServer.h"

#define WAIT_FOR_CONNECTION 10
int MySerialServer::sockFd=0;
bool MySerialServer::is_open=false;
ClientHandler* MySerialServer::clientHandler= nullptr;
//open for serial server
void MySerialServer::open(int port, ClientHandler *Ch) {
    //loop that listens to the client on the port we have been given.

}

void MySerialServer::stop() {

}


