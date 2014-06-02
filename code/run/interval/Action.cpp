/* 
 * File:   Action.cpp
 * Author: etudiant
 * 
 * Created on 2 juin 2014, 09:06
 */

#include "Action.h"

Action::Action(std::pair<int, int> pair, int costDiff) :
        pair(pair),
        costDiff(costDiff)
{}

Action::Action(const Action& orig):
        pair(orig.pair),
        costDiff(orig.costDiff)
{}

Action::~Action() {
}

int Action::getCostDiff() {
    return costDiff;
}

std::pair<int, int>& Action::getPair() {
    return pair;
}
