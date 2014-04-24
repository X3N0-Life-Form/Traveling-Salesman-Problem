/* 
 * File:   BestFit.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 16:03
 */

#include "BestFit.h"

BestFit::BestFit(int initialCost, int dimension) :
    Strategy(initialCost, dimension), counter(0) {
}

BestFit::BestFit(const BestFit& orig) : Strategy(orig) {
}

BestFit::~BestFit() {
}

bool BestFit::applyStrategy(int* nuPath, int nuCost) {
    counter++;
    if (nuCost < initialCost) {
        //history.insert(PAIR(nuPath, nuCost));
        if (counter >= dimension) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int* BestFit::getFit() {
    //return history.find()[0].first;
}

void BestFit::reset() {
    fit = NULL;
    counter = 0;
}

