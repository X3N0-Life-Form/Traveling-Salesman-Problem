/* 
 * File:   FirstFit.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 14:56
 */

#include "FirstFit.h"

FirstFit::FirstFit(int initialCost) : Strategy(initialCost) {
}

FirstFit::FirstFit(const FirstFit& orig) : Strategy(orig) {
}

FirstFit::~FirstFit() {
}

bool FirstFit::applyStrategy(int* nuPath, int nuCost) {
    if (nuCost < initialCost)
        return true;
    else
        return false;
}
