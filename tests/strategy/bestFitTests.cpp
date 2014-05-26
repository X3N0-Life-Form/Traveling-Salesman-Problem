/*
 * File:   bestFitTests.cpp
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 17:20:03
 */

#include "bestFitTests.h"

#include "../../code/strategy/BestFit.h"

BestFit* bf;
int* path;

CPPUNIT_TEST_SUITE_REGISTRATION(bestFitTests);

bestFitTests::bestFitTests() {
}

bestFitTests::~bestFitTests() {
}

void bestFitTests::setUp() {
    bf = new BestFit(10, 200);
    path = new int[10];
}

void bestFitTests::tearDown() {
    delete[](path);
    delete(bf);
}

void bestFitTests::test_applyStrategy_OK() {
    bf->applyStrategy(path, 190);
    CPPUNIT_ASSERT_EQUAL(190, bf->getFitCost());
}

void bestFitTests::test_applyStrategy_KO_worseCost() {
    bf->applyStrategy(path, 290);
    CPPUNIT_ASSERT_EQUAL(200, bf->getFitCost());
}

void bestFitTests::test_applyStrategy_KO_betterCost() {
    CPPUNIT_ASSERT(!bf->applyStrategy(path, 190));
    CPPUNIT_ASSERT(bf->getFitCost() == 190);
    CPPUNIT_ASSERT(!bf->applyStrategy(path, 195));
    CPPUNIT_ASSERT(bf->getFitCost() == 190);
    CPPUNIT_ASSERT(!bf->applyStrategy(path, 185));
    CPPUNIT_ASSERT(bf->getFitCost() == 185);
    //note: cost assignment is tied to path assignment, no need to test that
}
