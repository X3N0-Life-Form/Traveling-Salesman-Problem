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

extern bool main_quietMode;

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
    if (noNeighborhoodCutoff) {
        pairs = problem.getCityPairs(PM_FULL);
    } else {
        pairs = problem.getCityPairs(mode);
    }
    strategy.setStopCount(pairs->size());
    std::random_shuffle(pairs->begin(), pairs->end());
    PRINTLN("Going through " << pairs->size() << " pairs...");
    isFirstLoop = false;
}

Neighborhood* Relation::useThisPath(const Neighborhood& n, int* nuPath) {
    Neighborhood* nuN = new Neighborhood(n);
    nuN->setPath(strategy.getFit());
    nuN->setCost(strategy.getFitCost());
    if (nuPath != NULL)
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

void Relation::printLoopStatus(int count) {
    if (!main_quietMode
            && (float) (count % (pairs->size() / 10) == 0.0f)) {
        //int percent = (float) ((count / pairs->size()) * 100);
        PRINTLN("Loop #" << count << " / " << pairs->size()
                //<< " (" << percent << "% complete)"
                << " ==> Current cost=" << strategy.getFitCost());
    }
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

void Relation::setNoNeighborhoodCutoff(bool cutoff) {
    this->noNeighborhoodCutoff = cutoff;
}
