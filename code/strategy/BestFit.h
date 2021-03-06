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
    // Construtors / Destructor
    BestFit(int dimension, int initialCost = INT_MAX);
    BestFit(const BestFit& orig);
    virtual ~BestFit();
    // Implemented Methods
    virtual bool applyStrategy(int* nuPath, int nuCost, int counter = 0,
            std::pair<int, int> pair = std::make_pair(-1, -1));
    virtual std::string getType() const;
};

#endif	/* BESTFIT_H */

