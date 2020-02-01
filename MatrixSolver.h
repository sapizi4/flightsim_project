//
// Created by maor on 29/01/2020.
//

#ifndef FLIGHTSIM_MATRIXSOLVER_H
#define FLIGHTSIM_MATRIXSOLVER_H
#include "Solver.h"
#include "Searcher.h"
#include "MatrixSearchable.h"
//solve the matrix,  give solution
template <class Problem,class Solution,class T>
class MatrixSolver:public Solver<Problem,Solution>{
    Searcher<T>* searcher;

public:

    explicit MatrixSolver(Searcher<T>* searcher){
        this->searcher = searcher;
    }
    string solve(string problem){
        auto* matrix = new MatrixSearchable<T>();
        matrix->createMatrix(problem);
        string result = this->searcher->search(matrix);
        return result;
    }

};

#endif //FLIGHTSIM_MATRIXSOLVER_H
