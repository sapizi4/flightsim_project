//
// Created by maor on 24/01/2020.
//י
#include "MyParallelServer.h"
#include <pthread.h>

int MyParallelServer::sockFd=0;
bool MyParallelServer::is_open=false;
/**
 * handle with clients
 */
void* MyParallelServer:: handle(void* args) {
    auto* clientStruct=(struct client_params*) args;
    //Handle client
    clientStruct->clientHandler->handleClient(clientStruct->newSockFd);
    return nullptr;
}

/**
 * open multiple threads to clients - max 5
 */
void MyParallelServer::open(int port, ClientHandler *ch) {
    int sockfd, portno;
    struct sockaddr_in serv_addr{};
    auto* clientStruct = new client_params();
    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    clientStruct->clientHandler = ch;
    // Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = port;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }
    struct sockaddr_in cli_addr{};
    int clilen, newSockFd;
    listen(sockfd, MAX_CLIENTS);
    clilen = sizeof(cli_addr);

    timeval timeout{};
    timeval timeoutCli{};

    while (true) {
        printf("\n before");
        fflush(stdout);
        newSockFd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

        printf("\n after ");
        fflush(stdout);

        timeout.tv_usec = 0;
        timeout.tv_sec = 10;
        timeval timeForever{};
        timeForever.tv_sec = WAIT_FOREVER;
        timeForever.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));
        clientStruct->newSockFd = newSockFd;
        sockFd = newSockFd;
        if (newSockFd < 0) {
            if (errno == EWOULDBLOCK) {
                cout << "timeout!" << endl;
                stop();
                delete clientStruct;
                break;

            } else {
                perror("error reading from socket");
                stop();
                delete clientStruct;
                break;
            }
        }
        pthread_t pthread;
        if (pthread_create(&pthread, nullptr, MyParallelServer::handle, clientStruct) != 0) {
            perror("failure in thread create");
        }
        setsockopt(newSockFd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeForever, sizeof(timeForever));
        this->threads_created.push_back(pthread);
    }

}
void MyParallelServer::stop() {
    for (unsigned long thread : this->threads_created) {
        pthread_join(thread, nullptr);
    }
}
MyParallelServer:: ~MyParallelServer() {
    close(MyParallelServer::sockFd);
}
