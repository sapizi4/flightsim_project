//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_SLEEPCOMMAND_H
#define FLIGHTSIM_SLEEPCOMMAND_H
#include "Command.h"

class SleepCommand:public Command{
    int &index;
public:
    void execute(const vector<string>&cur_lex) override;
    explicit SleepCommand(int &index);
};
#endif //FLIGHTSIM_SLEEPCOMMAND_H
