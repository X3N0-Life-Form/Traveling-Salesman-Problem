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
{}

ChoicePicker::ChoicePicker(const ChoicePicker& orig) :
        manager(orig.manager),
        containers(orig.containers)
{}

ChoicePicker::~ChoicePicker() {
}

///////////////////////
// Getters / Setters //
///////////////////////

std::vector<ChoiceContainer*>& ChoicePicker::getContainers() {
    return containers;
}


//////////////////////
// Advanced Getters //
//////////////////////

std::pair<int, int>& ChoicePicker::getPair() {

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
