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
    // Constructors / Destructor
    Insert(Problem& problem, Strategy* strategy);
    Insert(const Insert& orig);
    virtual ~Insert();
    // Implemented Methods
    virtual Neighborhood* applyRelation(const Neighborhood& n, bool randomPick = true);
    virtual std::string getType() const;
};

#endif	/* INSERT_H */

