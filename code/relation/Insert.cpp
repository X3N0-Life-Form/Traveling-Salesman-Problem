/* 
 * File:   Insert.cpp
 * Author: etudiant
 * 
 * Created on 14 mai 2014, 11:12
 */

#include "Insert.h"

#include "../utils.h"
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
        int origin = rd() % idList.size();
        std::list<int> idList2 = problem.getCityIdsAsList();
        
        for (int j = 0; j < dimension; j++) {
            int target = rd() % idList2.size();
            // Note: Insert-specific code begins here
            int nuCost = n.calculatePotentialCostInsert(origin, target);
            if (nuCost < n.getCost()) {
                int* nuPath = new int[dimension];
                insert(nuPath, n.getPath(), dimension, origin, target);
                // Note: end of the Insert-specific code
                if (strategy.applyStrategy(nuPath, nuCost, i)) {
                    Neighborhood* nuN = new Neighborhood(n);
                    nuN->setPath(strategy.getFit());
                    nuN->setCost(strategy.getFitCost());
                    delete[](nuPath);
                    return nuN;
                }
                // delete nuPath
                delete[](nuPath);
            }
            // remove second id
            idList2.remove(target);
        }
        // remove first id
        idList.remove(origin);
    }
    // nothing better was found
    Neighborhood* oldN = new Neighborhood(n);
    return oldN;
}

std::string Insert::getType() {
    return std::string("Insert");
}
