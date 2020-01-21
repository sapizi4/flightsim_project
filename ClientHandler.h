#ifndef FLIGHTSIM_PROJECT_CLIENTHANDLER_H
#define FLIGHTSIM_PROJECT_CLIENTHANDLER_H
using namespace std;

//interface that holds all the different clients

class ClientHandler{
public:

    virtual void handleClient(InputStream in, Outputstream out)=0;
    ~ClientHandler(){};
};

#endif //FLIGHTSIM_PROJECT_CLIENTHANDLER_H
