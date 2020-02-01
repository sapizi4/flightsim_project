//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_BINARYEXPRESSION_H
#define FLIGHTSIM_BINARYEXPRESSION_H
#include "Number.h"

using namespace std;

class BinaryExpression: public Expression {
protected:
    BinaryExpression(Expression *left, Expression *right);

    Expression* right{};
    Expression* left{};
public:
    double calculate() override =0;

};

#endif //FLIGHTSIM_BINARYEXPRESSION_H
