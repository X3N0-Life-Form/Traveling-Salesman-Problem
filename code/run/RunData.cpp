/* 
 * File:   RunData.cpp
 * Author: etudiant
 * 
 * Created on 29 avril 2014, 11:17
 */

#include "RunData.h"

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

void RunData::setDepth(int depth) {
    this->depth = depth;
}

void RunData::setEndPoint(Neighborhood& endPoint) {
    this->endPoint = endPoint;
}
