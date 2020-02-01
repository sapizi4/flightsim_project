//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_MINUS_H
#define FLIGHTSIM_MINUS_H
#include "BinaryExpression.h"
#include "Number.h"
#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression *left, Expression *right);

    virtual ~Minus();

    double calculate() override;
};

#endif //FLIGHTSIM_MINUS_H
