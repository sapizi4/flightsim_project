
#ifndef FLIGHTSIM_PROJECT_IFCOMMAND_H
#define FLIGHTSIM_PROJECT_IFCOMMAND_H
#include "ConditionParser.h"

class IfCommand:public Command{
    int &index;
    ConditionParser conditionParser;
public:
    void execute(const vector<string>&lexer);
    IfCommand(int &index);
};

#endif //FLIGHTSIM_PROJECT_IFCOMMAND_H
