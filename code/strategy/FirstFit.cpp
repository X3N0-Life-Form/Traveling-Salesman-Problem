/* 
 * File:   FirstFit.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 14:56
 */

#include "FirstFit.h"

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
        fit = nuPath;
        fitCost = nuCost;
        return true;
    } else {
        return false;
    }
}

void FirstFit::reset() {
    fit = NULL;
}

std::string FirstFit::getType() const {
    return std::string("First Fit");
}
