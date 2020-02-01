//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_MAIN_H
#define FLIGHTSIM_MAIN_H

#include "MyParallelServer.h"
#include "Solver.h"
#include "Searcher.h"
#include "CacheManager.h"
#include "A_Star.h"
#include "FileCacheManager.h"
#include "MatrixSolver.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"

namespace boot {
    class Main {
    public:
        static int main(int argc, char *argv[]) {
            //if there are not 2 args that past to the main
            if (argc != 2) {
                cout << "wrong passing parameters";
                exit(4);
            }
            int port = stoi(argv[1]);
            //Server *myServer = new MyParallelServer();
            Server *myServer = new MySerialServer();
            Searcher<string> *searcher = new A_Star<string>();
            Solver<string, string> *solver = new MatrixSolver<string, string, string>(searcher);
            CacheManager<string, string> *cache = new FileCacheManager<string, string>();
            ClientHandler *client = new MyTestClientHandler(cache, solver);
            //open new server by the port and client
            myServer->open(port, client);

            return 0;
        }
        ~Main() = default;
    };
}
#endif //FLIGHTSIM_MAIN_H
