
#ifndef FLIGHTSIM_PROJECT_STRINGREVERSER_H
#define FLIGHTSIM_PROJECT_STRINGREVERSER_H
#include "Solver.h"
#include <string>

using namespace std;

class StringReverser:public Solver<string,string>{
public:
    //get a string and return the reversed string
    string solve(string problem) override;

};
#endif //FLIGHTSIM_PROJECT_STRINGREVERSER_H
