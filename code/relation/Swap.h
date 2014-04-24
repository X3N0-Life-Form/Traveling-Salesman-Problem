/* 
 * File:   Swap.h
 * Author: etudiant
 *
 * Created on 24 avril 2014, 10:04
 */

#ifndef SWAP_H
#define	SWAP_H

#include "Relation.h"

class Swap : public Relation {
public:
    Swap(Problem& problem, Strategy& strategy);
    Swap(const Swap& orig);
    virtual ~Swap();
    virtual Neighborhood& applyRelation(Neighborhood& n);

private:

};

#endif	/* SWAP_H */

