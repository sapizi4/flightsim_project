//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_PRINTCOMMAND_H
#define FLIGHTSIM_PRINTCOMMAND_H
#include "Command.h"

class PrintCommand:public Command{
    int &index;
    string str;
public:
    void execute(const vector<string>&cur_lex) override;
    explicit PrintCommand(int &index, int &i);
};

#endif //FLIGHTSIM_PRINTCOMMAND_H
