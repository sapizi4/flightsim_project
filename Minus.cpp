//
// Created by maor on 29/01/2020.
//

#include "Minus.h"
Minus::Minus(Expression* left, Expression* right) : BinaryExpression(left, right) {}
Minus::~Minus() = default;
double Minus::calculate() {
    return this->left->calculate() - this->right->calculate();
};
