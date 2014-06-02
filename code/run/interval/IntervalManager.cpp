/* 
 * File:   IntervalManager.cpp
 * Author: etudiant
 * 
 * Created on 2 juin 2014, 09:35
 */

#include "IntervalManager.h"

#include "../../utils.h"

IntervalManager::IntervalManager(Strategy* strategy, Relation* relation) :
        strategy(strategy),
        relation(relation)
{}

IntervalManager::IntervalManager(const IntervalManager& orig) :
        strategy(orig.strategy),
        relation(orig.relation),
        intervals(orig.intervals)
{}

IntervalManager::~IntervalManager() {
}

const std::list<Interval*>& IntervalManager::getIntervals() const {
    return intervals;
}

const Relation* IntervalManager::getRelation() const {
    return relation;
}

void IntervalManager::setRelation(Relation* relation) {
    this->relation = relation;
}

const Strategy* IntervalManager::getStrategy() const {
    return strategy;
}

void IntervalManager::setStrategy(Strategy* strategy) {
    this->strategy = strategy;
}

void IntervalManager::prepareIntervals(int dimension) {
    int min = 1;
    int max = 4;
    while (min < dimension) {
        PRINTLN("IntervalManager: new interval: " << min << "; " << max);
        Interval* interval = new Interval(min, max);
        intervals.push_back(interval);
        min = max;
        max *= 4;
    }
}

void IntervalManager::memorizeAction(std::pair<int, int>& pair, int costDiff) {
    int distance = pair.second - pair.first;
    PRINTLN("distance="<<distance);
    for (Interval* interval : intervals) {
        if (distance < interval->getMaxDistance()
                && distance >= interval->getMinDistance()) {
            Action* action = new Action(pair, costDiff);
            interval->addAction(action);
        }
    }
}

std::ostream& operator<<(std::ostream& out, const IntervalManager& manager) {
    out << "IntervalManager: " << manager.getRelation()->getType()
            << " - " << manager.getStrategy()->getType();
    for (Interval* interval : manager.getIntervals()) {
        out << "\n\t" << interval;
    }
    return out;
}

std::ostream& operator<<(std::ostream& out, const IntervalManager* manager) {
    out << *manager;
    return out;
}