/*
 * File:   swapTests.cpp
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 14:38:57
 */

#include "swapTests.h"

#include "../code/relation/Swap.h"
#include "../code/strategy/FirstFit.h"
#include "../code/core/Problem.h"
#include "../code/neighborhood/Neighborhood.h"
#include "tspParserTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(swapTests);

FirstFit f(-1, 280);
Problem p = parseProblem(path_a280);
Neighborhood n(p);
Swap s(p, f);

swapTests::swapTests() {
}

swapTests::~swapTests() {
}

void swapTests::setUp() {
    n.generateRandomNeighborhood();
    n.calculateCost();
    f.setInitialCost(n.getCost());
}

void swapTests::tearDown() {
}

void swapTests::test_applyRelation() {
    Neighborhood result = s.applyRelation(n);
    CPPUNIT_ASSERT(result.getCost() < n.getCost());
}


