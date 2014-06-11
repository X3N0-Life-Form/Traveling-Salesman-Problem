/*
 * File:   ChoiceMakerTests.cpp
 * Author: etudiant
 *
 * Created on 10 juin 2014, 13:57:25
 */

#include "ChoiceMakerTests.h"


CPPUNIT_TEST_SUITE_REGISTRATION(ChoiceMakerTests);

ChoiceMakerTests::ChoiceMakerTests() {
}

ChoiceMakerTests::~ChoiceMakerTests() {
}

#include "../../code/run/interval/IntervalManager.h"
#include "../../code/choice/ChoiceMaker.h"
#include "../../code/strategy/BestFit.h"
#include "../../code/relation/Reverse.h"
#include "../../code/core/Problem.h"

#include "../../code/utils.h"
extern bool SILENT;

BestFit* bestFit;
Reverse* rev;
Problem* problem = new Problem("test", 40, INTEGER);

IntervalManager* manager;
ChoiceMaker* choiceMaker;

void ChoiceMakerTests::setUp() {
    SILENT = true;
    bestFit = new BestFit(40, 250);
    rev = new Reverse(*problem, bestFit);
    manager = new IntervalManager(bestFit, rev);
    manager->prepareIntervals(40);
    choiceMaker = new ChoiceMaker(manager);
    choiceMaker->setHook(rev);
    rev->setHook(choiceMaker);
}

void ChoiceMakerTests::tearDown() {
}

void ChoiceMakerTests::test_processPair_one() {
    std::pair<int, int> pair(1, 35);
    CPPUNIT_ASSERT(choiceMaker->processPair(pair));
}

void ChoiceMakerTests::test_processPair_multi() {
    std::pair<int, int> pair(1, 39);
    for (int i = 0; i < 300; i++) {
        manager->memorizeAction(pair, 1);
        choiceMaker->processPair(pair);
        choiceMaker->updateHook(false);
    }
    CPPUNIT_ASSERT(!choiceMaker->processPair(pair));
    std::pair<int, int> pair_small(1, 2);
    CPPUNIT_ASSERT(choiceMaker->processPair(pair_small));
    manager->memorizeAction(pair_small, 10);
    choiceMaker->updateHook(true);
    CPPUNIT_ASSERT(choiceMaker->processPair(pair_small));
}
