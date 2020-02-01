//
// Created by maor on 24/01/2020.
//

#ifndef FLIGHTSIM_SEARCHABLE_H
#define FLIGHTSIM_SEARCHABLE_H
//define the functionality of a search problem

#include "State.h"
#include <vector>
#include <cstring>
#include <list>
#include <iostream>
using namespace std;
template <class T>
class Searchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual State<T>* getGoalState() = 0;
    virtual list<State<T>*> getAllPossibleStates(State<T>* s) = 0;
    virtual ~Searchable() = default;;
};
#endif //FLIGHTSIM_SEARCHABLE_H
