
#ifndef FLIGHTSIM_PROJECT_DEFINEVARCOMMAND_H
#define FLIGHTSIM_PROJECT_DEFINEVARCOMMAND_H


#include "Command.h"
#include "string"
#include "MapDB.h"
#include "Expression.h"

class DefineVarCommand : public Command {
    int &index;
    string name;
    string bindPath;
    Expression* expression = nullptr;
    MapDB* db;
public:
    void execute(const vector<string>&cur_lex);
    DefineVarCommand(int &index);
};
#endif //FLIGHTSIM_PROJECT_DEFINEVARCOMMAND_H
