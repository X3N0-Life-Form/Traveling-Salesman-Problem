/* 
 * File:   WorstFit.h
 * Author: etudiant
 *
 * Created on 28 avril 2014, 15:03
 */

#ifndef WORSTFIT_H
#define	WORSTFIT_H

#include "Strategy.h"


class WorstFit : public Strategy {
public:
    WorstFit(int dimension, int initialCost = INT_MAX);
    WorstFit(const WorstFit& orig);
    virtual ~WorstFit();
    // implemented methods
    virtual bool applyStrategy(int* nuPath, int nuCost, int counter = 0);
    virtual void reset();
    virtual std::string getType();
};

#endif	/* WORSTFIT_H */

