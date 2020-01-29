//
// Created by Sapir on 29/01/2020.
//

#ifndef FLIGHTSIM_PROJECT_COMPARATOR_H
#define FLIGHTSIM_PROJECT_COMPARATOR_H

#include "State.h"
//compares 2 possible states

template<class T>
class Comparator{
public:

    Comparator(){};
    //object adapter
    bool operator ()( State<T>state1, State<T>state2){
        return state1.getCost()< state2.getCost();
    }
};
#endif //FLIGHTSIM_PROJECT_COMPARATOR_H
