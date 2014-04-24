/* 
 * File:   FirstFit.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 14:56
 */

#include "FirstFit.h"

FirstFit::FirstFit(int initialCost, int dimension) :
    Strategy(initialCost, dimension) {
}

FirstFit::FirstFit(const FirstFit& orig) : Strategy(orig) {
}

FirstFit::~FirstFit() {
}

bool FirstFit::applyStrategy(int* nuPath, int nuCost) {
    if (nuCost < initialCost) {
        fit = nuPath;
        return true;
    } else {
        return false;
    }
}

int* FirstFit::getFit() {
    return fit;
}

void FirstFit::reset() {
    fit = NULL;
}
