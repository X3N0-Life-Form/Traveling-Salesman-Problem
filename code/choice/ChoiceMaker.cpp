/* 
 * File:   ChoiceMaker.cpp
 * Author: etudiant
 * 
 * Created on 10 juin 2014, 10:58
 */

#include "ChoiceMaker.h"

#include <random>

extern std::random_device randomDevice;

const double ChoiceMaker::ALPHA = 0.99;

///////////////////////////////
// Constructors / Destructor //
///////////////////////////////

ChoiceMaker::ChoiceMaker(IntervalManager* manager) :
        manager(manager),
        masterProbability(1)
{}

ChoiceMaker::ChoiceMaker(const ChoiceMaker& orig) :
        manager(orig.manager),
        hook(orig.hook)
{}

ChoiceMaker::~ChoiceMaker() {
}

///////////////////////
// Getters / Setters //
///////////////////////

void ChoiceMaker::setManager(IntervalManager* manager) {
    this->manager = manager;
}

void ChoiceMaker::setHook(Hookable* hook) {
    this->hook = hook;
}

///////////////////
// Other Methods //
///////////////////

bool ChoiceMaker::processPair(std::pair<int, int>& pair) {
    Interval* interval = manager->getInterval(pair);
    int count = interval->getActions().size();
    
    if (count == 0) {
        return true;
    } else {
        double probability = masterProbability - (count/manager->getDimension());
        double roll = randomDevice();
        if (roll > probability) {
            return true;
        } else {
            return false;
        }
    }
    // Note: should never arrive there
    return false;
}

void ChoiceMaker::updateHook(bool accepted) {
    int delta = 1;
    if (!accepted)
        delta = 0;
    masterProbability = masterProbability * ALPHA + (1 - ALPHA) * delta;
}
