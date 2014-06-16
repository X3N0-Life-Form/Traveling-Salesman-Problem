/* 
 * File:   ChoicePicker.h
 * Author: etudiant
 *
 * Created on 16 juin 2014, 09:49
 */

#ifndef CHOICEPICKER_H
#define	CHOICEPICKER_H

#include <vector>

#include "../run/interval/IntervalManager.h"
#include "ChoiceContainer.h"
#include "ChoiceMaker.h"
#include "../hook/Picker.h"

class ChoicePicker : public Picker {
private:
    IntervalManager* manager;
    std::vector<ChoiceContainer*> containers;
    Hookable* hook;
    ChoiceMaker* choiceMaker;
public:
    // Constructors / Destructor
    ChoicePicker(IntervalManager* manager);
    ChoicePicker(const ChoicePicker& orig);
    /**
     * Note: doesn't delete manager, but delete its internal ChoiceMaker.
     */
    virtual ~ChoicePicker();
    // Getters / Setters
    std::vector<ChoiceContainer*>& getContainers();
    // Implemented Methods - Picker
    virtual std::pair<int, int> getPair();
    virtual void prepareContainers(std::vector<std::pair<int, int> >* pairs);
    // Implemented Methods - Hookable
    virtual void setHook(Hookable* hook);
    virtual bool processPair(std::pair<int, int>& pair);
    virtual void updateHook(bool accepted);
    // Other Methods
    ChoiceContainer* selectContainer(std::pair<int, int>& pair);
};

#endif	/* CHOICEPICKER_H */

