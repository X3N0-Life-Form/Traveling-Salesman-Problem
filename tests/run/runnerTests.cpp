/*
 * File:   runnerTests.cpp
 * Author: etudiant
 *
 * Created on 29 avr. 2014, 13:35:11
 */

#include "runnerTests.h"

#include "../../code/run/Runner.h"
#include "../../code/utils.h"
#include "../../code/parse/tspParser.h"
#include "../../code/relation/Swap.h"
#include "../../code/strategy/BestFit.h"
#include "../../code/strategy/FirstFit.h"
#include "../../code/strategy/WorstFit.h"

CPPUNIT_TEST_SUITE_REGISTRATION(runnerTests);

Problem p = parseProblem(path_a280);
FirstFit ff(p.getDimension());
Runner runner(p);

runnerTests::runnerTests() {
}

runnerTests::~runnerTests() {
}

void runnerTests::setUp() {
    runner.addRelation(new Swap(p, ff));
    runner.addStrategy(new FirstFit(p.getDimension()));
    runner.addStrategy(new BestFit(p.getDimension()));
    runner.addStrategy(new WorstFit(p.getDimension()));
}

void runnerTests::tearDown() {
}

void runnerTests::test_start_OK() {
    //runner.run();
    //runner.outputResults();
    CPPUNIT_ASSERT(true);
}

