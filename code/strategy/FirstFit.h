/* 
 * File:   FirstFit.h
 * Author: etudiant
 *
 * Created on 24 avril 2014, 14:56
 */

#ifndef FIRSTFIT_H
#define	FIRSTFIT_H

#include "Strategy.h"

class FirstFit : public Strategy {
public:
    FirstFit(int initialCost, int dimension);
    FirstFit(const FirstFit& orig);
    virtual ~FirstFit();
    // overridden methods
    virtual bool applyStrategy(int* nuPath, int nuCost, int counter = 0);
    virtual void reset();
    virtual std::string getType();
};

#endif	/* FIRSTFIT_H */

