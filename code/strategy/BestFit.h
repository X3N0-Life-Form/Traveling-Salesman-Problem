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
    BestFit(int dimension, int initialCost = INT_MAX);
    BestFit(const BestFit& orig);
    virtual ~BestFit();
    // implemented methods
    virtual bool applyStrategy(int* nuPath, int nuCost, int counter = 0);
    virtual void reset();
    virtual std::string getType() const;
};

#endif	/* BESTFIT_H */

