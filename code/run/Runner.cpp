/* 
 * File:   Runner.cpp
 * Author: etudiant
 * 
 * Created on 29 avril 2014, 09:55
 */

#include "Runner.h"

#include <chrono>

extern bool main_quietMode;

Runner::Runner(Problem& problem, int maxDepth) :
        problem(problem),
        maxDepth(maxDepth),
        noDepth(false),
        doubleCheckCost(false),
        noNeighborhoodCutoff(false)
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
        startingPoint(orig.startingPoint),
        doubleCheckCost(orig.doubleCheckCost),
        noNeighborhoodCutoff(orig.noNeighborhoodCutoff),
        intervalManagers(orig.intervalManagers)
{}

Runner::~Runner() {
    delete(startingPoint);
}

std::list<RunData*>& Runner::getResults() {
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

void Runner::setDoubleCheckCost(bool doubleCheck) {
    this->doubleCheckCost = doubleCheck;
}

void Runner::setNoNeighborhoodCutoff(bool cutoff) {
    this->noNeighborhoodCutoff = cutoff;
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
            r->setStrategy(s);
            IntervalManager* intervalManager = new IntervalManager(s, r);
            intervalManager->prepareIntervals(problem.getDimension());
            
            bool randomPick = true;
            if (s->getType() != "First Fit") {
                randomPick = false;
            }
            // default = false
            r->setNoNeighborhoodCutoff(noNeighborhoodCutoff);

            
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
                    startingPoint->path = new int[problem.getDimension()];
                    ARRAY_COPY(startingPoint->path, n->getPath(), problem.getDimension());
                    startingPoint->initialized = true;
                }
            }
            RunData* data = new RunData(r, s, n);
            data->setDepth(maxDepth);
            PRINTLN("Initial cost=\t" << n->getCost());
            
            std::chrono::steady_clock::time_point beginning = clock.now();
            for (int i = 0; i < maxDepth || noDepth; i++) {
                int oldCost = n->getCost();
                Neighborhood* oldN = n;
                if (!main_quietMode)
                    PRINTLN("Current depth: " << i);
                n = r->applyRelation(*n, randomPick);
                // no better result was produced
                if (n->getCost() == oldCost) {
                    data->setDepth(i);
                    break;
                }
                int costDiff = oldCost - n->getCost();
                intervalManager->memorizeAction(s->getPair(), costDiff);
                PRINTLN(intervalManager);
                delete(oldN);
            }
            if (doubleCheckCost) {
                int potentialCost = n->getCost();
                int actualCost = n->calculateCost();
                if (potentialCost != actualCost) {
                    PRINTLN("WARNING: potential cost & actual cost differ: "
                            << "potential cost = " << potentialCost << "; "
                            << "actual cost = " << actualCost);
                }
            }
            std::chrono::steady_clock::time_point end = clock.now();
            r->setIsFirstLoop(true);
            
            PRINTLN("End cost=\t" << n->getCost());
            data->setEndPoint(n);
            data->setBeginTime(beginning);
            data->setEndTime(end);
            PRINTLN("\tRuntime= " << data->getRunTimeString());
            delete(n);
            delete(intervalManager);
            results.push_back(data);
        }
        // don't keep stuff that's too memory heavy
        r->deletePairs();
    }
}

std::ostream& Runner::outputResults(std::ostream& out) {
    out << "\nRun Results for " << problem.getName() << ":\n";
    for (RunData* data : results) {
        out << *data << std::endl;
    }
    return out;
}

std::ostream& Runner::outputResultsCSV(std::ostream& out) {
    for (RunData* data : results) {
        out << problem.getName() << ","
                << data->getRelation()->getType() << ","
                << data->getStrategy()->getType() << ","
                << data->getStartingPoint()->cost << ","
                << data->getEndPoint()->cost << ","
                << data->getDepth() << ","
                << data->getRunTimeSeconds()
                << "\n";
    }
    return out;
}

void Runner::clear() {
    strategies.clear();
    relations.clear();
    results.clear();
}
