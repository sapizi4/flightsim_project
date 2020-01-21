
#ifndef EX3_BINARYEXPRESSION_H
#define EX3_BINARYEXPRESSION_H

#include "Number.h"

using namespace std;

class BinaryExpression: public Expression {
protected:
    Expression* right;
    Expression* left;
public:
    virtual double calculate()=0;

};

#endif //EX3_BINARYEXPRESSION_H
