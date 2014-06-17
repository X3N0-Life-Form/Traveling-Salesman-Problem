/* 
 * File:   ChoiceContainer.cpp
 * Author: etudiant
 * 
 * Created on 16 juin 2014, 09:52
 */

#include <vector>

#include "ChoiceContainer.h"

///////////////////////////////
// Constructors / Destructor //
///////////////////////////////

ChoiceContainer::ChoiceContainer(Interval* interval) :
        interval(interval),
        index(0)
{}

ChoiceContainer::ChoiceContainer(const ChoiceContainer& orig) :
        interval(orig.interval),
        pairs(orig.pairs),
        index(orig.index)
{}

ChoiceContainer::~ChoiceContainer() {
}

////////////////////////////////
// Getters / Setters / Adders //
////////////////////////////////

unsigned int ChoiceContainer::size() {
    return pairs.size();
}

int ChoiceContainer::getIndex() {
    return index;
}

Interval* ChoiceContainer::getInterval() {
    return interval;
}

void ChoiceContainer::addPair(std::pair<int, int>& pair) {
    pairs.push_back(pair);
}

//////////////////////
// Advanced Getters //
//////////////////////

std::pair<int, int> ChoiceContainer::getNextPair() {
    // If empty, return a "neutral" pair
    if (pairs.size() == 0)
        return std::pair<int, int>(1, 1);
    std::pair<int, int>& result = pairs[index++];
    if (index == pairs.size())
        index = 0;
    return result;
}
