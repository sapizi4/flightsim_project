//
// Created by maor on 29/01/2020.
//

#include "Plus.h"

Plus::Plus(Expression *left, Expression *right) : BinaryExpression(left, right) {}

Plus::~Plus() = default;

double Plus::calculate() {
    return this->left->calculate() + this->right->calculate();
}