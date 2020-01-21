

#ifndef FLIGHTSIM_PROJECT_EXPRESSION_H
#define FLIGHTSIM_PROJECT_EXPRESSION_H

#include <map>
#include <list>
#include <string>

using namespace std;

//an interface.
class Expression {
public:
    /**
    * A convenience method. Like the `evaluate(assignment)` method above, but uses an empty assignment.
    * @return  the result of the variable.
    */
    virtual double calculate() =0;

};
#endif //FLIGHTSIM_PROJECT_EXPRESSION_H
