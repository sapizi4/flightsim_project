
#ifndef FLIGHTSIM_PROJECT_BINARYEXPRESSION_H
#define FLIGHTSIM_PROJECT_BINARYEXPRESSION_H

#include "Number.h"

using namespace std;

class BinaryExpression: public Expression {
protected:
    Expression* right;
    Expression* left;
public:
    virtual double calculate()=0;

};

#endif //FLIGHTSIM_PROJECT_BINARYEXPRESSION_H
