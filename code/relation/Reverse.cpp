/* 
 * File:   Reverse.cpp
 * Author: etudiant
 * 
 * Created on 26 mai 2014, 14:40
 */

#include "Reverse.h"

#include "../utils.h"

///////////////////////////////
// Constructors / Destructor //
///////////////////////////////

Reverse::Reverse(Problem& problem, Strategy* strategy) :
    Relation(problem, strategy)
{}

Reverse::Reverse(const Reverse& orig) :
    Relation(orig)
{}

Reverse::~Reverse() {
}

/////////////////////////
// Implemented Methods //
/////////////////////////

Neighborhood* Reverse::applyRelation(const Neighborhood& n, bool randomPick) {
    // Note: this section is identical to Swap & Insert's
    int dimension = problem.getDimension();
    if (strategy->getInitialCost() == INT_MAX) {
        strategy->setInitialCost(n.getCost());
    }
    //pair & shuffle
    if (isFirstLoop) {
        pairAndShuffle(PM_INSERT);
    }
    if (picker != NULL)
        picker->prepareContainers(pairs);
    
    for (int i = 0; i < pairs->size(); i++) {
        printLoopStatus(i);
        std::pair<int, int> randomPair = getPair(i, randomPick);
        // if we've been given the neutral pair, let's cut our loses & move on
        if (picker->maybeMoveOn()) {
            return useThisPath(n);
        }
        // make your move
        // Note: Reverse-specific code begins here
        int left = randomPair.first;
        int right = randomPair.second;
        
        // Hook: is this pair worth considering
        // Note: only if we don't have a picker
        if (picker == NULL && hook != NULL && !hook->processPair(randomPair)) {
            continue;
        }
        
        int nuCost = n.calculatePotentialCostReverse(left, right);
        // is it a good move
        if (nuCost < n.getCost()) {
            if (hook != NULL)
                hook->updateHook(true);
            
            int* nuPath = new int[dimension];
            reverse(nuPath, n.getPath(), dimension, left, right);
            // Note: end of the Reverse-specific code
            if (strategy->applyStrategy(nuPath, nuCost, i, randomPair)) {
                return useThisPath(n, nuPath);
            }
            // delete nuPath
            delete[](nuPath);
        } else if (hook != NULL) {
            hook->updateHook(false);
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

std::string Reverse::getType() const {
    return "Reverse";
}
