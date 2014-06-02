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

int Interval::getMinDistance() const {
    return minDistance;
}

int Interval::getMaxDistance() const {
    return maxDistance;
}

const std::vector<Action*>& Interval::getActions() const {
    return actions;
}

void Interval::addAction(Action* action) {
    actions.push_back(action);
}

std::ostream& operator<<(std::ostream& out, const Interval& interval) {
    out << "Interval: [" << interval.getMinDistance() << ", "
            << interval.getMaxDistance() << "[\n"
            << "Actions:" << interval.getActions().size();
    return out;
}

std::ostream& operator<<(std::ostream& out, const Interval* interval) {
    out << *interval;
    return out;
}