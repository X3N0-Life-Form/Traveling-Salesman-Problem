/* 
 * File:   IntervalManager.h
 * Author: etudiant
 *
 * Created on 2 juin 2014, 09:35
 */

#ifndef INTERVALMANAGER_H
#define	INTERVALMANAGER_H

#include <list>

#include "../../relation/Relation.h"
#include "../../strategy/Strategy.h"
#include "Interval.h"

enum IntervalType {
    DISJOINT,
    JOINED_AT_ORIGIN
};

class IntervalManager {
private:
    std::list<Interval*> intervals;
    Strategy* strategy;
    Relation* relation;
    int dimension;
    bool startedCSVOutput;
public:
    static int INTERVAL_STEP;
public:
    IntervalManager(Strategy* strategy, Relation* relation);
    IntervalManager(const IntervalManager& orig);
    virtual ~IntervalManager();
    // Getters/Setters/Adders
    const std::list<Interval*>& getIntervals() const;
    const Strategy* getStrategy() const;
    void setStrategy(Strategy* strategy);
    const Relation* getRelation() const;
    void setRelation(Relation* relation);
    // other methods
    void prepareIntervals(int dimension, IntervalType type = DISJOINT);
    void memorizeAction(std::pair<int, int>& pair, int costDiff);
    Interval* getInterval(int value);
    std::ostream& outputDataCSV(std::ostream& out = std::cout);
};

std::ostream& operator<<(std::ostream& out, const IntervalManager& manager);
std::ostream& operator<<(std::ostream& out, const IntervalManager* manager);

#endif	/* INTERVALMANAGER_H */

