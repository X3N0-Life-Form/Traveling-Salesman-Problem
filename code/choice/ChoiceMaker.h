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
    virtual void setHook(Hookable* hook);
    // Other Methods
    virtual bool processPair(std::pair<int, int>& pair);
    virtual void updateHook(bool accepted);
};

#endif	/* CHOICEMAKER_H */

