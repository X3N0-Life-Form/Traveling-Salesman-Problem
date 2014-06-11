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
        hook(NULL),
        intervalToUpdate(NULL)
{}

ChoiceMaker::ChoiceMaker(const ChoiceMaker& orig) :
        manager(orig.manager),
        hook(orig.hook),
        intervalToUpdate(orig.intervalToUpdate)
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
    intervalToUpdate = interval;
    int count = interval->getActions().size();
    int totalCount = manager->getActionCount();
    
    if (count == 0) {
        return true;
    } else {
        double probability = interval->getProbability()
            - (count/totalCount) * (1 - ALPHA);
        double roll = (randomDevice() % 100);
        if (roll / 100 < probability) {
            return true;
        } else {
            return false;
        }
    }
    // Note: should never arrive there
    return false;
}

void ChoiceMaker::updateHook(bool accepted) {
    if (intervalToUpdate == NULL)
        return;
    int delta = 1;
    if (!accepted)
        delta = 0;
    double nuProbability = intervalToUpdate->getProbability();
    
    nuProbability = nuProbability * ALPHA + (1 - ALPHA) * delta;
    
    intervalToUpdate->setProbability(nuProbability);
    intervalToUpdate = NULL;
}
