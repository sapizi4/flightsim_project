//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_NUMBER_H
#define FLIGHTSIM_NUMBER_H
#include "Expression.h"
using namespace std;

class Number : public Expression {
private:
    double value;
public:
    explicit Number(double val);
    Number(char c1,double val);
    double calculate() override;
    ~Number();
};
#endif //FLIGHTSIM_NUMBER_H
