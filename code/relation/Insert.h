/* 
 * File:   Insert.h
 * Author: etudiant
 *
 * Created on 14 mai 2014, 11:12
 */

#ifndef INSERT_H
#define	INSERT_H

#include "Relation.h"

class Insert : public Relation {
public:
    Insert(Problem& problem, Strategy& strategy);
    Insert(const Insert& orig);
    virtual ~Insert();
    // implemented methods
    virtual Neighborhood* applyRelation(const Neighborhood& n, bool randomPick = true);
    virtual std::string getType();
};

#endif	/* INSERT_H */

