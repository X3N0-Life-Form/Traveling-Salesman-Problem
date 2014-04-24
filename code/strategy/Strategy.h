/* 
 * File:   Strategy.h
 * Author: etudiant
 *
 * Created on 24 avril 2014, 11:04
 */

#ifndef STRATEGY_H
#define	STRATEGY_H

#include "../neighborhood/Neighborhood.h"
#include <vector>

class Strategy {
public:
    Strategy(int initialCost);
    Strategy(const Strategy& orig);
    virtual ~Strategy();
private:

public:
    virtual bool applyStrategy(int* nuPath, int nuCost) = 0;
    // Getters / Setters
    int getInitialCost();
    void setInitialCost(int initialCost);
protected:
    std::vector<int*> history;
    int initialCost;
};

#endif	/* STRATEGY_H */

