//
// Created by maor on 29/01/2020.
//

/*#include "OpenServerCommand.h"
#include <iostream>
#include <thread>
#include "Shuntingyard.h"



void OpenServerCommand::execute(const vector<string>&cur_lex) {
    Shuntingyard shuntingyard;
    int port, freq;
    try {
        //shunting yard algorithm returns double..
        port = (int)Shuntingyard::algorithm(cur_lex[index + 1]);
        freq = (int)Shuntingyard::algorithm(cur_lex[index + 2]);
        index += 3;
    } catch (...) {
        cerr << "ERROR : WRONG PASSING PARAMETERS" << endl;
        exit(1);
    }
    thread t(&DataReaderServer::openServer, port, freq);
    while (!DataReaderServer::isOpen()){
        //wait..
    }
    t.detach();
}

OpenServerCommand::OpenServerCommand(int &index):index(index) {

}*/