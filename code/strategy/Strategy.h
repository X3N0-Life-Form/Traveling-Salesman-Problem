/* 
 * File:   Strategy.h
 * Author: etudiant
 *
 * Created on 24 avril 2014, 11:04
 */

#ifndef STRATEGY_H
#define	STRATEGY_H

#include "../neighborhood/Neighborhood.h"
class Strategy {
public:
    Strategy(int initialCost, int dimension);
    Strategy(const Strategy& orig);
    virtual ~Strategy();
    // abstract methods
    virtual bool applyStrategy(int* nuPath, int nuCost) = 0;
    virtual int* getFit() = 0;
    virtual void reset() = 0;
    // Getters / Setters
    int getInitialCost();
    void setInitialCost(int initialCost);
    
protected:
    int* fit;
    int initialCost;
    int dimension;
};

#endif	/* STRATEGY_H */

