//
// Created by maor on 29/01/2020.
//

#include "MapDB.h"
// update or add command into map
void MapDB::addCommand(const string& varName, ExpressionCommand *command){
    this->commandTable[varName] = command;
}

ExpressionCommand* MapDB::getCommand(const string &CommandName) {
    if(this->commandTable.count(CommandName) ==  1)
        return this->commandTable[CommandName];
    else
        return nullptr;
}

