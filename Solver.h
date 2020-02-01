//
// Created by maor on 24/01/2020.
//

#ifndef FLIGHTSIM_SOLVER_H
#define FLIGHTSIM_SOLVER_H
//solver interface , take a problem and solve it
template <class Problem,class Solution>
class Solver{
public:

    virtual Solution solve(Problem problem)=0;
    ~Solver()= default;;
};

#endif //FLIGHTSIM_SOLVER_H
