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
#include "StrategicMemory.h"

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
    StrategicMemory* strategicMemory;
    Action* lastAction; //Hero
public:
    static int INTERVAL_STEP;
public:
    // Constructors / Destructor
    IntervalManager(Strategy* strategy, Relation* relation);
    IntervalManager(const IntervalManager& orig);
    /**
     * Note: Does not delete any pointer.
     */
    virtual ~IntervalManager();
    // Getters / Setters / Adders
    const std::list<Interval*>& getIntervals() const;
    const Strategy* getStrategy() const;
    void setStrategy(Strategy* strategy);
    const Relation* getRelation() const;
    void setRelation(Relation* relation);
    int getDimension() const;
    int getInitialCost();
    void setStrategicMemory(StrategicMemory* strategicMemory);
    // Advanced Getters
    Interval* getInterval(int value);
    Interval* getInterval(const std::pair<int, int>& pair);
    int getActionCount();
    // Other Methods
    void prepareIntervals(int dimension, IntervalType type = DISJOINT);
    void memorizeAction(std::pair<int, int>& pair, int costDiff);
    std::ostream& outputDataCSV(std::ostream& out = std::cout);
};

// Operators
std::ostream& operator<<(std::ostream& out, const IntervalManager& manager);
std::ostream& operator<<(std::ostream& out, const IntervalManager* manager);

#endif	/* INTERVALMANAGER_H */

