

#include "Number.h"
using namespace std;


double Number::calculate() {
    return this->value;
}

Number::Number(double val) {
    this->value = val;
}
Number::Number(char c1,double val) {
    if (c1 == '-') {
        this->value = -1 * value;
    }
}
