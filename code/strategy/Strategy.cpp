/* 
 * File:   Strategy.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 11:04
 */

#include "Strategy.h"

Strategy::Strategy(int initialCost) : initialCost(initialCost) {
}

Strategy::Strategy(const Strategy& orig) : history(history) {
}

Strategy::~Strategy() {
}

int Strategy::getInitialCost() {
    return initialCost;
}

void Strategy::setInitialCost(int initialCost) {
    this->initialCost = initialCost;
}
