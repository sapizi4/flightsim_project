
//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_COMPARATOR_H
#define FLIGHTSIM_COMPARATOR_H
#include "State.h"
//compares 2 possible states

template<class T>
class Comparator{
public:

    Comparator()= default;
    //object adapter
    bool operator ()( State<T>state1, State<T>state2){
        return state1.getCost()< state2.getCost();
    }
};
#endif //FLIGHTSIM_COMPARATOR_H
