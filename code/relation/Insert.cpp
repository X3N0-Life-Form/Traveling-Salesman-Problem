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

Insert::Insert(Problem& problem, Strategy& strategy) :
    Relation(problem, strategy)
{}

Insert::Insert(const Insert& orig) :
    Relation(orig)
{}

Insert::~Insert() {
}

Neighborhood* Insert::applyRelation(const Neighborhood& n) {
    // Note: this section is identical to Swap's
    int dimension = problem.getDimension();
    if (strategy.getInitialCost() == INT_MAX) {
        strategy.setInitialCost(n.getCost());
    }
    //pair & shuffle
    std::vector<std::pair<int, int> > pairs = problem.getCityPairs();
    strategy.setStopCount(pairs.size());
    std::random_shuffle(pairs.begin(), pairs.end()); //takes a while ...
    for (int i = 0; i < pairs.size(); i++) {
        std::pair<int, int> randomPair = pairs[i];
        // make your move
        // Note: Insert-specific code begins here
        int origin = randomPair.first;
        int target = randomPair.second;
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
        // swap our pair with the end
        pairs.at(i) = pairs.at(pairs.size() - i - 1);
        pairs.at(pairs.size() - i - 1) = randomPair;
    }
    
    // nothing better was found
    Neighborhood* oldN = new Neighborhood(n);
    return oldN;
}

std::string Insert::getType() {
    return std::string("Insert");
}
