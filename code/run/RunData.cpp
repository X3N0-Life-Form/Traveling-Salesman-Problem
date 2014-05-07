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
    this->endPoint.setProblem(endPoint->getProblem());
    this->endPoint.setPath(endPoint->getPath());
    this->endPoint.setCost(endPoint->getCost());
}

void RunData::setBeginTime(std::chrono::steady_clock::time_point* beginTime) {
    this->beginTime = beginTime;
}

void RunData::setEndTime(std::chrono::steady_clock::time_point* endTime) {
    this->endTime = endTime;
}

std::string RunData::getRunTimeString() {
    std::string res;
    auto h = std::chrono::duration_cast<std::chrono::hours>
        (*endTime - *beginTime);
    auto min = std::chrono::duration_cast<std::chrono::minutes>
        (*endTime - *beginTime);
    auto sec = std::chrono::duration_cast<std::chrono::seconds>
        (*endTime - *beginTime);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>
        (*endTime - *beginTime);
    
    if (h.count() > 0) {
        res.append(std::to_string(h.count()));
        res.append("h ");
    }
    
    if (min.count() > 0) {
        res.append(std::to_string(min.count()));
        res.append(" min ");
    }
    
    res.append(std::to_string(sec.count()));
    res.append(".");
    res.append(std::to_string(ms.count()));
    res.append(" sec");
    
    return res;
}


std::ostream& operator<<(std::ostream& out, RunData& data) {
    out << "Run Data: Relation=" << data.getRelation()->getType()
            << ";\tStrategy=" << data.getStrategy()->getType()
            << ";\tstarting cost=" << data.getStartingPoint().getCost()
            << ",\tend cost=" << data.getEndPoint().getCost()
            << ";\tdepth=" << data.getDepth()
            << ";\trun time= " << data.getRunTimeString();
    return out;
}