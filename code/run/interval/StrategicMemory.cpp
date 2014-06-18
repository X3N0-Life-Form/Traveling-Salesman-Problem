/* 
 * File:   StrategicMemory.cpp
 * Author: etudiant
 * 
 * Created on 18 juin 2014, 11:50
 */

#include "StrategicMemory.h"

///////////////////////////////
// Constructors / Destructor //
///////////////////////////////

StrategicMemory::StrategicMemory() {
}

StrategicMemory::StrategicMemory(const StrategicMemory& orig) {
}

StrategicMemory::~StrategicMemory() {
}

////////////////////////////////
// Getters / Setters / Adders //
////////////////////////////////

void StrategicMemory::addAction(Action* action) {
    actionsConsidered.push_back(action);
}

//////////////////////
// Advanced Getters //
//////////////////////

int StrategicMemory::getNumberOfGoodActions() {
    int good = 0;
    for (Action* action : actionsConsidered) {
       if (action->getCostDiff() > 0)  {
           good++;
       }
    }
    return good;
}

int StrategicMemory::getNumberOfBadActions() {
    int bad = 0;
    for (Action* action : actionsConsidered) {
       if (action->getCostDiff() <= 0)  {
           bad++;
       }
    }
    return bad;
}

double StrategicMemory::getGoodToBadRatio() {
    int good = 0;
    int bad = 0;
    for (Action* action : actionsConsidered) {
       if (action->getCostDiff() > 0)  {
           good++;
       } else {
           bad++;
       }
    }
    double dgood = (double) good;
    double dbad = (double) bad;
    if (bad == 0) {
        return 0.0;
    } else {
        return (dgood / (dgood + dbad));
    }
}

///////////////////
// Other Methods //
///////////////////

void StrategicMemory::flushMemory() {
    for (Action* action : actionsConsidered) {
        delete(action);
        action = NULL;
    }
    actionsConsidered.clear();
}
