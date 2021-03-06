/* 
 * File:   ChoiceMaker.cpp
 * Author: etudiant
 * 
 * Created on 10 juin 2014, 10:58
 */

#include "ChoiceMaker.h"

#include <random>

#include "../utils.h"

extern std::random_device randomDevice;

const double ChoiceMaker::ALPHA = 0.999;
double ChoiceMaker::LOWEST_STARTING_PROBABILITY = 0.3;

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

void ChoiceMaker::setIntervalToUpdate(Interval* interval) {
    this->intervalToUpdate = interval;
}

/////////////////////////
// Implemented Methods //
/////////////////////////

void ChoiceMaker::setHook(Hookable* hook) {
    this->hook = hook;
}

bool ChoiceMaker::processPair(std::pair<int, int>& pair) {
    // if this is a stupid pair, abort
    if (pair.first == pair.second)
        return false;
    // else, process
    Interval* interval = manager->getInterval(pair);
    intervalToUpdate = interval;
    int count = interval->getActions().size();
    
    if (count == 0) {
        return true;
    } else {
        return maybeChooseThisInterval(interval);
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
    // cost diff variation
    double gamma = 0;
    if (intervalToUpdate->getLatestAction() != NULL) {
        Action* latestAction = intervalToUpdate->getLatestAction();
        gamma = 1 / latestAction->getCostDiff();
    }
    // take dimension into account
    double omicron = (1 + (1 /manager->getDimension()));
    
    nuProbability = nuProbability * ALPHA * omicron
            + (1 - ALPHA - gamma) * delta;
    
    intervalToUpdate->setProbability(nuProbability);
    intervalToUpdate = NULL;
}

///////////////////
// Other Methods //
///////////////////

void ChoiceMaker::adjustProbabilities() {
    int intervalCount = manager->getIntervals().size();
    double step = (1 - LOWEST_STARTING_PROBABILITY) / manager->getDimension();
    double currentStartingProbability = 1.0;
    for (Interval* interval : manager->getIntervals()) {
        interval->setProbability(currentStartingProbability);
        currentStartingProbability -= step
                * (interval->getMaxDistance() - interval->getMinDistance());
    }
}

bool ChoiceMaker::maybeChooseThisInterval(Interval* interval) {
    int count = interval->getActions().size();
    int totalCount = manager->getActionCount();
    // if we're empty
    if (totalCount == 0) {
        count = ++totalCount;
    }
    
    double probability = interval->getProbability()
        - (count/totalCount) * (1 - ALPHA);
    double roll = (randomDevice() % 100);
    if (roll / 100 < probability) {
        //PRINTLN("Accepted!"<<probability<<"; "<<*interval);
        return true;
    } else {
        //PRINTLN("Refused!"<<probability<<"; "<<*interval);
        return false;
    }
}
