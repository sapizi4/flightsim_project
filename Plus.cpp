
#include "Plus.h"
using namespace std;

double Plus::calculate() {
    double result = left->calculate()+right->calculate();
    return result;
}
Plus:: Plus(Number val1,Number val2){
    this->left = new Number(val1);
    this->right = new Number(val2);

}
Plus:: Plus(Expression* val1,Number val2){
    this->left = val1;
    this->right = new Number(val2);

}
Plus:: Plus(Number val1, Expression* val2){
    this->left = new Number(val1);
    this->right = val2;

}
Plus:: Plus(Expression* val1,Expression* val2){
    this->right = val2;
    this->left = val1;

}