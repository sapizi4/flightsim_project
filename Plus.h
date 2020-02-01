//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_PLUS_H
#define FLIGHTSIM_PLUS_H
#include "BinaryExpression.h"
#include "Expression.h"

class Plus : public BinaryExpression {
public:
    Plus(Expression *left, Expression *right);

    virtual ~Plus();

    double calculate() override;
};


#endif //FLIGHTSIM_PLUS_H
