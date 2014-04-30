/* 
 * File:   Runner.h
 * Author: etudiant
 *
 * Created on 29 avril 2014, 09:55
 */

#ifndef RUNNER_H
#define	RUNNER_H

#include "../utils.h"
#include "../core/Problem.h"
#include "../relation/Relation.h"
#include "../strategy/Strategy.h"
#include "RunData.h"

class Runner {
private:
    Problem& problem;
    int maxDepth;
    // Note: using pointers cause we can't allocate memory for an abstract type
    std::list<Strategy*> strategies;
    std::list<Relation*> relations;
    std::list<RunData> results;
public:
    Runner(Problem& problem, int depth = 1);
    Runner(const Runner& orig);
    virtual ~Runner();
    // Getters/Setters/Adders
    std::list<RunData>& getResults();
    void setMaxDepth(int maxDepth);
    void addStrategy(Strategy* s);
    void addStrategy(Strategy& s);
    void addRelation(Relation* r);
    void addRelation(Relation& r);
    // other methods
    void run();
    void clear();
    std::ostream& outputResults(std::ostream& out = std::cout);
};

#endif	/* RUNNER_H */

