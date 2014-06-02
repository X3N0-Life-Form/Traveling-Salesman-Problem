/* 
 * File:   Insert.cpp
 * Author: etudiant
 * 
 * Created on 14 mai 2014, 11:12
 */

#include "Insert.h"

#include "../utils.h"
#include <algorithm>
#include <list>

Insert::Insert(Problem& problem, Strategy* strategy) :
    Relation(problem, strategy)
{}

Insert::Insert(const Insert& orig) :
    Relation(orig)
{}

Insert::~Insert() {
}

Neighborhood* Insert::applyRelation(const Neighborhood& n, bool randomPick) {
    // Note: this section is identical to Swap's
    int dimension = problem.getDimension();
    if (strategy->getInitialCost() == INT_MAX) {
        strategy->setInitialCost(n.getCost());
    }
    //pair & shuffle
    if (isFirstLoop) {
        pairAndShuffle(PM_INSERT);
    }
    
    for (int i = 0; i < pairs->size(); i++) {
        printLoopStatus(i);
        std::pair<int, int> randomPair = getPair(i, randomPick);
        // make your move
        // Note: Insert-specific code begins here
        int origin = randomPair.first;
        int target = randomPair.second;
        int nuCost = n.calculatePotentialCostInsert(origin, target);
        // is it a good move
        if (nuCost < n.getCost()) {
            int* nuPath = new int[dimension];
            insert(nuPath, n.getPath(), dimension, origin, target);
            // Note: end of the Insert-specific code
            if (strategy->applyStrategy(nuPath, nuCost, i, randomPair)) {
                return useThisPath(n, nuPath);
            }
            // delete nuPath
            delete[](nuPath);
        }
        // swap our pair with the end
        pairs->at(i) = pairs->at(pairs->size() - i - 1);
        pairs->at(pairs->size() - i - 1) = randomPair;
    }
    
    if (strategy->hasBetter()) {
        return useThisPath(n);
    }
    // nothing better was found
    Neighborhood* oldN = new Neighborhood(n);
    return oldN;
}

std::string Insert::getType() const {
    return std::string("Insert");
}
