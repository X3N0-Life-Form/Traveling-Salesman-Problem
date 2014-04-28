/*
 * File:   WorstFitTests.cpp
 * Author: etudiant
 *
 * Created on 28 avr. 2014, 15:13:02
 */

#include "WorstFitTests.h"

#include "../code/strategy/WorstFit.h"

WorstFit wf(200, 1);
int* path;

CPPUNIT_TEST_SUITE_REGISTRATION(WorstFitTests);

WorstFitTests::WorstFitTests() {
}

WorstFitTests::~WorstFitTests() {
}

void WorstFitTests::setUp() {
    wf = WorstFit(200, 10);
    path = new int[10];
}

void WorstFitTests::tearDown() {
    delete[](path);
}
// Note: copy-pasting again

void WorstFitTests::test_applyStrategy_OK() {
    wf.applyStrategy(path, 190);
    CPPUNIT_ASSERT(wf.getFitCost() == 190);
}

void WorstFitTests::test_applyStrategy_KO_worseCost() {
    wf.applyStrategy(path, 290);
    CPPUNIT_ASSERT(wf.getFitCost() == 200);
}

// here is the actually interesting test
void WorstFitTests::test_applyStrategy_KO_betterCost() {
    wf = WorstFit(200, 10);
    CPPUNIT_ASSERT(!wf.applyStrategy(path, 190));
    CPPUNIT_ASSERT(wf.getFitCost() == 190);
    CPPUNIT_ASSERT(!wf.applyStrategy(path, 195));
    CPPUNIT_ASSERT(wf.getFitCost() == 195);
    CPPUNIT_ASSERT(!wf.applyStrategy(path, 185));
    CPPUNIT_ASSERT(wf.getFitCost() == 195);
    //note: cost assignment is tied to path assignment, no need to test that
}

