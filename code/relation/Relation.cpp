/* 
 * File:   Relation.cpp
 * Author: etudiant
 * 
 * Created on 23 avril 2014, 17:43
 */

#include "Relation.h"

#include <algorithm>
#include <random>
#include "../utils.h"
#include "../core/Neighborhood.h"

Relation::Relation(Problem& problem, Strategy& strategy) :
        problem(problem),
        strategy(strategy),
        pairs(NULL)
{}

Relation::Relation(const Relation& orig) :
        problem(orig.problem),
        strategy(orig.strategy),
        pairs(orig.pairs)
{}

Relation::~Relation() {
    delete(pairs);
}

void Relation::pairAndShuffle(PairingMode mode) {
    if (pairs != NULL) {
        delete(pairs);
        pairs = NULL;
    }
    pairs = problem.getCityPairs(mode);
    strategy.setStopCount(pairs->size());
    std::random_shuffle(pairs->begin(), pairs->end());
    PRINTLN("Going through " << pairs->size() << " pairs...");
    isFirstLoop = false;
}

Neighborhood* Relation::useThisPath(int* nuPath, const Neighborhood& n) {
    Neighborhood* nuN = new Neighborhood(n);
    nuN->setPath(strategy.getFit());
    nuN->setCost(strategy.getFitCost());
    delete[](nuPath);
    return nuN;
}

std::pair<int, int> Relation::getPair(int index, bool randomPick) {
    std::pair<int, int> randomPair;
    if (randomPick && index < pairs->size() - 1) {
        // turns out this section of code takes a humongus buttload of time
        //std::random_device rd;
        //int randomIndex = rd() % (pairs.size() - index - 1);
        //randomPair = pairs[randomIndex];
        // so let's pipe it down shall we?
        randomPair = pairs->at(index);
    } else {
        randomPair = pairs->at(index);
    }
    return randomPair;
}

void Relation::deletePairs() {
    delete(pairs);
    pairs = NULL;
}

Strategy& Relation::getStrategy() const {
    return strategy;
}

void Relation::setStrategy(Strategy& s) {
    strategy = s;
}

void Relation::setIsFirstLoop(bool isFirstLoop) {
    this->isFirstLoop = isFirstLoop;
}
