//
// Created by maor on 29/01/2020.
//
#include "MyParallelServer.h"
#include "Searcher.h"
#include "A_Star.h"
#include "CacheManager.h"
#include "ClientHandler.h"
#include "DFS.h"
#include "BFS.h"
#include "FileCacheManager.h"

int main(int argc, char *argv[]) {

    int port = stoi(argv[1]);
    MyParallelServer myParallelServer
    Searcher<int>, string> *searcherInterface = new DFS< int>, string>;
    GraphSearcher<Searchable<int>> *, string, int> *solver
            = new GraphSearcher<Searchable< int>> *, string, int>(searcherInterface);
    CacheManager<string> *cacheManager = new FileCacheManager;
    ClientHandler *clientHandler = new ClientHandler(sockFd);
    myParallelServer.open(port, clientHandler);

    return 0;
}

