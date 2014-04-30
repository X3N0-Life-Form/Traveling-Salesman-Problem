/* 
 * File:   WorstFit.cpp
 * Author: etudiant
 * 
 * Created on 28 avril 2014, 15:03
 */

#include "WorstFit.h"

#include "../utils.h"

WorstFit::WorstFit(int dimension, int initialCost) :
    Strategy(dimension, initialCost) {
}

WorstFit::WorstFit(const WorstFit& orig) : Strategy(orig) {
}

WorstFit::~WorstFit() {
}

bool WorstFit::applyStrategy(int* nuPath, int nuCost, int counter) {
    // Note: mostly copy-pasted from BestFit
    if (nuCost < initialCost) {
        if (nuCost > fitCost || fitCost == initialCost) {
            //PRINTLN(nuCost<<" < "<<fitCost);
            fitCost = nuCost;
            fit = new int[dimension];
            ARRAY_COPY(fit, nuPath, dimension);
        }
    }
    // are we there yet?
    if (counter >= dimension - 1) {
        return true;
    } else {
        return false;
    }
}

void WorstFit::reset() {
    fit = NULL;
    fitCost = initialCost;
}

std::string WorstFit::getType() {
    return std::string("Worst Fit");
}
