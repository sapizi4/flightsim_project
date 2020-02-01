//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_EXPRESSIONCOMMAND_H
#define FLIGHTSIM_EXPRESSIONCOMMAND_H

#include "Command.h"
#include "Expression.h"

class ExpressionCommand:public Expression{
protected:
    Command *command;
    vector<string> lexer;
    int index{};
public:
    ExpressionCommand(Command *command, vector<string> cur_lex);

    double calculate() override;
};
#endif //FLIGHTSIM_EXPRESSIONCOMMAND_H
