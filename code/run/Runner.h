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
#include "interval/IntervalManager.h"

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
    bool doubleCheckCost;
    bool noNeighborhoodCutoff;
    bool printIntervalData;
    std::ostream* intervalDataCSVoutput;
    // Note: using pointers cause we can't allocate memory for an abstract type
    std::list<Strategy*> strategies;
    std::list<Relation*> relations;
    // and because copying shit around is kinda bad for your memory usage
    std::list<RunData*> results;
    std::list<IntervalManager*> intervalManagers;
public:
    Runner(Problem& problem, int depth = 1);
    Runner(const Runner& orig);
    /**
     * Note: does not delete the intervalDataCSVoutput pointer.
     */
    virtual ~Runner();
    // Getters/Setters/Adders
    std::list<RunData*>& getResults();
    
    int getMaxDepth() const;
    void setMaxDepth(int maxDepth);
    bool getNoDepth();
    void setNoDepth(bool noDepth);
    
    void setSameStartingPoint(bool useSameStartingPoint);
    void setDoubleCheckCost(bool doubleCheck);
    void setNoNeighborhoodCutoff(bool cutoff);
    
    void setPrintIntervalData(bool print);
    void setIntervalDataCSVoutput(std::ostream* out);
    
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

