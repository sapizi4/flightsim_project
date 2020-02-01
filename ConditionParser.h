//
// Created by maor on 29/01/2020.
//

#include "Command.h"
#include "MapDB.h"

class ConditionParser: public Command {
    vector<string>cur_lex;
    int &index;
public:
    void execute(const vector<string>&cur_lex) override;
    bool checkCondition(const vector<string>&cur_lex);
    static bool isBigger(double left,double right);
    static bool isEqual(double left,double right);
    static bool isOperator(const string &oper);
    explicit ConditionParser(int &index);
};