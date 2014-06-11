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
    // Constructors / Destructor
    WorstFit(int dimension, int initialCost = INT_MAX);
    WorstFit(const WorstFit& orig);
    virtual ~WorstFit();
    // Implemented Methods
    virtual bool applyStrategy(int* nuPath, int nuCost, int counter = 0,
            std::pair<int, int> pair = std::make_pair(-1, -1));
    virtual std::string getType() const;
};

#endif	/* WORSTFIT_H */

