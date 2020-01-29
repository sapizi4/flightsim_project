
#ifndef FLIGHTSIM_PROJECT_SEARCHABLE_H
#define FLIGHTSIM_PROJECT_SEARCHABLE_H

//define the functionality of a search problem

#include "State.h"
#include <vector>
#include <string.h>
#include <list>
#include <iostream>
using namespace std;
template <class T>
class Searchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual State<T>* getGoalState() = 0;
    virtual list<State<T>*> getAllPossibleStates(State<T>* s) = 0;
    virtual ~Searchable() {};
};
#endif //FLIGHTSIM_PROJECT_SEARCHABLE_H
