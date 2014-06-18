/* 
 * File:   FirstFit.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 14:56
 */

#include "FirstFit.h"

#include "../utils.h"

///////////////////////////////
// Constructors / Destructor //
///////////////////////////////

FirstFit::FirstFit(int dimension, int initialCost) :
    Strategy(dimension, initialCost)
{}

FirstFit::FirstFit(const FirstFit& orig) :
    Strategy(orig)
{}

FirstFit::~FirstFit() {
}

/////////////////////////
// Implemented Methods //
/////////////////////////

bool FirstFit::applyStrategy(int* nuPath, int nuCost, int counter,
        std::pair<int, int> pair) {
    if (nuCost < initialCost) {
        ARRAY_COPY(fit, nuPath, dimension);
        fitCost = nuCost;
        this->pair = pair;
        if (strategicMemory != NULL) {
            recordAction(pair, nuCost);
        }
        return true;
    } else {
        if (strategicMemory != NULL) {
            recordAction(pair, nuCost);
        }
        return false;
    }
}

std::string FirstFit::getType() const {
    return std::string("First Fit");
}
