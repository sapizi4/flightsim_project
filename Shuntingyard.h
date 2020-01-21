#ifndef FLIGHTSIM_PROJECT_SHUNTINGYARD_H
#define FLIGHTSIM_PROJECT_SHUNTINGYARD_H
#include <string>
#include "SymbolTable.h"
#include "Expression.h"
#include "Number.h"
#include "Mul.h"
#include "Plus.h"
#include "Minus.h"
#include "Div.h"
#include <algorithm>
#include <stack>

using namespace std;


class Shuntingyard {
public:
    Shuntingyard();
    double algorithm(string exp);
    bool isOperator(char c);
    bool isDigit(char c);
    unsigned int precedence(char op);
    string extract_string(const string& str);
    ~Shuntingyard();
    bool check_if_neg(const string &exp);
    Expression *string_to_exp(vector<string> shunt_string);
};

#endif //FLIGHTSIM_PROJECT_SHUNTINGYARD_H
