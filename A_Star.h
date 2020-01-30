//
// Created by Sapir on 19/01/2020.
//

#ifndef FLIGHTSIM_PROJECT_A_STAR_H
#define FLIGHTSIM_PROJECT_A_STAR_H
#include "HeuristicSearch.h"
#include "MyPriorityQueue.h"
#include <unordered_set>
#include <map>

template<class T>
class A_Star:public HeuristicSearch<T>{
    vector<State<T>*> open;

public:
    string search(Searchable<T>* searchable){
        vector<State<T>*> close;
        State<T>* goal = searchable->getGoalState();
        State<T>* start = searchable->getInitialState();
        map<State<T>*,bool> isVisited;
        double f = this->heuristicFunc(start,goal);
        this->open.push_back(start);
        while(!this->open.empty()){
            //get lowest value by heuristic and return its state
            State<T>* current = this->getLowest(goal);
            isVisited[current]=true;
            close.push_back(current);
            //final
            if(current->equals(goal)){
                this->numberOfNodesEvaluated++;
                return this->backTrace(current,searchable);
            }
            this->numberOfNodesEvaluated++;
            //all neighbors
            list<State<T>*> successors = searchable->getAllPossibleStates(current);
            while (!successors.empty()){
                State<T>* temp = successors.back();
                successors.pop_back();

                if(isVisited[temp]){
                    continue;
                }
                //update cost path
                double pathFromCurrent = current->getPathCost()+temp->getCost();
                //check if better
                if(find(this->open.begin(),this->open.end(),temp)!=this->open.end()){
                    if(temp->getPathCost()<pathFromCurrent){
                        continue;
                    }
                }else if(find(close.begin(),close.end(),temp)!=close.end()){
                    if(temp->getPathCost()<pathFromCurrent) {
                        continue;
                    }

                }else{
                    this->open.push_back(temp);
                }
                temp->setPathCost(pathFromCurrent);
                temp->setFather(current);
            }
        }
        return "-1"; //no solution
    }
    /*
     * get lowest state by heuristic function
     */
    State<T>* getLowest(State<T>* goal) {
        vector<State<T>*> temp;
        State<T>* lowest = open.back();
        open.pop_back();
        double huristic = this->heuristicFunc(lowest,goal);
        double first = huristic + lowest->getPathCost();

        while(!this->open.empty()){
            State<T>* state = open.back();
            open.pop_back();


            huristic = this->heuristicFunc(state,goal);
            double newCost = huristic + state->getPathCost();
            if(newCost<first){
                first = newCost;
                temp.push_back(lowest);
                lowest = state;
                //keep on trying get better
                continue;
            }
            temp.push_back(state);
        }

        for(int i = 0 ; i < temp.size();i++){
            this->open.push_back(temp[i]);
        }

        return lowest;
    }

};


#endif //FLIGHTSIM_PROJECT_A_STAR_H
