/* 
 * File:   BestFit.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 16:03
 */

#include "BestFit.h"

#include "../utils.h"

BestFit::BestFit(int initialCost, int dimension) :
    Strategy(initialCost, dimension) {
}

BestFit::BestFit(const BestFit& orig) : Strategy(orig) {
}

BestFit::~BestFit() {
}

bool BestFit::applyStrategy(int* nuPath, int nuCost, int counter) {
    std::cout << "\napplyStrategy #"<<counter<<": "<<nuCost<<"("<<fitCost<<")";
    if (nuCost < initialCost) {
        if (nuCost < fitCost) {
            fitCost = nuCost;
            fit = nuPath;
        }
        if (counter >= dimension) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void BestFit::reset() {
    fit = NULL;
    fitCost = initialCost;
}

