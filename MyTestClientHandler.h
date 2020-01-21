
#ifndef FLIGHTSIM_PROJECT_MYTESTCLIENTHANDLER_H
#define FLIGHTSIM_PROJECT_MYTESTCLIENTHANDLER_H
#include "ClientHandler.h"
//foundation check for the future
class MyTestClientHandler: public ClientHandler{
    Solver<string,string>* solver;
    CacheManager<string,string>* cacheManager;
public:
    MyTestClientHandler(CacheManager<string, string> *pManager, Solver<string, string> *pSolver);
    void handleClient(int sockFd);
    void writeTheSolution(int id, const char* buffer);
};
#endif //FLIGHTSIM_PROJECT_MYTESTCLIENTHANDLER_H
