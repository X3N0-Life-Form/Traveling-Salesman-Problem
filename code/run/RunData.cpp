/* 
 * File:   RunData.cpp
 * Author: etudiant
 * 
 * Created on 29 avril 2014, 11:17
 */

#include "RunData.h"

#include "../utils.h"

RunData::RunData(Relation* r, Strategy* s, Neighborhood* startingPoint) :
    relation(r),
    strategy(s),
    startingPoint(*startingPoint), endPoint(*startingPoint) {
}


RunData::RunData(const RunData& orig) :
        relation(orig.relation),
        strategy(orig.strategy),
        startingPoint(orig.startingPoint),
        endPoint(orig.endPoint),
        depth(orig.depth) {
}

RunData::~RunData() {
}

Relation* RunData::getRelation() {
    return relation;
}

Strategy* RunData::getStrategy() {
    return strategy;
}

int RunData::getDepth() {
    return depth;
}

void RunData::setDepth(int depth) {
    this->depth = depth;
}

Neighborhood& RunData::getStartingPoint() {
    return startingPoint;
}

Neighborhood& RunData::getEndPoint() {
    return endPoint;
}

void RunData::setEndPoint(Neighborhood* endPoint) {
    PRINTLN("Problem="<<endPoint->getProblem().getName());
    this->endPoint.setProblem(endPoint->getProblem());
    this->endPoint.setPath(endPoint->getPath());
    this->endPoint.setCost(endPoint->getCost());
    PRINTLN("setEndPoint="<<this->endPoint.getDimension());
}

std::ostream& operator<<(std::ostream& out, RunData& data) {
    out << "Run Data: Relation=" << data.getRelation()->getType()
            << "; Strategy=" << data.getStrategy()->getType()
            << "; starting cost=" << data.getStartingPoint().getCost()
            << ", end cost=" << data.getEndPoint().getCost();
    return out;
}