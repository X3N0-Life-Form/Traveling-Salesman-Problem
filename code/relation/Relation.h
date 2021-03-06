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
#include "../hook/Hookable.h"
#include "../hook/Picker.h"

class Relation : public Hookable {
protected:
    Problem& problem;
    Strategy* strategy;
    bool isFirstLoop = true;
    std::vector<std::pair<int, int> >* pairs;
    bool noNeighborhoodCutoff;
    Hookable* hook;
    Picker* picker;
public:
    // Constructors / Destructor
    Relation(Problem& problem, Strategy* strategy);
    Relation(const Relation& orig);
    /**
     * Does NOT delete the Strategy pointer, nor any hook or picker.
     */
    virtual ~Relation();
    // Abstract Methods
    virtual Neighborhood* applyRelation(const Neighborhood& n, bool randomPick = true) = 0;
    virtual std::string getType() const = 0;
    // Common Methods
    void pairAndShuffle(PairingMode mode);
    Neighborhood* useThisPath(const Neighborhood& n, int* nuPath = NULL);
    std::pair<int, int>& getPair(int index, bool randomPick);
    void deletePairs();
    void printLoopStatus(int count);
    // Getters/Setters
    Strategy* getStrategy() const;
    void setStrategy(Strategy* s);
    void setIsFirstLoop(bool isFirstLoop);
    void setNoNeighborhoodCutoff(bool cutoff);
    void setPicker(Picker* picker);
    int getInitialCost();
    // Hookable Methods
    virtual void setHook(Hookable* hook);
    virtual bool processPair(std::pair<int, int>& pair);
    virtual void updateHook(bool accepted);
};

#endif	/* RELATION_H */

