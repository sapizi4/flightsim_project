//
// Created by maor on 29/01/2020.
//

#include "ConnectCommand.h"
#include "thread"
#include "DataReaderServer.h"
#include "Shuntingyard.h"

void ConnectCommand::execute(const vector<string> &cur_lex) {
    Shuntingyard shuntingYard;
    int port;
    string adress;
    try {
        adress = cur_lex[index + 1];
        port = (int)(Shuntingyard::algorithm(cur_lex[index + 2]));
        index+=3;
    } catch (...) {
        cerr << "ERROR : WRONG PASSING PARAMETERS"<< endl;
        exit(1);
    }

    DataWriterClient::createConnection(port, adress);
}

ConnectCommand::ConnectCommand(int &index):index(index) {
}