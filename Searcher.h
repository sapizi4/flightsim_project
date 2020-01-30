

#ifndef FLIGHTSIM_PROJECT_SEARCHER_H
#define FLIGHTSIM_PROJECT_SEARCHER_H
//for the searching algorithm
#include "State.h"
#include "Searchable.h"
#include <list>
#include <set>
using namespace std;


template <class T>
class Searcher{
protected:
    double cost{};
    int numberOfNodesEvaluated{};
public:
    virtual string search(Searchable<T>* searchable)=0;
    //virtual int getNumberOfNodesEvaluated()=0;
    //virtual double getTotalCost()=0;
    ~Searcher()= default;;
};
#endif //FLIGHTSIM_PROJECT_SEARCHER_H
