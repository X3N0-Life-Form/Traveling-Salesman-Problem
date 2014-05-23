/* 
 * File:   RunData.h
 * Author: etudiant
 *
 * Created on 29 avril 2014, 11:17
 */

#ifndef RUNDATA_H
#define	RUNDATA_H

#include <chrono>

#include "../relation/Relation.h"
#include "../strategy/Strategy.h"
#include "../core/Neighborhood.h"

struct t_neighborhoodLite {
    //Problem& problem;
    int cost;
    //int* path;
};
typedef t_neighborhoodLite NeighborhoodLite;

class RunData {
private:
    Relation* relation;
    Strategy* strategy;
    NeighborhoodLite* startingPoint;
    NeighborhoodLite* endPoint;
    int depth;
    std::chrono::steady_clock::time_point beginTime;
    std::chrono::steady_clock::time_point endTime;
public:
    RunData(Relation* r, Strategy* s, Neighborhood* startingPoint);
    RunData(const RunData& orig);
    virtual ~RunData();
    // Getters/Setters
    Relation* getRelation();
    Strategy* getStrategy();
    NeighborhoodLite* getStartingPoint();
    NeighborhoodLite* getEndPoint();
    /**
     * Note: copies the contents of the pointed Neighborhood.
     * @param endPoint
     */
    void setEndPoint(Neighborhood* endPoint);
    int getDepth();
    void setDepth(int depth);
    void setBeginTime(std::chrono::steady_clock::time_point beginTime);
    void setEndTime(std::chrono::steady_clock::time_point endTime);
    // Advanced Getters
    std::string getRunTimeString();
    std::string getRunTimeSeconds();
};

std::ostream& operator<<(std::ostream& out, RunData& data);

#endif	/* RUNDATA_H */

