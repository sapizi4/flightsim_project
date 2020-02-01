//
// Created by maor on 29/01/2020.
//


#include "Mul.h"

Mul::Mul(Expression *left, Expression *right) : BinaryExpression(left, right) {}

Mul::~Mul() =default;

double Mul::calculate() {
    return this->left->calculate() * this->right->calculate();
}