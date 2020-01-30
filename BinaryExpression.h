
#ifndef FLIGHTSIM_PROJECT_BINARYEXPRESSION_H
#define FLIGHTSIM_PROJECT_BINARYEXPRESSION_H

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
#endif //FLIGHTSIM_PROJECT_BINARYEXPRESSION_H
