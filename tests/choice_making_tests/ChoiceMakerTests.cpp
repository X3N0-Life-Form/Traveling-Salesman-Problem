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

void ChoiceMakerTests::test_isPairWorthConsidering() {
    std::pair<int, int> pair(1, 35);
    CPPUNIT_ASSERT(choiceMaker->processPair(pair));
}

