/* 
 * File:   Neighborhood.cpp
 * Author: etudiant
 * 
 * Created on 23 avril 2014, 15:22
 */

#include "Neighborhood.h"

Neighborhood::Neighborhood(Problem& problem) :
    problem(problem), cost(0) {
    path = new int[problem.getDimension()];
}

Neighborhood::Neighborhood(const Neighborhood& orig) : 
    problem(orig.problem), cost(orig.cost), path(orig.path) {
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

void Neighborhood::setPath(int* path) {
    this->path = path;
}

int Neighborhood::getCost() {
    return cost;
}

int Neighborhood::calculateCost() {
    cost = 0;
    for (int i = 0; i < problem.getDimension() - 1; i++) {
        cost += problem.getDistance(path[i], path[i+1]);
    }
    cost += problem.getDistance(path[0], path[problem.getDimension() - 1]);
    return cost;
}

