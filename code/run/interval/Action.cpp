/* 
 * File:   Action.cpp
 * Author: etudiant
 * 
 * Created on 2 juin 2014, 09:06
 */

#include "Action.h"

////////////////////////////////
// Constructors / Destructors //
////////////////////////////////

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

///////////////////////
// Getters / Setters //
///////////////////////

int Action::getCostDiff() const {
    return costDiff;
}

const std::pair<int, int>& Action::getPair() const {
    return pair;
}

std::ostream& operator<<(std::ostream& out, const Action& action) {
    out << "Action: <"
            << action.getPair().first << ", " << action.getPair().second << ">"
            << "; costDiff=" << action.getCostDiff();
    return out;
}

std::ostream& operator<<(std::ostream& out, const Action* action) {
    out << *action;
    return out;
}