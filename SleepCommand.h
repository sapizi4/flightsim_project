
#ifndef FLIGHTSIM_PROJECT_SLEEPCOMMAND_H
#define FLIGHTSIM_PROJECT_SLEEPCOMMAND_H
#include "Command.h"

class SleepCommand:public Command{
    int &index;
public:
    void execute(const vector<string>&cur_lex);
    SleepCommand(int &index);
};
#endif //FLIGHTSIM_PROJECT_SLEEPCOMMAND_H
