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
    double probability;
    int dimension;
    Action* latestAction;
public:
    // Constructors / Destructor
    Interval(int min, int max);
    Interval(const Interval& orig);
    virtual ~Interval();
    // Getters / Setters / Adders
    int getMinDistance() const;
    void setMinDistance(int min);
    int getMaxDistance() const;
    void setMaxDistance(int max);
    const std::vector<Action*>& getActions() const;
    void addAction(Action* action);
    double getProbability() const;
    void setProbability(double probability);
    void setDimension(int dimension);
    Action* getLatestAction();
    // Advanced Getters
    bool includes(const std::pair<int, int>& pair);
};

// Operators
std::ostream& operator<<(std::ostream& out, const Interval& interval);
std::ostream& operator<<(std::ostream& out, const Interval* interval);

#endif	/* INTERVAL_H */

