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
    Strategy& strategy;
    bool isFirstLoop = true;
    std::vector<std::pair<int, int> >* pairs;
public:
    Relation(Problem& problem, Strategy& strategy);
    Relation(const Relation& orig);
    virtual ~Relation();
    // abstract methods
    virtual Neighborhood* applyRelation(const Neighborhood& n, bool randomPick = true) = 0;
    virtual std::string getType() = 0;
    // common methods
    void pairAndShuffle(PairingMode mode);
    Neighborhood* useThisPath(int* nuPath, const Neighborhood& n);
    std::pair<int, int> getPair(int index, bool randomPick);
    void deletePairs();
    // Getters/Setters
    Strategy& getStrategy() const;
    void setStrategy(Strategy& s);
    void setIsFirstLoop(bool isFirstLoop);
};

#endif	/* RELATION_H */

