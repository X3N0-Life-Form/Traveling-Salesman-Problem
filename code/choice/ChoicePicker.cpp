/* 
 * File:   ChoicePicker.cpp
 * Author: etudiant
 * 
 * Created on 16 juin 2014, 09:49
 */

#include "ChoicePicker.h"

#include "../utils.h"

///////////////////////////////
// Constructors / Destructor //
///////////////////////////////

ChoicePicker::ChoicePicker(IntervalManager* manager) :
        manager(manager)
{
    choiceMaker = new ChoiceMaker(manager);
    choiceMaker->adjustProbabilities();
}

ChoicePicker::ChoicePicker(const ChoicePicker& orig) :
        manager(orig.manager),
        containers(orig.containers),
        hook(orig.hook),
        choiceMaker(orig.choiceMaker)
{}

ChoicePicker::~ChoicePicker() {
    delete(choiceMaker);
}

///////////////////////
// Getters / Setters //
///////////////////////

std::vector<ChoiceContainer*>& ChoicePicker::getContainers() {
    return containers;
}


//////////////////////////////////
// Implemented Methods - Picker //
//////////////////////////////////

std::pair<int, int> ChoicePicker::getPair() {
    //note: need to think about updating intervals
    for (ChoiceContainer* container : containers) {
        Interval* interval = container->getInterval();
        if (choiceMaker->maybeChooseThisInterval(interval)) {
            choiceMaker->setIntervalToUpdate(interval);
            return container->getNextPair();
        }
    }
    // if nothing was chosen, return something that won't be processed
    std::pair<int, int> res(1,1);
    return res;
}

////////////////////////////////////
// Implemented Methods - Hookable //
////////////////////////////////////

bool ChoicePicker::processPair(std::pair<int, int>& pair) {
    throw "This hook can't process pairs.";
}

void ChoicePicker::setHook(Hookable* hook) {
    this->hook = hook;
}

void ChoicePicker::updateHook(bool accepted) {
    hook->updateHook(accepted);
}


///////////////////
// Other Methods //
///////////////////

ChoiceContainer* ChoicePicker::selectContainer(std::pair<int, int>& pair) {
    for (ChoiceContainer* container : containers) {
        Interval* interval = container->getInterval();
        if (interval->includes(pair))
            return container;
    }
    return NULL;
}

void ChoicePicker::prepareContainers(std::vector<std::pair<int, int> >& pairs) {
    for (Interval* interval : manager->getIntervals()) {
        ChoiceContainer* container = new ChoiceContainer(interval);
        containers.push_back(container);
    }
    
    for (std::pair<int, int> pair : pairs) {
        ChoiceContainer* container = selectContainer(pair);
        if (container != NULL) {
            container->addPair(pair);
        } else if (pair.first == pair.second) {
            // Invalid pair, don't process it
        } else {
            PRINTLN("WARNING: ChoicePicker::selectContainer() could "
                    << "not find a container for pair <" << pair.first
                    << ", " << pair.second << ">");
        }
    }
}
