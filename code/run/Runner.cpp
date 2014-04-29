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

void Runner::addStrategy(Strategy* s) {
    strategies.push_back(s);
}

void Runner::addStrategy(Strategy& s) {
    strategies.push_back(&s);
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
            Neighborhood* n = new Neighborhood(problem);
            PRINTLN("#1 n.dimension="<<n->getDimension()<<"; problem.dimension="<<problem.getDimension());
            n->generateRandomNeighborhood();
            n->calculateCost();
            RunData data(r, s, n);
            data.setDepth(maxDepth);
            PRINTLN("#2 n.dimension="<<n->getDimension()<<"; problem.dimension="<<problem.getDimension());
            
            for (int i = 0; i < maxDepth; i++) {
                int cost = n->getCost();
                n = &r->applyRelation(*n);
                if (n->getCost() == cost) {
                    data.setDepth(i);
                    break;
                }
            }
            PRINTLN("#3 n.dimension="<<n->getDimension()<<"; problem.dimension="<<problem.getDimension());
            
            PRINTLN("End point="<<n);
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
