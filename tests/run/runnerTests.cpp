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
extern bool SILENT;

CPPUNIT_TEST_SUITE_REGISTRATION(runnerTests);

Problem p = parseProblem(path_a280);
FirstFit ff(p.getDimension());
Runner r(p);

runnerTests::runnerTests() {
}

runnerTests::~runnerTests() {
}

void runnerTests::setUp() {
    SILENT = true;
    r.addRelation(new Swap(p, &ff));
    r.addStrategy(new FirstFit(p.getDimension()));
    r.addStrategy(new BestFit(p.getDimension()));
    r.addStrategy(new WorstFit(p.getDimension()));
    r.setPrintIntervalData(false);
}

void runnerTests::tearDown() {
    r.clear();
}

void runnerTests::test_start_OK_depth_1() {
    r.run();
    r.outputResults();
    for (RunData* data : r.getResults()) {
        int startingCost = data->getStartingPoint()->cost;
        int endCost = data->getEndPoint()->cost;
        CPPUNIT_ASSERT(startingCost > endCost);
    }
}

void runnerTests::test_start_OK_depth_5() {
    r.setMaxDepth(5);
    r.run();
    r.outputResults();
}

void runnerTests::test_start_OK_depth_10() {
    r.setMaxDepth(10);
    r.run();
    r.outputResults();
}

void runnerTests::test_start_OK_depth_100() {
    r.setMaxDepth(100);
    r.run();
    r.outputResults();
}

void runnerTests::test_start_OK_depth_1000() {
    r.setMaxDepth(1000);
    r.run();
    r.outputResults();
}
