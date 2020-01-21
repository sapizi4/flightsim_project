
#ifndef FLIGHTSIM_PROJECT_PARSER_H
#define FLIGHTSIM_PROJECT_PARSER_H

#include <vector>
#include <string>
#include <map>
#include "Command.h"
#include "OpenServerCommand.h"
#include "ConnectCommand.h"
#include "DefineVarCommand.h"
#include "MapDB.h"
#include "IfCommand.h"
#include "LoopCommand.h"
#include "PrintCommand.h"
#include "SleepCommand.h"
#include "AssignCommand.h"


class Parser{
    map<string, Expression *> commandsTable;
    int &index;
public:
    Parser(const vector<string>&cur_lex,int& index);
    void run(const vector<string> &cur_lex);

};
#endif //FLIGHTSIM_PROJECT_PARSER_H
