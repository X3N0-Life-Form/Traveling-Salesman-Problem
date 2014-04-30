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
    Swap(Problem& problem);
    Swap(Problem& problem, Strategy& strategy);
    Swap(const Swap& orig);
    virtual ~Swap();
    // implemented methods
    virtual Neighborhood* applyRelation(const Neighborhood& n);
    virtual std::string getType();
};

#endif	/* SWAP_H */

