
#ifndef FLIGHTSIM_PROJECT_LOOPCOMMAND_H
#define FLIGHTSIM_PROJECT_LOOPCOMMAND_H
#include "ConditionParser.h"

class LoopCommand:public Command{
    int &index;
    ConditionParser conditionParser;
    map<string,Expression*>&command_map;
    bool first_iteration;
    list<Expression*>commands;
public:
    LoopCommand(map<string,Expression*>&command_map,int &index);
    void execute(const vector<string>&lexer);
    void commands_in_loop(const vector<string>cur_lex,int &index);
};

#endif //FLIGHTSIM_PROJECT_LOOPCOMMAND_H
