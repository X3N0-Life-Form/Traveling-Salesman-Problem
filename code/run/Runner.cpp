/* 
 * File:   Runner.cpp
 * Author: etudiant
 * 
 * Created on 29 avril 2014, 09:55
 */

#include "Runner.h"

#include <chrono>

Runner::Runner(Problem& problem, int maxDepth) :
        problem(problem),
        maxDepth(maxDepth),
        noDepth(false)
{
    startingPoint = new StartingPoint();
    startingPoint->cost = -1;
    startingPoint->initialized = false;
    startingPoint->useSameStartingPoint = false;
    startingPoint->path = NULL;
}

Runner::Runner(const Runner& orig) :
        problem(orig.problem),
        strategies(orig.strategies),
        relations(orig.relations),
        maxDepth(orig.maxDepth),
        noDepth(orig.noDepth),
        startingPoint(orig.startingPoint)
{}

Runner::~Runner() {
    delete(startingPoint);
}

std::list<RunData>& Runner::getResults() {
    return results;
}

int Runner::getMaxDepth() const {
    return maxDepth;
}

void Runner::setMaxDepth(int maxDepth) {
    this->maxDepth = maxDepth;
}

bool Runner::getNoDepth() {
    return noDepth;
}

void Runner::setNoDepth(bool noDepth) {
    this->noDepth = noDepth;
}

void Runner::setSameStartingPoint(bool useSameStartingPoint) {
    startingPoint->useSameStartingPoint = useSameStartingPoint;
}

std::list<Strategy*>& Runner::getStrategies() {
    return strategies;
}

void Runner::addStrategy(Strategy* s) {
    strategies.push_back(s);
}

void Runner::addStrategy(Strategy& s) {
    strategies.push_back(&s);
}

std::list<Relation*> Runner::getRelations() {
    return relations;
}

void Runner::addRelation(Relation* r) {
    relations.push_back(r);
}

void Runner::addRelation(Relation& r) {
    relations.push_back(&r);
}

void Runner::run() {
    std::chrono::steady_clock clock;
    for (Relation* r : relations) {
        for (Strategy* s : strategies) {//TODO: use multiple threads
            r->setStrategy(*s);
            bool randomPick = true;
            if (s->getType() != "First Fit") {
                randomPick = false;
            }
            
            PRINTLN("Running " << r->getType()
                    << " with strategy " << s->getType());
            Neighborhood* n = new Neighborhood(problem);
            if (startingPoint->useSameStartingPoint && startingPoint->initialized) {
                n->setCost(startingPoint->cost);
                ARRAY_COPY(n->getPath(), startingPoint->path, problem.getDimension());
            } else {
                n->generateRandomNeighborhood();
                n->calculateCost();
                if (startingPoint->useSameStartingPoint) {
                    startingPoint->cost = n->getCost();
                    ARRAY_COPY(startingPoint->path, n->getPath(), problem.getDimension());
                    startingPoint->initialized = true;
                }
            }
            RunData data(r, s, n);
            data.setDepth(maxDepth);
            PRINTLN("Initial cost=\t" << n->getCost());
            
            std::chrono::steady_clock::time_point beginning = clock.now();
            for (int i = 0; i < maxDepth || noDepth; i++) {
                int oldCost = n->getCost();
                Neighborhood* oldN = n;
                n = r->applyRelation(*n, randomPick);
                // no better result was produced
                if (n->getCost() == oldCost) {
                    data.setDepth(i);
                    break;
                }
                delete(oldN);
            }
            std::chrono::steady_clock::time_point end = clock.now();
            r->setIsFirstLoop(true);
            
            PRINTLN("End cost=\t" << n->getCost());
            data.setEndPoint(n);
            data.setBeginTime(beginning);
            data.setEndTime(end);
            PRINTLN("\tRuntime= " << data.getRunTimeString());
            delete(n);
            results.push_back(data);
        }
        // don't keep stuff that's too memory heavy
        r->deletePairs();
    }
}

std::ostream& Runner::outputResults(std::ostream& out) {
    out << "\nRun Results for " << problem.getName() << ":\n";
    for (RunData data : results) {
        out << data << std::endl;
    }
    return out;
}

std::ostream& Runner::outputResultsCSV(std::ostream& out) {
    for (RunData data : results) {
        out << problem.getName() << ","
                << data.getRelation()->getType() << ","
                << data.getStrategy()->getType() << ","
                << data.getStartingPoint().getCost() << ","
                << data.getEndPoint().getCost() << ","
                << data.getDepth() << ","
                << data.getRunTimeSeconds()
                << "\n";
    }
    return out;
}

void Runner::clear() {
    strategies.clear();
    relations.clear();
    results.clear();
}
