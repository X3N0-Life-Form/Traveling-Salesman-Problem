/* 
 * File:   BestFit.h
 * Author: etudiant
 *
 * Created on 24 avril 2014, 16:03
 */

#ifndef BESTFIT_H
#define	BESTFIT_H

#include "Strategy.h"

class BestFit : public Strategy {
public:
    BestFit(int initialCost, int dimension);
    BestFit(const BestFit& orig);
    virtual ~BestFit();
private:
    int counter;
public:
    virtual bool applyStrategy(int* nuPath, int nuCost);
    virtual void reset();
};

#endif	/* BESTFIT_H */

