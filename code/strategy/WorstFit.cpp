/* 
 * File:   WorstFit.cpp
 * Author: etudiant
 * 
 * Created on 28 avril 2014, 15:03
 */

#include "WorstFit.h"

#include "../utils.h"

WorstFit::WorstFit(int dimension, int initialCost) :
    Strategy(dimension, initialCost)
{}

WorstFit::WorstFit(const WorstFit& orig) :
    Strategy(orig)
{}

WorstFit::~WorstFit() {
}

bool WorstFit::applyStrategy(int* nuPath, int nuCost, int counter,
        std::pair<int, int> pair) {
    // Note: mostly copy-pasted from BestFit
    if (nuCost < initialCost) {
        if (fitCost == INT_MAX) {
            fitCost = initialCost;
        }
        if (nuCost > fitCost || fitCost == initialCost) {
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

std::string WorstFit::getType() const {
    return std::string("Worst Fit");
}
