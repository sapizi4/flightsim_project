//
// Created by maor on 24/01/2020.
//

#ifndef FLIGHTSIM_MYTESTCLIENTHANDLER_H
#define FLIGHTSIM_MYTESTCLIENTHANDLER_H
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
//foundation check for the future
class MyTestClientHandler: public ClientHandler{
    Solver<string,string>* solver;
    CacheManager<string,string>* cacheManager;
public:
    MyTestClientHandler(CacheManager<string, string> *pManager, Solver<string, string> *pSolver);
    void handleClient(int sockFd) override;
    //void writeTheSolution(int id, const char* buffer);
};
#endif //FLIGHTSIM_MYTESTCLIENTHANDLER_H
