/* 
 * File:   BestFit.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 16:03
 */

#include "BestFit.h"

#include "../utils.h"

BestFit::BestFit(int dimension, int initialCost) :
    Strategy(dimension, initialCost)
{}

BestFit::BestFit(const BestFit& orig) :
    Strategy(orig)
{}

BestFit::~BestFit() {
}

bool BestFit::applyStrategy(int* nuPath, int nuCost, int counter,
        std::pair<int, int> pair) {
    if (nuCost < initialCost) {
        if (nuCost < fitCost) {
            //PRINTLN(nuCost<<" < "<<fitCost);
            fitCost = nuCost;
            //fit = new int[dimension];
            ARRAY_COPY(fit, nuPath, dimension);
            this->pair = pair;
        }
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
