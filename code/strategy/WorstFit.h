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
    WorstFit(int initialCost, int dimension);
    WorstFit(const WorstFit& orig);
    virtual ~WorstFit();

    virtual bool applyStrategy(int* nuPath, int nuCost, int counter = 0);
    virtual void reset();
};

#endif	/* WORSTFIT_H */

