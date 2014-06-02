/* 
 * File:   Interval.h
 * Author: etudiant
 *
 * Created on 2 juin 2014, 08:55
 */

#ifndef INTERVAL_H
#define	INTERVAL_H

#include <vector>

#include "Action.h"

class Interval {
private:
    int minDistance;
    int maxDistance;
    std::vector<Action*> actions;
public:
    Interval(int min, int max);
    Interval(const Interval& orig);
    virtual ~Interval();
    // Getters/Setters/Adders
    int getMinDistance();
    int getMaxDistance();
    void addAction(Action* action);
};

#endif	/* INTERVAL_H */

