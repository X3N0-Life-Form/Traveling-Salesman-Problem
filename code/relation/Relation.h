/* 
 * File:   Relation.h
 * Author: etudiant
 *
 * Created on 23 avril 2014, 17:43
 */

#ifndef RELATION_H
#define	RELATION_H

#include "../core/Neighborhood.h"
#include "../strategy/Strategy.h"

class Relation {
protected:
    Problem& problem;
    Strategy* strategy;
    bool isFirstLoop = true;
    std::vector<std::pair<int, int> >* pairs;
    bool noNeighborhoodCutoff;
public:
    Relation(Problem& problem, Strategy* strategy);
    Relation(const Relation& orig);
    /**
     * Does NOT delete the Strategy pointer.
     */
    virtual ~Relation();
    // abstract methods
    virtual Neighborhood* applyRelation(const Neighborhood& n, bool randomPick = true) = 0;
    virtual std::string getType() const = 0;
    // common methods
    void pairAndShuffle(PairingMode mode);
    Neighborhood* useThisPath(const Neighborhood& n, int* nuPath = NULL);
    std::pair<int, int> getPair(int index, bool randomPick);
    void deletePairs();
    void printLoopStatus(int count);
    // Getters/Setters
    Strategy* getStrategy() const;
    void setStrategy(Strategy* s);
    void setIsFirstLoop(bool isFirstLoop);
    void setNoNeighborhoodCutoff(bool cutoff);
};

#endif	/* RELATION_H */

