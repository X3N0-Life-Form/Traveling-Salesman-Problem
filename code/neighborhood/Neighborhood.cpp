/* 
 * File:   Neighborhood.cpp
 * Author: etudiant
 * 
 * Created on 23 avril 2014, 15:22
 */

#include "Neighborhood.h"

#include <iostream>
#include "../utils.h"

Neighborhood::Neighborhood(Problem& problem) :
    problem(problem), cost(0) {
    path = new int[problem.getDimension()];
}

Neighborhood::Neighborhood(const Neighborhood& orig) : 
    problem(orig.problem), cost(orig.cost), path(NULL) {
    path = new int[problem.getDimension()];
    ARRAY_COPY(path, orig.path, problem.getDimension());
}

Neighborhood::~Neighborhood() {
}

void Neighborhood::generateRandomNeighborhood() {
    std::vector<int> v_city = problem.getCityIds();
    for (int i = 0; i < problem.getDimension(); i++) {
        std::random_device rd;
        int randomIndex = rd() % v_city.size();
        path[i] = v_city[randomIndex];
        auto toErase = v_city.begin() + randomIndex;
        v_city.erase(toErase);
    }
}

/**
 * Calculate this Neighborhood's cost systematically.
 * @return The new cost.
 */
int Neighborhood::calculateCost() {
    cost = 0;
    for (int i = 0; i < problem.getDimension() - 1; i++) {
        cost += problem.getDistance(path[i], path[i+1]);
    }
    cost += problem.getDistance(path[0], path[problem.getDimension() - 1]);
    return cost;
}

/**
 * Lightweight cost calculation method (only recalculates what is necessary).
 * <br />Note: doesn't modify this class' cost.
 * @param index1 index of a city in the current path
 * @param index2 index of a city in the current path
 * @return cost of this Neighborhood if we swapped these two cities.
 */
int Neighborhood::calculatePotentialCost(int index1, int index2) const {
    int nuCost = cost;
    int id1 = path[index1];
    int id2 = path[index2];
    // previous & next ids
    int prev1 = index1 - 1;
    int next1 = index1 + 1;
    int prev2 = index2 - 1;
    int next2 = index2 + 1;
    // WARNING: special cases: first & last cities in our path
    if (prev1 < 0)
        prev1 = problem.getDimension() - 1;
    else if (next1 >= problem.getDimension())
        next1 = 0;
    if (prev2 < 0)
        prev2 = problem.getDimension() - 1;
    else if (next2 >= problem.getDimension())
        next2 = 0;
    // remove old distance costs
    nuCost -= problem.getDistance(path[prev1], id1)
            + problem.getDistance(id1, path[next1])
            + problem.getDistance(path[prev2], id2)
            + problem.getDistance(id2, path[next2]);
    // add the new costs
    nuCost += problem.getDistance(path[prev1], id2)
            + problem.getDistance(id2, path[next1])
            + problem.getDistance(path[prev2], id1)
            + problem.getDistance(id1, path[next2]);
    
    return nuCost;
}

int* Neighborhood::getPath() const {
    return path;
}

void Neighborhood::setPath(int* path) {
    ARRAY_COPY(this->path, path, problem.getDimension());
    //this->path = path;
}

int Neighborhood::getCost() const {
    return cost;
}

void Neighborhood::setCost(int cost) {
    this->cost = cost;
}

/**
 * 
 * @return This Neighborhood Problem's dimension.
 */
int Neighborhood::getDimension() {
    return problem.getDimension();
}

Problem& Neighborhood::getProblem() {
    return problem;
}


std::ostream& operator<<(std::ostream& out, Neighborhood& n) {
    out << "Neighborhood: cost=" << n.getCost() << "; path=[";
    for (int i = 0; i < n.getDimension() - 1; i++) {
        out << n.getPath()[i] << ", ";
    }
    out << n.getPath()[n.getDimension() - 1] << "]";
    return out;
}
