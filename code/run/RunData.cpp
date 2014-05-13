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
        startingPoint(orig.startingPoint), endPoint(orig.endPoint),
        depth(orig.depth),
        beginTime(orig.beginTime), endTime(orig.endTime)
{}

RunData::~RunData() {
    //delete(strategy);
    //delete(relation);
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

void RunData::setBeginTime(std::chrono::steady_clock::time_point beginTime) {
    this->beginTime = beginTime;
}

void RunData::setEndTime(std::chrono::steady_clock::time_point endTime) {
    this->endTime = endTime;
}

std::string RunData::getRunTimeString() {
    std::string res;
    std::chrono::steady_clock::duration diff = endTime - beginTime;
    auto h = std::chrono::duration_cast<std::chrono::hours> (diff);
    auto min = std::chrono::duration_cast<std::chrono::minutes> (diff);
    auto sec = std::chrono::duration_cast<std::chrono::seconds> (diff);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds> (diff);
    
    if (h.count() > 0) {
        res.append(std::to_string(h.count()));
        res.append("h ");
    }
    
    if (min.count() > 0) {
        res.append(std::to_string(min.count() % 60));
        res.append(" min ");
    }
    
    res.append(std::to_string(sec.count() % 60));
    res.append(".");
    if (ms.count() < 100)
        res.append("0");
    if (ms.count() < 10)
        res.append("0");
    res.append(std::to_string(ms.count() % 1000));
    res.append(" sec");
    
    return res;
}

std::string RunData::getRunTimeSeconds() {
    std::string res;
    std::chrono::steady_clock::duration diff = endTime - beginTime;
    auto sec = std::chrono::duration_cast<std::chrono::seconds> (diff);
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds> (diff);
    
    res.append(std::to_string(sec.count()));
    res.append(".");
    res.append(std::to_string(ms.count() % 1000));
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