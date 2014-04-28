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

    virtual bool applyStrategy(int* nuPath, int nuCost, int counter = 0);
    virtual void reset();
};

#endif	/* BESTFIT_H */

