//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_MUL_H
#define FLIGHTSIM_MUL_H
#include "BinaryExpression.h"
#include "Expression.h"

class Mul : public BinaryExpression {
public:
    Mul(Expression *left, Expression *right);

    virtual ~Mul();

    double calculate() override;
};

#endif //FLIGHTSIM_MUL_H
