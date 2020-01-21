
#ifndef FLIGHTSIM_PROJECT_DIV_H
#define FLIGHTSIM_PROJECT_DIV_H

#include "BinaryExpression.h"
#include "Plus.h"

using namespace std;

class Div: public BinaryExpression {
public:
    Div(Number val1,Number val2);
    Div(Expression* val1,Number val2);
    Div(Number val1, Expression* val2);
    Div(Expression* val1,Expression* val2);
    double calculate();
    ~Div();

};

#endif //FLIGHTSIM_PROJECT_DIV_H
