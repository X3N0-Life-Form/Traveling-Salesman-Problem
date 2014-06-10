/* 
 * File:   ChoiceMaker.h
 * Author: etudiant
 *
 * Created on 10 juin 2014, 10:58
 */

#ifndef CHOICEMAKER_H
#define	CHOICEMAKER_H

#include "../run/interval/IntervalManager.h"
#include "../hook/RelationChoiceHook.h"

class ChoiceMaker : public Hookable {
private:
    IntervalManager* manager;
    RelationChoiceHook* hook;
public:
    ChoiceMaker(IntervalManager* manager);
    ChoiceMaker(const ChoiceMaker& orig);
    /**
     * Note: does not delete the IntervalManager or the Hook.
     */
    virtual ~ChoiceMaker();
    // Getters / Setters
    void setManager(IntervalManager* manager);
    virtual void setHook(Hook* hook);
    // other methods
    virtual bool processPair(std::pair<int, int>& pair);
};

#endif	/* CHOICEMAKER_H */

