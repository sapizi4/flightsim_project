
#ifndef FLIGHTSIM_PROJECT_PLUS_H
#define FLIGHTSIM_PROJECT_PLUS_H


#include "BinaryExpression.h"
#include "Number.h"

using namespace std;

class Plus: public BinaryExpression{
public:
    Plus(Number val1,Number val2);
    Plus(Expression* val1,Number val2);
    Plus(Number val1, Expression* val2);
    Plus(Expression* val1,Expression* val2);
    double calculate();
    ~Plus();

};

#endif //FLIGHTSIM_PROJECT_PLUS_H
