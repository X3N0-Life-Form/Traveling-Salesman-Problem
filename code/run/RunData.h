/* 
 * File:   RunData.h
 * Author: etudiant
 *
 * Created on 29 avril 2014, 11:17
 */

#ifndef RUNDATA_H
#define	RUNDATA_H

#include "../relation/Relation.h"
#include "../strategy/Strategy.h"
#include "../core/Neighborhood.h"

class RunData {
private:
    Relation* relation;
    Strategy* strategy;
    Neighborhood startingPoint;
    Neighborhood endPoint;
    int depth;
public:
    RunData(Relation* r, Strategy* s, Neighborhood* startingPoint);
    RunData(const RunData& orig);
    virtual ~RunData();
    // Getters/Setters
    Relation* getRelation();
    Strategy* getStrategy();
    Neighborhood& getStartingPoint();
    Neighborhood& getEndPoint();
    void setEndPoint(Neighborhood& endPoint);
    int getDepth();
    void setDepth(int depth);
};

std::ostream& operator<<(std::ostream& out, RunData& data);

#endif	/* RUNDATA_H */

