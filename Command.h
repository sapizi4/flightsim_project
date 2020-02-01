//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_COMMAND_H
#define FLIGHTSIM_COMMAND_H
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <thread>
using namespace std;

using namespace std;
class Command {
public:
    virtual void execute(const vector<string>&lexer)=0;
    ~Command()= default;
};
#endif //FLIGHTSIM_COMMAND_H
