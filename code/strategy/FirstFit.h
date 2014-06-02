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
    FirstFit(int dimension, int initialCost = INT_MAX);
    FirstFit(const FirstFit& orig);
    virtual ~FirstFit();
    // overridden methods
    virtual bool applyStrategy(int* nuPath, int nuCost, int counter = 0,
            std::pair<int, int> pair = std::make_pair(-1, -1));
    virtual std::string getType() const;
};

#endif	/* FIRSTFIT_H */

