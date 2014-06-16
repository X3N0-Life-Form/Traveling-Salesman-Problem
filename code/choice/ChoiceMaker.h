/* 
 * File:   ChoiceMaker.h
 * Author: etudiant
 *
 * Created on 10 juin 2014, 10:58
 */

#ifndef CHOICEMAKER_H
#define	CHOICEMAKER_H

#include "../run/interval/IntervalManager.h"
#include "../hook/Hookable.h"

class ChoiceMaker : public Hookable {
public:
    static const double ALPHA; // = 0.99
    static double LOWEST_STARTING_PROBABILITY; // = 0.3
private:
    IntervalManager* manager;
    Hookable* hook;
    Interval* intervalToUpdate;
public:
    // Constructors / Destructor
    ChoiceMaker(IntervalManager* manager);
    ChoiceMaker(const ChoiceMaker& orig);
    /**
     * Note: does not delete the IntervalManager or the Hook.
     */
    virtual ~ChoiceMaker();
    // Getters / Setters
    void setManager(IntervalManager* manager);
    void setIntervalToUpdate(Interval* interval);
    // Implemented Methods
    virtual void setHook(Hookable* hook);
    virtual bool processPair(std::pair<int, int>& pair);
    virtual void updateHook(bool accepted);
    // Other Methods
    /**
     * Sets each interval's starting probability according to the
     * LOWEST_STARTING_PROBABILITY static attribute, from that value to 1.0.
     */
    void adjustProbabilities();
    /**
     * Performs a probability roll to determine whether to choose this Interval.
     * Note: Does NOT set intervalToUpdate if accepted.
     * @param interval
     * @return true if the specified Interval passed the roll.
     */
    bool maybeChooseThisInterval(Interval* interval);
};

#endif	/* CHOICEMAKER_H */

