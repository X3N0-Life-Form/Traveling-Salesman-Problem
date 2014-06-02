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

class IntervalManager {
private:
    std::list<Interval*> intervals;
    Strategy* strategy;
    Relation* relation;
public:
    IntervalManager(Strategy* strategy, Relation* relation);
    IntervalManager(const IntervalManager& orig);
    virtual ~IntervalManager();
    // Getters/Setters/Adders
    std::list<Interval*>& getIntervals();
    void setStrategy(Strategy* strategy);
    void setRelation(Relation* relation);
    // other methods
    void prepareIntervals(int dimension);
    void memorizeAction(std::pair<int, int> pair, int costDiff);
};

#endif	/* INTERVALMANAGER_H */

