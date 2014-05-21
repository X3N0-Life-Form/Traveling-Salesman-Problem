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

struct t_startingPoint {
    bool useSameStartingPoint;
    bool initialized;
    int* path;
    int cost;
};
typedef t_startingPoint StartingPoint;

class Runner {
private:
    Problem& problem;
    int maxDepth;
    bool noDepth;
    StartingPoint* startingPoint;
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
    
    int getMaxDepth() const;
    void setMaxDepth(int maxDepth);
    bool getNoDepth();
    void setNoDepth(bool noDepth);
    
    void setSameStartingPoint(bool useSameStartingPoint);
    
    std::list<Strategy*>& getStrategies();
    void addStrategy(Strategy* s);
    void addStrategy(Strategy& s);
    
    std::list<Relation*> getRelations();
    void addRelation(Relation* r);
    void addRelation(Relation& r);
    // other methods
    void run();
    void clear();
    std::ostream& outputResults(std::ostream& out = std::cout);
    std::ostream& outputResultsCSV(std::ostream& out = std::cout);
};

#endif	/* RUNNER_H */

