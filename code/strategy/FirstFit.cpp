/* 
 * File:   FirstFit.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 14:56
 */

#include "FirstFit.h"

#include "../utils.h"

FirstFit::FirstFit(int dimension, int initialCost) :
    Strategy(dimension, initialCost)
{}

FirstFit::FirstFit(const FirstFit& orig) :
    Strategy(orig)
{}

FirstFit::~FirstFit() {
}

bool FirstFit::applyStrategy(int* nuPath, int nuCost, int counter) {
    if (nuCost < initialCost) {
        ARRAY_COPY(fit, nuPath, dimension);
        fitCost = nuCost;
        return true;
    } else {
        return false;
    }
}


std::string FirstFit::getType() const {
    return std::string("First Fit");
}
