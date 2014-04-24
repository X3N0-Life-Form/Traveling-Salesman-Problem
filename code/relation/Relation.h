/* 
 * File:   Relation.h
 * Author: etudiant
 *
 * Created on 23 avril 2014, 17:43
 */

#ifndef RELATION_H
#define	RELATION_H

#include "../neighborhood/Neighborhood.h"

class Relation {
public:
    Relation();
    Relation(const Relation& orig);
    virtual ~Relation();
    virtual Neighborhood& applyRelation(Neighborhood& n) = 0;
private:

};

#endif	/* RELATION_H */

