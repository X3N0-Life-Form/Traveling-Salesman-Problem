/* 
 * File:   Interval.cpp
 * Author: etudiant
 * 
 * Created on 2 juin 2014, 08:55
 */

#include "Interval.h"

#include "../../utils.h"

///////////////////////////////
// Constructors / Destructor //
///////////////////////////////

Interval::Interval(int min, int max) :
        minDistance(min),
        maxDistance(max),
        probability(1),
        latestAction(NULL)
{}

Interval::Interval(const Interval& orig) :
        minDistance(orig.minDistance),
        maxDistance(orig.maxDistance),
        actions(orig.actions),
        probability(orig.probability),
        dimension(orig.dimension),
        latestAction(orig.latestAction)
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
    latestAction = action;
}

double Interval::getProbability() const {
    return probability;
}

void Interval::setProbability(double probability) {
    this->probability = probability;
}

void Interval::setDimension(int dimension) {
    this->dimension = dimension;
}

Action* Interval::getLatestAction() {
    return latestAction;
}

//////////////////////
// Advanced Getters //
//////////////////////

bool Interval::includes(const std::pair<int, int>& pair) {
    int distance = getPairDistance(pair, dimension);
    if (distance >= minDistance && distance < maxDistance)
        return true;
    else
        return false;
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