//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_DEFINEVARCOMMAND_H
#define FLIGHTSIM_DEFINEVARCOMMAND_H
#include "Command.h"
#include "string"
#include "MapDB.h"
#include "Expression.h"

class DefineVarCommand : public Command {
    int &index;
    string name;
    string bindPath;
    Expression* expression = nullptr;
    MapDB* db{};
public:
    void execute(const vector<string>&cur_lex) override;
    explicit DefineVarCommand(int &index);
};
#endif //FLIGHTSIM_DEFINEVARCOMMAND_H
