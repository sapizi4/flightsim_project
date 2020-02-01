//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_SHUNTINGYARD_H
#define FLIGHTSIM_SHUNTINGYARD_H

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
#include <vector>

using namespace std;


class Shuntingyard {
public:
    Shuntingyard();
    static double algorithm(string exp);
    static bool isOperator(char c);
    static bool isDigit(char c);
    static unsigned int precedence(char op);
    static string extract_string(const string& str);
    ~Shuntingyard();
    static bool check_if_neg(const string &exp);
    static Expression *string_to_exp(const std::vector<string> &shunt_vec);
};

#endif //FLIGHTSIM_SHUNTINGYARD_H
