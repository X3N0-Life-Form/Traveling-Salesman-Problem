/* 
 * File:   StrategicMemory.h
 * Author: etudiant
 *
 * Created on 18 juin 2014, 11:50
 */

#ifndef STRATEGICMEMORY_H
#define	STRATEGICMEMORY_H

#include <list>

#include "Action.h"

/**
 * Records things that happen in Strategy.
 */
class StrategicMemory {
private:
    std::list<Action*> actionsConsidered;
public:
    // Constructors / Destructor
    StrategicMemory();
    StrategicMemory(const StrategicMemory& orig);
    virtual ~StrategicMemory();
    // Getters / Setters / Adders
    void addAction(Action* action);
    // Advanced Getters
    /**
     * Calculates & returns the ratio between improving actions & degrading
     * actions.
     * @return #improving Neighbors / total # of Neighbors
     */
    int getNumberOfGoodActions();
    int getNumberOfBadActions();
    double getGoodToBadRatio();
    // Other Methods
    void flushMemory();
};

#endif	/* STRATEGICMEMORY_H */

