/* 
 * File:   ChoicePicker.cpp
 * Author: etudiant
 * 
 * Created on 16 juin 2014, 09:49
 */

#include "ChoicePicker.h"

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

void ChoicePicker::prepareContainers() {

}
