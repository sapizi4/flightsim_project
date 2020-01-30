//
// Created by Sapir on 24/01/2020.
//

#ifndef FLIGHTSIM_PROJECT_STATE_H
#define FLIGHTSIM_PROJECT_STATE_H
template<class T>
class State{
    T state;
    double cost{};
    State<T>* cameFrom;
    double PathCost{};
    double HeuristicCost{};
public:
    //constructor with state
    explicit State(T state) {
        this->state = state;
    }
    State(){
        this->cost = 0;
        this->HeuristicCost = 0;
        this->PathCost = 0;
    }
    void setCost(double costToSet) {
        this->cost = costToSet;
    }
    bool equals(State<T>* other_state) {
        return other_state->getState() == state;
    }
    void setFather(State<T>* father) {
        this->cameFrom = father;
    }
    double getCost() {
        return this->cost;
    }
    T getState(){
        return this->state;
    }
    void setState(T stateToSet){
        this->state = stateToSet;
    }
    State<T>*getFather(){
        return this->cameFrom;
    }
    double getPathCost() const {
        return PathCost;
    }
    void setPathCost(double pathCost) {
        this->PathCost = pathCost;
    }
    int getRow(){
        return this->state[0];
    }
    int getCol(){
        return this->state[1];
    }
    double getHeuristicCost(){
        return this->HeuristicCost;
    }
    void setHeuristicCost(double heuristicCost){
        this->HeuristicCost = heuristicCost;
    }
    //destractor
    ~State()= default;

};
#endif //FLIGHTSIM_PROJECT_STATE_H
