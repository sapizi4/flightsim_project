//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_MAPDB_H
#define FLIGHTSIM_MAPDB_H
#include <map>
#include <string>
#include "Command.h"
#include "ExpressionCommand.h"

using namespace std;
/*
 * class created in order to store var and their current values.
 */
class MapDB {
    map<string,ExpressionCommand*> commandTable;
    map<string,double> valuesTable;
    map<string,string> bindTable;
    map<string,double> bindValuesTable;
public:
    MapDB() = default;

    map<string, ExpressionCommand *> &getCommandTable() { return commandTable; }

    map<string, double> &getValuesTable() { return valuesTable; }

    map<string, string> &getBindTable() { return bindTable; }

    map<string, double> &getBindValuesTable() { return bindValuesTable; }
    void addCommand(string varName, ExpressionCommand* command);
    ExpressionCommand* getCommand(const string &CommandName);

    void addCommand(const string &varName, ExpressionCommand *command);
};

#endif //FLIGHTSIM_MAPDB_H
