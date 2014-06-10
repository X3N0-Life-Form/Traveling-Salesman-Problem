/* 
 * File:   ChoiceMaker.cpp
 * Author: etudiant
 * 
 * Created on 10 juin 2014, 10:58
 */

#include "ChoiceMaker.h"

const double ChoiceMaker::ALPHA = 0.99;

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

void ChoiceMaker::setManager(IntervalManager* manager) {
    this->manager = manager;
}

void ChoiceMaker::setHook(Hookable* hook) {
    this->hook = hook;
}

bool ChoiceMaker::processPair(std::pair<int, int>& pair) {
    Interval* interval = manager->getInterval(pair);
    int count = interval->getActions().size();
    
    
    
    return false;
}

void ChoiceMaker::updateHook(bool accepted) {
    int delta = 1;
    if (!accepted)
        delta = 0;
    masterProbability = masterProbability * ALPHA + (1 - ALPHA) * delta;
}
