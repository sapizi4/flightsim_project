//
// Created by Sapir on 19/01/2020.
//

#ifndef FLIGHTSIM_PROJECT_FILECACHEMANAGER_H
#define FLIGHTSIM_PROJECT_FILECACHEMANAGER_H
#include "CacheManager.h"

using namespace std;
template<class Problem,class Solution>
class FileCacheManager:public CacheManager<Problem,Solution>{

public:
    FileCacheManager(){}
    //we need to know in o(n), if we get a string ,is the solution saved
    bool solution_exist(string p){}
};
#endif //FLIGHTSIM_PROJECT_FILECACHEMANAGER_H
