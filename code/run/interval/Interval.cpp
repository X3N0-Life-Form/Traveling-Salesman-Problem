/* 
 * File:   Interval.cpp
 * Author: etudiant
 * 
 * Created on 2 juin 2014, 08:55
 */

#include "Interval.h"

Interval::Interval(int min, int max) :
        minDistance(min),
        maxDistance(max)
{}

Interval::Interval(const Interval& orig)
{}

Interval::~Interval() {
}

int Interval::getMinDistance() {
    return minDistance;
}

int Interval::getMaxDistance() {
    return maxDistance;
}

std::vector<Action*>& Interval::getActions() {
    return actions;
}

void Interval::addAction(Action* action) {
    actions.push_back(action);
}
