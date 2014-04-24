/* 
 * File:   Relation.h
 * Author: etudiant
 *
 * Created on 23 avril 2014, 17:43
 */

#ifndef RELATION_H
#define	RELATION_H

#include "../neighborhood/Neighborhood.h"
#include "../strategy/Strategy.h"

class Relation {
public:
    Relation(Problem& problem, Strategy& strategy);
    Relation(const Relation& orig);
    virtual ~Relation();
    virtual Neighborhood& applyRelation(Neighborhood& n) = 0;
protected:
    Problem& problem;
    Strategy& strategy;
private:

};

#endif	/* RELATION_H */

