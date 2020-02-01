//
// Created by maor on 29/01/2020.
//

#include "Div.h"

Div::Div(Expression *left, Expression *right) : BinaryExpression(left, right) {}

Div::~Div() {
//    delete this->left;
//    delete this->right;
}

double Div::calculate() {
    if (this->right->calculate() == 0) {
        throw "bad input";
    }
    return this->left->calculate() / this->right->calculate();
};