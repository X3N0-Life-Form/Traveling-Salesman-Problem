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
    // Constructors / Destructor
    Swap(Problem& problem);
    Swap(Problem& problem, Strategy* strategy);
    Swap(const Swap& orig);
    virtual ~Swap();
    // Implemented Methods
    virtual Neighborhood* applyRelation(const Neighborhood& n, bool randomPick = true);
    Neighborhood* applyRelationPartial(const Neighborhood& n);
    virtual std::string getType() const;
};

#endif	/* SWAP_H */

