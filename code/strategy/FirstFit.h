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
private:
    int* fit;
public:
    virtual bool applyStrategy(int* nuPath, int nuCost);
    virtual int* getFit();
    virtual void reset();
};

#endif	/* FIRSTFIT_H */

