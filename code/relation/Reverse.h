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
    Reverse(Problem& problem, Strategy& strategy);
    Reverse(const Reverse& orig);
    virtual ~Reverse();

    virtual Neighborhood* applyRelation(const Neighborhood& n, bool randomPick);
    virtual std::string getType();

};

#endif	/* REVERSE_H */

