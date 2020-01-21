
#ifndef FLIGHTSIM_PROJECT_PRINTCOMMAND_H
#define FLIGHTSIM_PROJECT_PRINTCOMMAND_H
#include "Command.h"

class PrintCommand:public Command{
    int &index;
    string str;
public:
    void execute(const vector<string>&cur_lex);
    PrintCommand(int &index);
};
#endif //FLIGHTSIM_PROJECT_PRINTCOMMAND_H
