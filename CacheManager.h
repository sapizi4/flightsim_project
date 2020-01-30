
#ifndef FLIGHTSIM_PROJECT_CACHEMANAGER_H
#define FLIGHTSIM_PROJECT_CACHEMANAGER_H
#define SOL_TABLE "solutions.txt"
#include <map>
#include <string>
#include <fstream>

using namespace std;

//cache manager interface
template <class Problem,class Solution>
class CacheManager{

public:
    //have we solved this problem before
    virtual bool solution_exist(Problem p)=0;
    //get the solution from the disk
    virtual Solution get_solution(Problem p)=0;
    //solve the problem and save it to the disk
    virtual void save_solution(Problem p,Solution S)=0;
    ~CacheManager()= default;;


};
#endif //FLIGHTSIM_PROJECT_CACHEMANAGER_H
