/* 
 * File:   StrategicChoiceHook.h
 * Author: etudiant
 *
 * Created on 10 juin 2014, 12:52
 */

#ifndef STRATEGICCHOICEHOOK_H
#define	STRATEGICCHOICEHOOK_H

#include "Hookable.h"
#include "Hook.h"

class RelationChoiceHook : public Hook {
private:
    Hookable* choiceMaker;
    Hookable* relation;
public:
    RelationChoiceHook();
    RelationChoiceHook(const RelationChoiceHook& orig);
    /**
     * Note: Does not delete either pointers.
     */
    virtual ~RelationChoiceHook();
    // Getters / Setters
    void setChoiceMaker(Hookable* choiceMaker);
    void setRelation(Hookable* relation);
    // other methods
    bool isPairWorthConsidering(std::pair<int, int>& pair);
};

#endif	/* STRATEGICCHOICEHOOK_H */

