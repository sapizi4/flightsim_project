//
// Created by maor on 29/01/2020.
//

#include "IfCommand.h"
void IfCommand::execute(const vector<string> &lexer){
    if (conditionParser.checkCondition(lexer))    {
        while(lexer[index] != "}") {
            index++;
        }
    }
}

IfCommand::IfCommand(int &index):index(index),conditionParser(this->index){}