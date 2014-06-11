/* 
 * File:   Interval.cpp
 * Author: etudiant
 * 
 * Created on 2 juin 2014, 08:55
 */

#include "Interval.h"

///////////////////////////////
// Constructors / Destructor //
///////////////////////////////

Interval::Interval(int min, int max) :
        minDistance(min),
        maxDistance(max),
        probability(1)
{}

Interval::Interval(const Interval& orig) :
        minDistance(orig.minDistance),
        maxDistance(orig.maxDistance),
        actions(orig.actions),
        probability(orig.probability)
{}

Interval::~Interval() {
}

////////////////////////////////
// Getters / Setters / Adders //
////////////////////////////////

int Interval::getMinDistance() const {
    return minDistance;
}

void Interval::setMinDistance(int min) {
    minDistance = min;
}

int Interval::getMaxDistance() const {
    return maxDistance;
}

void Interval::setMaxDistance(int max) {
    maxDistance = max;
}

const std::vector<Action*>& Interval::getActions() const {
    return actions;
}

void Interval::addAction(Action* action) {
    actions.push_back(action);
}

double Interval::getProbability() const {
    return probability;
}

void Interval::setProbability(double probability) {
    this->probability = probability;
}

///////////////
// Operators //
///////////////

std::ostream& operator<<(std::ostream& out, const Interval& interval) {
    out << "Interval: [" << interval.getMinDistance() << ", "
            << interval.getMaxDistance() << "[\t"
            << "Actions:" << interval.getActions().size();
    return out;
}

std::ostream& operator<<(std::ostream& out, const Interval* interval) {
    out << *interval;
    return out;
}