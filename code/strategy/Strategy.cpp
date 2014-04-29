/* 
 * File:   Strategy.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 11:04
 */

#include "Strategy.h"

Strategy::Strategy() : dimension(0), initialCost(INT_MAX){
}

Strategy::Strategy(int dimension, int initialCost) :
    initialCost(initialCost), dimension(dimension), fitCost(initialCost) {
}

Strategy::Strategy(const Strategy& orig) :
    initialCost(orig.initialCost), dimension(orig.dimension),
    fit(orig.fit), fitCost(orig.fitCost) {
}

Strategy::~Strategy() {
}

int Strategy::getInitialCost() {
    return initialCost;
}

void Strategy::setInitialCost(int initialCost) {
    this->initialCost = initialCost;
}

int* Strategy::getFit() {
    return fit;
}

int Strategy::getFitCost() {
    return fitCost;
}
