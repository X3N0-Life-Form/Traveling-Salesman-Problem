/* 
 * File:   Insert.cpp
 * Author: etudiant
 * 
 * Created on 14 mai 2014, 11:12
 */

#include "Insert.h"

#include <random>
#include <list>

Insert::Insert(Problem& problem, Strategy& strategy) :
    Relation(problem, strategy)
{}

Insert::Insert(const Insert& orig) : Relation(orig) {
}

Insert::~Insert() {
}

Neighborhood* Insert::applyRelation(const Neighborhood& n) {
    // Note: this section is identical to Swap's
    std::list<int> idList = problem.getCityIdsAsList();
    int dimension = problem.getDimension();
    if (strategy.getInitialCost() == INT_MAX) {
        strategy.setInitialCost(n.getCost());
    }
    
    for (int i = 0; i < dimension; i++) {
        // make your move
        std::random_device rd;
        int randomIndex1 = rd() % idList.size();
        std::list<int> idList2 = problem.getCityIdsAsList();
        
        for (int j = 0; j < dimension; j++) {
            int randomIndex2 = rd() % idList2.size();
            // Note: Insert-specific code begins here
            //int nuCost = n.calculatePotentialCostInsert(randomIndex1, randomIndex2);
        }
    }
}

std::string Insert::getType() {
    return std::string("Insert");
}
