/* 
 * File:   IntervalManager.cpp
 * Author: etudiant
 * 
 * Created on 2 juin 2014, 09:35
 */

#include "IntervalManager.h"

#include "../../utils.h"

int IntervalManager::INTERVAL_STEP = 4;

IntervalManager::IntervalManager(Strategy* strategy, Relation* relation) :
        strategy(strategy),
        relation(relation),
        dimension(-1),
        startedCSVOutput(false)
{}

IntervalManager::IntervalManager(const IntervalManager& orig) :
        strategy(orig.strategy),
        relation(orig.relation),
        intervals(orig.intervals),
        dimension(orig.dimension),
        startedCSVOutput(orig.startedCSVOutput)
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

void IntervalManager::prepareIntervals(int dimension, IntervalType type) {
    this->dimension = dimension;
    int min = 1;
    int max = INTERVAL_STEP;
    Interval* prev = NULL;
    while (min < dimension) {
        if (max > dimension) {
            max = dimension + 1;
        }
        
        if (prev != NULL
                && (max - min) < prev->getMaxDistance() - prev->getMinDistance()) {
            prev->setMaxDistance(prev->getMaxDistance() + (max - min));
            PRINTLN("IntervalManager: expanding last Interval: ["
                    << prev->getMinDistance() << "; "
                    << prev->getMaxDistance() << "[");
        } else {
            switch (type) {
                case DISJOINT:
                    // nuthin special
                    break;
                case JOINED_AT_ORIGIN:
                    min = 1;
                    break;
            }
            PRINTLN("IntervalManager: new Interval: [" << min << "; "
                << max << "[");
            Interval* interval = new Interval(min, max);
            intervals.push_back(interval);
            prev = interval;
        }
        
        min = max;
        max *= INTERVAL_STEP;
    }
}

void IntervalManager::memorizeAction(std::pair<int, int>& pair, int costDiff) {
    int distance = pair.second - pair.first;
    // if we go all the way around
    if (distance < 0) {
        distance = dimension - pair.second + pair.first;
    }
    //PRINTLN("distance="<<distance);
    for (Interval* interval : intervals) {
        if (distance < interval->getMaxDistance()
                && distance >= interval->getMinDistance()) {
            Action* action = new Action(pair, costDiff);
            interval->addAction(action);
        }
        // Note: don't break, more than one interval might qualify
    }
}

std::ostream& IntervalManager::outputDataCSV(std::ostream& out) {
    // prefix
    out << relation->getType() << "," << strategy->getType() << ",";
    // either 1st line data or current data
    if (!startedCSVOutput) {
        startedCSVOutput = true;
        for (Interval* interval : intervals) {
            out << "[" << interval->getMinDistance() << ";"
                    << interval->getMaxDistance() << "[,";
        }
    } else {
        for (Interval* interval : intervals) {
            out << interval->getActions().size() << ",";
        }
    }
    out << std::endl;
    
    return out;
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