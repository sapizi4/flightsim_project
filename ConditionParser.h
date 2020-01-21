

#ifndef FLIGHTSIM_PROJECT_CONDITIONPARSER_H
#define FLIGHTSIM_PROJECT_CONDITIONPARSER_H
#include "Command.h"
#include "MapDB.h"

class ConditionParser: public Command {
    vector<string>cur_lex;
    int &index;
public:
    void execute(const vector<string>&cur_lex);
    bool checkCondition(const vector<string>&cur_lex);
    bool isBigger(double left,double right);
    bool isEqual(double left,double right);
    bool isOperator(const string &oper);
    explicit ConditionParser(int &index);
};
#endif //FLIGHTSIM_PROJECT_CONDITIONPARSER_H
