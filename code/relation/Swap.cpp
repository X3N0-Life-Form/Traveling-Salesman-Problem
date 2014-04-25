/* 
 * File:   Swap.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 10:04
 */

#include "Swap.h"

#include <random>
#include "../utils.h"

Swap::Swap(Problem& problem, Strategy& strategy) : Relation(problem, strategy) {
}

Swap::Swap(const Swap& orig) : Relation(orig) {
}

Swap::~Swap() {
}

Neighborhood& Swap::applyRelation(const Neighborhood& n) {
    std::vector<int> idList = problem.getCityIds();
    int dimension = problem.getDimension();
    
    for (int i = 0; i < dimension; i++) {
        // make your move
        std::random_device rd;
        int randomIndex1 = rd() % idList.size();
        int randomIndex2 = rd() % idList.size();
        int nuCost = n.calculatePotentialCost(randomIndex1, randomIndex2);
        // is it a good move
        if (nuCost < n.getCost()) {
            int* nuPath = new int[dimension];
            ARRAY_COPY(nuPath, n.getPath(), dimension);
            SWAP(nuPath, randomIndex1, randomIndex2);
            std::cout << "\nSwap: "<< randomIndex1 << " & "<< randomIndex2;
            
            if (strategy.applyStrategy(nuPath, nuCost)) {
                Neighborhood nuN(n);
                nuN.setPath(strategy.getFit());
                nuN.setCost(strategy.getFitCost());
                return nuN;
            }
        }
        // remove these two ids
        auto toErase = idList.begin() + randomIndex1;
        idList.erase(toErase);
        toErase = idList.begin() + randomIndex2;
        idList.erase(toErase);
    }
 
    
}

