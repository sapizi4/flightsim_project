//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_CONNECTCOMMAND_H
#define FLIGHTSIM_CONNECTCOMMAND_H
#include "Command.h"
#include <string>
#include <cstdio>
#include <cstdlib>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <sys/socket.h>
#include "thread"
#include "DataReaderServer.h"
#include "DataWriterClient.h"

class ConnectCommand:public Command{
    int &index;
public:
    void execute(const vector<string>&cur_lex) override;
    explicit ConnectCommand(int &index);
};
#endif //FLIGHTSIM_CONNECTCOMMAND_H
