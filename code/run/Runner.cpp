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
            n->generateRandomNeighborhood();
            n->calculateCost();
            RunData data(r, s, n);
            data.setDepth(maxDepth);
            
            for (int i = 0; i < maxDepth; i++) {
                int cost = n->getCost();
                n = r->applyRelation(*n);
                // no better result was produced
                if (n->getCost() == cost) {
                    data.setDepth(i);
                    break;
                }//TODO:delete old n?
            }
            
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