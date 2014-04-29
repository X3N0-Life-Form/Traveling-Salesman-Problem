/* 
 * File:   Relation.h
 * Author: etudiant
 *
 * Created on 23 avril 2014, 17:43
 */

#ifndef RELATION_H
#define	RELATION_H

#include "../core/Neighborhood.h"
#include "../strategy/Strategy.h"

class Relation {
protected:
    Problem& problem;
    Strategy& strategy;
public:
    Relation(Problem& problem, Strategy& strategy);
    Relation(const Relation& orig);
    virtual ~Relation();
    // abstract methods
    virtual Neighborhood& applyRelation(const Neighborhood& n) = 0;
    virtual std::string getType() = 0;
    // Getters/Setters
    void setStrategy(Strategy& s);
};

#endif	/* RELATION_H */

