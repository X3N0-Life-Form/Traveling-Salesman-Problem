/* 
 * File:   Swap.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 10:04
 */

#include "Swap.h"

#include <random>

Swap::Swap(Problem& problem, Strategy& strategy) : Relation(problem, strategy) {
}

Swap::Swap(const Swap& orig) : Relation(orig) {
}

Swap::~Swap() {
}

Neighborhood& Swap::applyRelation(Neighborhood& n) {
    std::vector<int> idList = problem.getCityIds();
    
    for (int i = 0; i < problem.getDimension(); i++) {
        std::random_device rd;
        int randomIndex1 = rd() % idList.size();
        int randomIndex2 = rd() % idList.size();
        int nuCost = n.calculatePotentialCost(randomIndex1, randomIndex2);
        if (nuCost < n.getCost()) {
            //apply strategy
        }
        // remove these two ids
        auto toErase = idList.begin() + randomIndex1;
        idList.erase(toErase);
        toErase = idList.begin() + randomIndex2;
        idList.erase(toErase);
    }
 
    
}

