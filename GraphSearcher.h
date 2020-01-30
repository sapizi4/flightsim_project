//
// Created by Sapir on 24/01/2020.
//

#ifndef FLIGHTSIM_PROJECT_GRAPHSEARCHER_H
#define FLIGHTSIM_PROJECT_GRAPHSEARCHER_H
#include "Searcher.h"
#include "Searchable.h"

//interface for searchers that using graph
template<class T>
class GraphSearcher:public Searcher<T>{

public:

    virtual string search(Searchable<T>* searchable)=0;
    int getNumberOfNodesEvaluted(){
        return this->numberOfNodesEvaluated;
    }
    string backTrace(State<T>* goal, Searchable<T>* toSearch) {
        int rowChild,rowFather,colChild,colFather;
        State<T> *start = toSearch->getInitialState();
        string result;
        list<State<T> *> backTraceList;

        while (!goal->equals(start)) {
            string name = goal->getState();
            string parentName = goal->getFather()->getState();

            char *divide = const_cast<char *>(name.c_str());
            rowChild = stoi(strtok(divide, ","));
            colChild = stoi(strtok(nullptr, ","));

            char *divideParent = const_cast<char *>(parentName.c_str());
            rowFather = stoi(strtok(divideParent, ","));
            colFather = stoi(strtok(nullptr, ","));

            if (rowChild > rowFather) {
                result += "Down";
            } else if (rowChild < rowFather) {
                result += "Up";
            } else if (colChild > colFather) {
                result += "Right";
            } else if (colChild < colFather) {
                result += "Left";
            }

            result += ",";
            goal = goal->getFather();
        }

        return result;
    }
    double getTotalCost(){
        return this->cost;
    }
};
#endif //FLIGHTSIM_PROJECT_GRAPHSEARCHER_H
