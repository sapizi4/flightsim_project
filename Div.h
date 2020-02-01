//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_DIV_H
#define FLIGHTSIM_DIV_H
#include "BinaryExpression.h"
#include "Expression.h"

/**
 * div operator class
 */
class Div : public BinaryExpression {
public:
    Div(Expression *left, Expression *right);

    virtual ~Div();

    double calculate() override;
};



#endif //FLIGHTSIM_DIV_H
