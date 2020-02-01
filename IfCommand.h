//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_IFCOMMAND_H
#define FLIGHTSIM_IFCOMMAND_H
#include "ConditionParser.h"

class IfCommand:public Command{
    int &index;
    ConditionParser conditionParser;
public:
    void execute(const vector<string>&lexer) override;
    explicit IfCommand(int &index);
};


#endif //FLIGHTSIM_IFCOMMAND_H
