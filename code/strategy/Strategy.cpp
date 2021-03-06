/* 
 * File:   Strategy.cpp
 * Author: etudiant
 * 
 * Created on 24 avril 2014, 11:04
 */

#include "Strategy.h"

#include "../utils.h"

///////////////////////////////
// Constructors / Destructor //
///////////////////////////////

Strategy::Strategy() :
        dimension(0),
        initialCost(INT_MAX),
        strategicMemory(NULL)
{
    fit = new int[dimension];
}

Strategy::Strategy(int dimension, int initialCost) :
        initialCost(initialCost),
        dimension(dimension),
        fitCost(initialCost),
        strategicMemory(NULL)
{
    fit = new int[dimension];
}

Strategy::Strategy(const Strategy& orig) :
        initialCost(orig.initialCost),
        dimension(orig.dimension),
        fitCost(orig.fitCost),
        strategicMemory(orig.strategicMemory)
{
    fit = new int[dimension];
    ARRAY_COPY(fit, orig.fit, dimension);
}

Strategy::~Strategy() {
    delete[](fit);
}

///////////////////////
// Getters / Setters //
///////////////////////

int Strategy::getDimension() const {
    return dimension;
}

int Strategy::getInitialCost() const {
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

int Strategy::getStopCount() {
    return stopCount;
}

void Strategy::setStopCount(int count) {
    stopCount = count;
}

std::pair<int, int>& Strategy::getPair() {
    return pair;
}

StrategicMemory* Strategy::getStrategicMemory() {
    return strategicMemory;
}

void Strategy::setStrategicMemory(StrategicMemory* strategicMemory) {
    this->strategicMemory = strategicMemory;
}

////////////////////
// Common Methods //
////////////////////

bool Strategy::hasBetter() {
    return fitCost < initialCost;
}

void Strategy::recordAction(std::pair<int, int>& pair, int costDiff) {
    Action* action = new Action(pair, costDiff);
    strategicMemory->addAction(action);
}

void Strategy::flushMemory() {
    strategicMemory->flushMemory();
}

///////////////
// Operators //
///////////////

bool operator !=(const Strategy& left, const Strategy& right) {
    return !(left == right);
}

bool operator ==(const Strategy& left, const Strategy& right) {
    if (left.getType() != right.getType())
        return false;
    else if (left.getDimension() != right.getDimension())
        return false;
    else if (left.getInitialCost() != right.getInitialCost())
        return false;
    // not so sure about comparing paths & fit costs
    return true;
}