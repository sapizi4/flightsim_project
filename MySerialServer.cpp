//
// Created by maor on 24/01/2020.
//

#include "MySerialServer.h"
#include <fstream>
#define WAIT_FOR_CONNECTION 10
int MySerialServer::sockFd=0;
bool MySerialServer::is_open=false;
ClientHandler* MySerialServer::clientHandler= nullptr;
//open for serial server
void MySerialServer::open(int port, ClientHandler *Ch) {
    clientHandler = Ch;
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv{};
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    if (bind(s, (sockaddr *) &serv, sizeof(serv)) < 0) {
        cerr << "Bad!" << endl;
    }
    this->myThread = thread(&MySerialServer::connection,port,s);
    myThread.join();
}

void MySerialServer::stop() {
    is_open = false;
    close(sockFd);
}

void MySerialServer::connection(int port,int s) {
    int new_sock;
    listen(s, 1);
    struct sockaddr_in client{};
    socklen_t clilen = sizeof(client);

    timeval timeout{};
    timeout.tv_sec = WAIT_FOR_CONNECTION;
    timeout.tv_usec = 0;

    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));

    new_sock = accept(s, (struct sockaddr *) &client, &clilen);
    if (new_sock < 0) {
        if (errno == EWOULDBLOCK) {
            cout << "timeout!" << endl;
            exit(2);
        } else {
            perror("other error");
            exit(3);
        }
    }
    is_open = true;
    sockFd = new_sock;
    cout << new_sock << endl;
    cout << s << endl;
    clientHandler->handleClient(sockFd);
    close(sockFd);
}