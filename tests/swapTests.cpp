/*
 * File:   swapTests.cpp
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 14:38:57
 */

#include "swapTests.h"

#include "../code/relation/Swap.h"
#include "../code/strategy/FirstFit.h"
#include "../code/strategy/BestFit.h"
#include "../code/core/Problem.h"
#include "../code/neighborhood/Neighborhood.h"
#include "tspParserTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(swapTests);

FirstFit ff(-1, 280);
BestFit bf(-1, 280);

Problem p = parseProblem(path_a280);
Neighborhood n(p);

Swap swap_ff(p, ff);
Swap swap_bf(p, bf);

swapTests::swapTests() {
}

swapTests::~swapTests() {
}

void swapTests::setUp() {
    n.generateRandomNeighborhood();
    n.calculateCost();
    ff.setInitialCost(n.getCost());
    BestFit bf(n.getCost(), 280);
}

void swapTests::tearDown() {
}

void swapTests::test_applyRelation_firstFit() {
    Neighborhood& result = swap_ff.applyRelation(n);
    //std::cout <<result.getCost() << "###"<<n.getCost();
    CPPUNIT_ASSERT(result.getCost() < n.getCost());
}

void swapTests::test_applyRelation_bestFit() {
    Neighborhood& result = swap_bf.applyRelation(n);
    CPPUNIT_ASSERT(result.getCost() < n.getCost());
    //Neighborhood r2 = swap_bf.applyRelation(n);
    //CPPUNIT_ASSERT_EQUAL(result.getCost(), r2.getCost());
}
