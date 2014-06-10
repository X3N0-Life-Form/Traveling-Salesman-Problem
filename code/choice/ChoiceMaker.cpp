/* 
 * File:   ChoiceMaker.cpp
 * Author: etudiant
 * 
 * Created on 10 juin 2014, 10:58
 */

#include "ChoiceMaker.h"

ChoiceMaker::ChoiceMaker(IntervalManager* manager) :
        manager(manager)
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

void ChoiceMaker::setHook(Hook* hook) {
    this->hook = dynamic_cast<RelationChoiceHook*>(hook);
}

bool ChoiceMaker::processPair(std::pair<int, int>& pair) {
    return false;
}
