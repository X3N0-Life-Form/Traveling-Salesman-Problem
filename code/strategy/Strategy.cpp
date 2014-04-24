/* 
 * File:   Strategy.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 11:04
 */

#include "Strategy.h"

Strategy::Strategy(int initialCost, int dimension) :
    initialCost(initialCost), dimension(dimension) {
}

Strategy::Strategy(const Strategy& orig) :
    history(orig.history), dimension(orig.dimension) {
}

Strategy::~Strategy() {
}

int Strategy::getInitialCost() {
    return initialCost;
}

void Strategy::setInitialCost(int initialCost) {
    this->initialCost = initialCost;
}
