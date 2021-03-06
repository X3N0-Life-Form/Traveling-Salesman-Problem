/* 
 * File:   Reverse.h
 * Author: etudiant
 *
 * Created on 26 mai 2014, 14:40
 */

#ifndef REVERSE_H
#define	REVERSE_H

#include "Relation.h"

class Reverse : public Relation {
public:
    // Constructors / Destructor
    Reverse(Problem& problem, Strategy* strategy);
    Reverse(const Reverse& orig);
    virtual ~Reverse();
    // Implemented Methods
    virtual Neighborhood* applyRelation(const Neighborhood& n, bool randomPick = true);
    virtual std::string getType() const;
};

#endif	/* REVERSE_H */

