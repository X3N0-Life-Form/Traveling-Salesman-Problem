/* 
 * File:   Swap.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 10:04
 */

#include "Swap.h"

#include <algorithm>
#include <list>
#include "../utils.h"

Swap::Swap(Problem& problem, Strategy& strategy) :
    Relation(problem, strategy)
{}

Swap::Swap(const Swap& orig) :
    Relation(orig)
{}

Swap::~Swap() {
}

Neighborhood* Swap::applyRelation(const Neighborhood& n) {
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
        int nuCost = n.calculatePotentialCostSwap(
            randomPair.first, randomPair.second);
        // is it a good move
        if (nuCost < n.getCost()) {
            int* nuPath = new int[dimension];
            ARRAY_COPY(nuPath, n.getPath(), dimension);
            SWAP(nuPath, randomPair.first, randomPair.second);

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

Neighborhood* Swap::applyRelationPartial(const Neighborhood& n) {
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
            int nuCost = n.calculatePotentialCostSwap(randomIndex1, randomIndex2);
            // is it a good move
            if (nuCost < n.getCost()) {
                int* nuPath = new int[dimension];
                ARRAY_COPY(nuPath, n.getPath(), dimension);
                SWAP(nuPath, randomIndex1, randomIndex2);
                
                if (strategy.applyStrategy(nuPath, nuCost, i)) {
                    Neighborhood* nuN = new Neighborhood(n);
                    nuN->setPath(strategy.getFit());
                    nuN->setCost(strategy.getFitCost());
                    delete[](nuPath);
                    return nuN;//!!!!keep this logic ==> partial worst
                }
                // delete nuPath
                delete[](nuPath);
            }
            // remove second id
            idList2.remove(randomIndex2);
        }
        // remove first id
        idList.remove(randomIndex1);
    }
    // nothing better was found
    Neighborhood* oldN = new Neighborhood(n);
    return oldN;
}

std::string Swap::getType() {
    return "Swap";
}
