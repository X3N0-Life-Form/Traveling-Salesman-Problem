/* 
 * File:   Reverse.cpp
 * Author: etudiant
 * 
 * Created on 26 mai 2014, 14:40
 */

#include "Reverse.h"

#include "../utils.h"

Reverse::Reverse(Problem& problem, Strategy& strategy) :
    Relation(problem, strategy)
{}

Reverse::Reverse(const Reverse& orig) :
    Relation(orig)
{}

Reverse::~Reverse() {
}

Neighborhood* Reverse::applyRelation(const Neighborhood& n, bool randomPick) {
    // Note: this section is identical to Swap & Insert's
    int dimension = problem.getDimension();
    if (strategy.getInitialCost() == INT_MAX) {
        strategy.setInitialCost(n.getCost());
    }
    //pair & shuffle
    if (isFirstLoop) {
        pairAndShuffle(PM_INSERT);
    }
    
    for (int i = 0; i < pairs->size(); i++) {
        printLoopStatus(i);
        std::pair<int, int> randomPair = getPair(i, randomPick);
        // make your move
        // Note: Reverse-specific code begins here
        int left = randomPair.first;
        int right = randomPair.second;
        int nuCost = n.calculatePotentialCostReverse(left, right);
        // is it a good move
        if (nuCost < n.getCost()) {
            int* nuPath = new int[dimension];
            reverse(nuPath, n.getPath(), dimension, left, right);
            // Note: end of the Reverse-specific code
            if (strategy.applyStrategy(nuPath, nuCost, i)) {
                return useThisPath(n, nuPath);
            }
            // delete nuPath
            delete[](nuPath);
        }
        // swap our pair with the end
        pairs->at(i) = pairs->at(pairs->size() - i - 1);
        pairs->at(pairs->size() - i - 1) = randomPair;
    }
    
    if (strategy.hasBetter()) {
        return useThisPath(n);
    }
    // nothing better was found
    Neighborhood* oldN = new Neighborhood(n);
    return oldN;
}

std::string Reverse::getType() {
    return "Reverse";
}
