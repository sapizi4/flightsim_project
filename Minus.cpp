
#include "Minus.h"
using namespace std;

double Minus::calculate() {
    double result = (left->calculate()-right->calculate());
    return result;

}
Minus:: Minus(Number val1,Number val2){
    this->left = new Number(val1);
    this->right = new Number(val2);

}
Minus:: Minus(Expression* val1,Number val2){
    this->left = val1;
    this->right = new Number(val2);

}
Minus:: Minus(Number val1, Expression* val2){
    this->left = new Number(val1);
    this->right = val2;

}
Minus:: Minus(Expression* val1,Expression* val2) {
    this->left = val1;
    this->right = val2;

}