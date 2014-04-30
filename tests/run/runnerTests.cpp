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
    runner.clear();
}

void runnerTests::test_start_OK_depth_1() {
    runner.run();
    runner.outputResults();
    for (RunData data : runner.getResults()) {
        CPPUNIT_ASSERT(data.getStartingPoint().getCost()
                > data.getEndPoint().getCost());
    }
}

void runnerTests::test_start_OK_depth_5() {
    runner.setMaxDepth(5);
    runner.run();
    runner.outputResults();
}

void runnerTests::test_start_OK_depth_10() {
    runner.setMaxDepth(10);
    runner.run();
    runner.outputResults();
}

void runnerTests::test_start_OK_depth_100() {
    runner.setMaxDepth(100);
    runner.run();
    runner.outputResults();
}

void runnerTests::test_start_OK_depth_1000() {
    runner.setMaxDepth(1000);
    runner.run();
    runner.outputResults();
}
