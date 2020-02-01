//
// Created by Sapir on 19/01/2020.
//
#ifndef FLIGHTSIM_BESTFIRSTSEARCHER_H
#define FLIGHTSIM_BESTFIRSTSEARCHER_H

#include "GraphSearcher.h"
#include <queue>
#include <unordered_set>
#include "MyPriorityQueue.h"


template <class T>
class BestFirstSearch:public GraphSearcher<T>{
    MyPriorityQueue<State<T>*> priorityQueue;
public:
    State<T>* popFromPriorityQueue(){
        this->numberOfNodesEvaluated++;
        State<T>* temp =  this->priorityQueue.top();
        this->priorityQueue.pop();
        return temp;
    }
    void updatePriority(State<T>*current ,State<T>*update){
        double cost;
        vector<State<T>*> temp;
        while (!this->priorityQueue.empty()){
            State<T>* top = this->popFromPriorityQueue();
            temp.push_back(top);
            if(current->equals(top)){
                top->setFather(update);
                cost = update->getPathCost()+current->getCost();
                top->setPathCost(cost);
                break;
            }
        }

        for(int i = 0 ; i<temp.size();i++){
            this->priorityQueue.push(temp[i]);
        }
    }

    string search(Searchable<T>* searchable){
        this->numberOfNodesEvaluated=0;
        //first state
        State<T>* first = searchable->getInitialState();
        this->priorityQueue.push(first);
        first->setPathCost(first->getCost());
        State<T>* current;
        unordered_set<State<T>*> closed;
        typename unordered_set<State<T>*>::iterator onClosed;
        while (!this->priorityQueue.empty()) {
            current  = this->popFromPriorityQueue();
            closed.insert(current);
            if (current == searchable->getGoalState()) {
                this->numberOfNodesEvaluated++;
                return this->backTrace(current,searchable);
            }
            this->numberOfNodesEvaluated++;
            for (State<T>*& s : searchable->getAllPossibleStates(current) ) {
                double currPath = current->getPathCost() + s->getCost();
                onClosed = closed.find(s);
                if (onClosed ==closed.end() && !this->priorityQueue.atPriorityQueue(s)) {
                    s->setFather(current);
                    s->setPathCost(currPath);
                    this->priorityQueue.push(s);
                } else if (currPath < s->getPathCost()) {
                    if (!this->priorityQueue.atPriorityQueue(s)) {
                        this->priorityQueue.push(s);
                    } else {
                        this->updatePriority(s,current);
                    }
                }
            }
        }
        return "-1"; //no solution
    }
};
#endif //FLIGHTSIM_BESTFIRSTSEARCHER_H

#endif //FLIGHTSIM_PROJECT_BESTFIRSTSEARCH_H
