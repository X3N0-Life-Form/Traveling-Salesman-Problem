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
    Strategy();
    Strategy(const Strategy& orig);
    virtual ~Strategy();
private:

public:
    virtual bool applyStrategy(int* nuPath, int nuCost) = 0;
};

#endif	/* STRATEGY_H */

