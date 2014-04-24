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
    FirstFit(int initialCost);
    FirstFit(const FirstFit& orig);
    virtual ~FirstFit();
private:

public:
    virtual bool applyStrategy(int* nuPath, int nuCost);

};

#endif	/* FIRSTFIT_H */

