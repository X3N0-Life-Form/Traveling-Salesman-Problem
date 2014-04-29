/* 
 * File:   Strategy.h
 * Author: etudiant
 *
 * Created on 24 avril 2014, 11:04
 */

#ifndef STRATEGY_H
#define	STRATEGY_H

#include "../core/Neighborhood.h"
class Strategy {
public:
    Strategy(int initialCost, int dimension);
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
    virtual std::string getType() = 0;
    // Getters / Setters
    int getInitialCost();
    void setInitialCost(int initialCost);
    int* getFit();
    int getFitCost();
    
protected:
    int* fit;
    int fitCost;
    int initialCost;
    int dimension;
};

#endif	/* STRATEGY_H */

