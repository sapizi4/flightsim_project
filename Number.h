
#ifndef FLIGHTSIM_PROJECT_NUMBER_H
#define FLIGHTSIM_PROJECT_NUMBER_H
#include "Expression.h"
using namespace std;

class Number : public Expression {
private:
    double value;
public:
    Number(double val);
    Number(char c1,double val);
    double calculate();
    ~Number();
};
#endif //FLIGHTSIM_PROJECT_NUMBER_H
