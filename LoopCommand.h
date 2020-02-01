//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_LOOPCOMMAND_H
#define FLIGHTSIM_LOOPCOMMAND_H
#include "ConditionParser.h"

class LoopCommand:public Command{
    int &index;
    ConditionParser conditionParser;
    map<string,Expression*>&command_map;
    bool first_iteration{};
    list<Expression*>commands;
public:
    LoopCommand(map<string,Expression*>&command_map,int &index);
    void execute(const vector<string>&lexer) override;
    void commands_in_loop(const vector<string>&cur_lex,int &i);
};


#endif //FLIGHTSIM_LOOPCOMMAND_H
