/* 
 * File:   BestFit.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 16:03
 */

#include "BestFit.h"

#include "../utils.h"

//////////////////////////////
// Construtors / Destructor //
//////////////////////////////

BestFit::BestFit(int dimension, int initialCost) :
    Strategy(dimension, initialCost)
{}

BestFit::BestFit(const BestFit& orig) :
    Strategy(orig)
{}

BestFit::~BestFit() {
}

/////////////////////////
// Implemented Methods //
/////////////////////////

bool BestFit::applyStrategy(int* nuPath, int nuCost, int counter,
        std::pair<int, int> pair) {
    int costDiff = fitCost - nuCost;
    if (nuCost < initialCost) {
        if (nuCost < fitCost) {
            //PRINTLN(nuCost<<" < "<<fitCost);
            fitCost = nuCost;
            //fit = new int[dimension];
            ARRAY_COPY(fit, nuPath, dimension);
            this->pair = pair;
        }
    }
    
    if (strategicMemory != NULL) {
        recordAction(pair, costDiff);
    }
    
    // are we there yet?
    if (counter == stopCount) {
        return true;
    } else {
        return false;
    }
}

std::string BestFit::getType() const {
    return std::string("Best Fit");
}
