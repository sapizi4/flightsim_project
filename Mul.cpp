
#include "Mul.h"
using namespace std;

double Mul::calculate() {
    double result = left->calculate()*right->calculate();
    return result;

}
Mul:: Mul(Number val1,Number val2){
    this->left = new Number(val1);
    this->right = new Number(val2);

}
Mul:: Mul(Expression* val1,Number val2){
    this->left = val1;
    this->right = new Number(val2);

}
Mul:: Mul(Number val1, Expression* val2){
    this->left = new Number(val1);
    this->right = val2;

}
Mul:: Mul(Expression* val1,Expression* val2){
    this->left = val1;
    this->right = val2;

}