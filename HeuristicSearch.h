//
// Created by Sapir on 24/01/2020.
//

#ifndef FLIGHTSIM_PROJECT_HEURISTICSEARCH_H
#define FLIGHTSIM_PROJECT_HEURISTICSEARCH_H
#include "Searcher.h"
#include "Searchable.h"
template <class T>
class HeuristicSearch:public Searcher<T>{
public:
    virtual string search(Searchable<T>* searchable)=0;
    string backTrace(State<T>* goal, Searchable<T>* searchable) {
        this->cost = 0;
        int rowChild,rowFather,colChild,colFather;
        State<T> *start = searchable->getInitialState();
        string result = "";
        list<State<T> *> backTraceList;
        while (!goal->equals(start)) {
            string name = goal->getState();
            string parentName = goal->getFather()->getState();

            char *divide = const_cast<char *>(name.c_str());
            rowChild = stoi(strtok(divide, ","));
            colChild = stoi(strtok(NULL, ","));

            char *divideParent = const_cast<char *>(parentName.c_str());
            rowFather = stoi(strtok(divideParent, ","));
            colFather = stoi(strtok(NULL, ","));

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
            this->cost+=goal->getCost();
        }
        return result;
    }
    int getNumberOfNodesEvaluted(){
        return this->numberOfNodesEvaluated;
    }
    double getTotalCost(){
        return this->cost;
    }
    double heuristicFunc(State<T>* state, State<T>* goalState) {
        return abs(state->getRow()-goalState->getRow()+ state->getCol()-goalState->getCol());
    }
};
#endif //FLIGHTSIM_PROJECT_HEURISTICSEARCH_H
