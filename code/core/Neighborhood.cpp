/* 
 * File:   Neighborhood.cpp
 * Author: etudiant
 * 
 * Created on 23 avril 2014, 15:22
 */

#include "Neighborhood.h"

#include <iostream>
#include <random>
#include "../utils.h"

///////////////////////////////
// Constructors / Destructor //
///////////////////////////////

Neighborhood::Neighborhood(Problem& problem) :
        problem(problem),
        cost(0),
        dimension(problem.getDimension())
{
    path = new int[dimension];
}

Neighborhood::Neighborhood(const Neighborhood& orig) : 
        problem(orig.problem),
        cost(orig.cost),
        dimension(orig.dimension),
        path(NULL)
{
    path = new int[dimension];
    ARRAY_COPY(path, orig.path, dimension);
}

Neighborhood::~Neighborhood() {
    delete[](path);
}

Neighborhood& Neighborhood::operator =(const Neighborhood& right) {
    this->problem = right.problem;
    this->cost = right.cost;
    this->path = right.path;
}

///////////////////////
// Getters / Setters //
///////////////////////

int* Neighborhood::getPath() const {
    return path;
}

void Neighborhood::setPath(int* path) {
    ARRAY_COPY(this->path, path, dimension);
    //this->path = path;
}

int Neighborhood::getCost() const {
    return cost;
}

void Neighborhood::setCost(int cost) {
    this->cost = cost;
}

/**
 * <=> problem.getDimension()
 * @return This Neighborhood Problem's dimension.
 */
int Neighborhood::getDimension() const {
    return dimension;
}

Problem& Neighborhood::getProblem() const {
    return problem;
}

void Neighborhood::setProblem(Problem& problem) {
    this->problem = problem;
}

void Neighborhood::generateRandomNeighborhood() {
    std::vector<int> v_city = problem.getCityIdsAsVector();
    for (int i = 0; i < dimension; i++) {
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
    for (int i = 0; i < dimension - 1; i++) {
        cost += problem.getDistance(path[i], path[i+1]);
    }
    cost += problem.getDistance(path[0], path[dimension - 1]);
    return cost;
}

/**
 * Lightweight cost calculation method (only recalculates what is necessary).
 * <br />Note: doesn't modify this class' cost.
 * @param index1 index of a city in the current path
 * @param index2 index of a city in the current path
 * @return cost of this Neighborhood if we swapped these two cities.
 */
int Neighborhood::calculatePotentialCostSwap(int index1, int index2) const {
    int nuCost = cost;
    // previous & next ids
    int prev1 = index1 - 1;
    int next1 = index1 + 1;
    int prev2 = index2 - 1;
    int next2 = index2 + 1;
    // WARNING: special cases: first & last cities in our path
    if (prev1 < 0)
        prev1 = dimension - 1;
    else if (next1 >= dimension)
        next1 = 0;
    if (prev2 < 0)
        prev2 = dimension - 1;
    else if (next2 >= dimension)
        next2 = 0;
    // remove old distance costs
    // be careful when dealing with two cities right after the other in the path
    if (path[prev1] != path[index2])
        nuCost -= problem.getDistance(path[prev1],  path[index1]);
    if (path[next1] != path[index2])
        nuCost -= problem.getDistance(path[index1], path[next1]);
    if (path[prev2] != path[index1])
        nuCost -= problem.getDistance(path[prev2],  path[index2]);
    if (path[next2] != path[index1])
        nuCost -= problem.getDistance(path[index2], path[next2]);
    // add the new costs
    // no need extra checks here, distance between cities #i & #i = 0
    nuCost += problem.getDistance(path[prev1],  path[index2]);
    nuCost += problem.getDistance(path[index2], path[next1]);
    nuCost += problem.getDistance(path[prev2],  path[index1]);
    nuCost += problem.getDistance(path[index1], path[next2]);
    
    return nuCost;
}

int Neighborhood::calculatePotentialCostInsert(int origin, int target) const {
    // Note: this section is identical to Swap's
    int nuCost = cost;
    // previous & next ids
    int prev_origin = origin - 1;
    int next_origin = origin + 1;
    int prev_target = target - 1;
    int next_target = target + 1;
    // WARNING: special cases: first & last cities in our path
    if (prev_origin < 0)
        prev_origin = dimension - 1;
    else if (next_origin >= dimension)
        next_origin = 0;
    if (prev_target < 0)
        prev_target = dimension - 1;
    else if (next_target >= dimension)
        next_target = 0;
    // remove old distance costs
    // be careful when dealing with two cities right after the other in the path
    // Note: Insert specific code begins here
    if (path[target] == path[next_origin] || path[target] == path[origin])
        return cost;
    nuCost -= problem.getDistance(path[prev_origin],  path[origin]);
    nuCost -= problem.getDistance(path[origin], path[next_origin]);
    nuCost -= problem.getDistance(path[prev_target],  path[target]);
    // add the new costs
    nuCost += problem.getDistance(path[prev_origin], path[next_origin]);
    nuCost += problem.getDistance(path[prev_target], path[origin]);
    nuCost += problem.getDistance(path[origin], path[target]);
    
    return nuCost;
}

int Neighborhood::calculatePotentialCostReverse(int left, int right) const {
    // Note: this section is identical to Swap & Insert's
    int nuCost = cost;
    // previous & next ids
    int prev_left = left - 1;
    int next_left = left + 1;
    int prev_right = right - 1;
    int next_right = right + 1;
    // WARNING: special cases: first & last cities in our path
    if (prev_left < 0)
        prev_left = dimension - 1;
    else if (next_left >= dimension)
        next_left = 0;
    if (prev_right < 0)
        prev_right = dimension - 1;
    else if (next_right >= dimension)
        next_right = 0;
    // remove old distance costs
    // be careful when dealing with two cities right after the other in the path
    // Note: Reverse specific code begins here
    if (left == right
            || (prev_left == right && next_right == left)) {
        return nuCost;
    } else {
        nuCost -= problem.getDistance(path[prev_left], path[left]);
        nuCost -= problem.getDistance(path[right], path[next_right]);

        nuCost += problem.getDistance(path[prev_left], path[right]);
        nuCost += problem.getDistance(path[left], path[next_right]);
    }
    
    return nuCost;
}

///////////////
// Operators //
///////////////

std::ostream& operator<<(std::ostream& out, Neighborhood& n) {
    out << "Neighborhood: cost=" << n.getCost() << "; path=[";
    for (int i = 0; i < n.getDimension() - 1; i++) {
        out << n.getPath()[i] << ", ";
    }
    out << n.getPath()[n.getDimension() - 1] << "]";
    return out;
}

bool operator==(const Neighborhood& left, const Neighborhood& right) {
    if (left.getProblem() != right.getProblem())
        return false;
    else if (left.getDimension() != right.getDimension())
        return false;
    else if (left.getCost() != right.getCost())
        return false;
    else if (left.getPath() == right.getPath())
        return true;
    // compare path contents
    for (int i = 0; i < left.getDimension(); i++) {
        if (left.getPath()[i] != right.getPath()[i])
            return false;
    }
    return true;
}

bool operator!=(const Neighborhood& left, const Neighborhood& right) {
    return !(left == right);
}

