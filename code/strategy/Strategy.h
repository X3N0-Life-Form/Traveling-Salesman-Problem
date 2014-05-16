/* 
 * File:   Strategy.h
 * Author: etudiant
 *
 * Created on 24 avril 2014, 11:04
 */

#ifndef STRATEGY_H
#define	STRATEGY_H

#include <climits>
#include "../core/Neighborhood.h"

class Strategy {
protected:
    int* fit;
    int fitCost;
    int initialCost;
    int dimension;
    int stopCount;
public:
    Strategy();
    Strategy(int dimension, int initialCost = INT_MAX);
    Strategy(const Strategy& orig);
    virtual ~Strategy();
    // abstract methods
    /**
     * 
     * @param nuPath
     * @param nuCost
     * @param counter
     * @return true the Strategy's requirements are met (ie. not need to
     * continue looping).
     */
    virtual bool applyStrategy(int* nuPath, int nuCost, int counter = 0) = 0;
    virtual void reset() = 0;
    /**
     * Useful when outputting a Strategy.
     * @return The name of this type of Strategy (ie. First Fit, Best Fit, ...)
     */
    virtual std::string getType() const = 0;
    // Getters / Setters
    int getDimension() const;
    int getInitialCost() const;
    void setInitialCost(int initialCost);
    int* getFit();
    int getFitCost();
    int getStopCount();
    void setStopCount(int count);
};

bool operator==(const Strategy& left, const Strategy& right);
bool operator!=(const Strategy& left, const Strategy& right);

#endif	/* STRATEGY_H */

