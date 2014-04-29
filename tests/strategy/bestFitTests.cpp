/*
 * File:   bestFitTests.cpp
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 17:20:03
 */

#include "bestFitTests.h"

#include "../../code/strategy/BestFit.h"

BestFit bf(200, 1);
int* path;

CPPUNIT_TEST_SUITE_REGISTRATION(bestFitTests);

bestFitTests::bestFitTests() {
}

bestFitTests::~bestFitTests() {
}

void bestFitTests::setUp() {
    bf = BestFit(200, 10);
    path = new int[10];
}

void bestFitTests::tearDown() {
    delete[](path);
}

void bestFitTests::test_applyStrategy_OK() {
    bf.applyStrategy(path, 190);
    CPPUNIT_ASSERT(bf.getFitCost() == 190);
}

void bestFitTests::test_applyStrategy_KO_worseCost() {
    bf.applyStrategy(path, 290);
    CPPUNIT_ASSERT(bf.getFitCost() == 200);
}

void bestFitTests::test_applyStrategy_KO_betterCost() {
    bf = BestFit(200, 10);
    CPPUNIT_ASSERT(!bf.applyStrategy(path, 190));
    CPPUNIT_ASSERT(bf.getFitCost() == 190);
    CPPUNIT_ASSERT(!bf.applyStrategy(path, 195));
    CPPUNIT_ASSERT(bf.getFitCost() == 190);
    CPPUNIT_ASSERT(!bf.applyStrategy(path, 185));
    CPPUNIT_ASSERT(bf.getFitCost() == 185);
    //note: cost assignment is tied to path assignment, no need to test that
}
