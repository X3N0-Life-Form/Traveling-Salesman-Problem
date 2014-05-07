/* 
 * File:   Runner.cpp
 * Author: etudiant
 * 
 * Created on 29 avril 2014, 09:55
 */

#include "Runner.h"

Runner::Runner(Problem& problem, int maxDepth) :
    problem(problem), maxDepth(maxDepth) {
}

Runner::Runner(const Runner& orig) :
    problem(orig.problem),
    strategies(orig.strategies),
    relations(orig.relations),
    maxDepth(orig.maxDepth) {
}

Runner::~Runner() {
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
    for (Relation* r : relations) {
        for (Strategy* s : strategies) {
            r->setStrategy(*s);
            
            PRINTLN("Running " << r->getType()
                    << " with strategy " << s->getType());
            Neighborhood* n = new Neighborhood(problem);
            n->generateRandomNeighborhood();
            n->calculateCost();
            RunData data(r, s, n);
            data.setDepth(maxDepth);
            PRINTLN("Initial cost=\t" << n->getCost());
            
            for (int i = 0; i < maxDepth; i++) {
                int oldCost = n->getCost();
                n = r->applyRelation(*n);
                // no better result was produced
                if (n->getCost() == oldCost) {
                    data.setDepth(i);
                    break;
                }//TODO:delete old n?
            }
            
            PRINTLN("End cost=\t" << n->getCost());
            data.setEndPoint(n);
            results.push_back(data);
        }
    }
}

std::ostream& Runner::outputResults(std::ostream& out) {
    out << "\nRun Results for " << problem.getName() << ":\n";
    for (RunData data : results) {
        out << data << std::endl;
    }
    return out;
}

void Runner::clear() {
    strategies.clear();
    relations.clear();
    results.clear();
}
