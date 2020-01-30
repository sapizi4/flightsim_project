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
    MyParallelServer myParallelServer;
    Searcher<pair<int, int>, string> *searcherInterface = new DFS<pair<int, int>, string>;
    GraphSearcher<Searchable<pair<int, int>> *, string, pair<int, int>> *solver
            = new GraphSearcher<Searchable<pair<int, int>> *, string, pair<int, int>>(searcherInterface);
    CacheManager<string, string> *cacheManager = new FileCacheManager;
    ClientHandler *clientHandler = new ClientHandler(solver, cacheManager);
    myParallelServer.open(port, clientHandler);

    return 0;
}
