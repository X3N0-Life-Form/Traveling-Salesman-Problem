/* 
 * File:   Neighborhood.cpp
 * Author: etudiant
 * 
 * Created on 23 avril 2014, 15:22
 */

#include "neighborhood.h"

Neighborhood::Neighborhood(Problem& problem) :
    problem(problem) {
    path = new int[problem.getDimension()];
}

Neighborhood::Neighborhood(const Neighborhood& orig) : 
    problem(orig.problem) {
}

Neighborhood::~Neighborhood() {
}

void Neighborhood::generateRandomNeighborhood() {
    std::vector<int> v_city = problem.getCityIds();
    for (int i = 0; i < problem.getDimension(); i++) {
        std::random_device rd;
        int r = rd() % v_city.size();
        path[i] = v_city[r];
        auto toErase = v_city.begin() + r;
        v_city.erase(toErase);
    }
}

int* Neighborhood::getPath() {
    return path;
}


