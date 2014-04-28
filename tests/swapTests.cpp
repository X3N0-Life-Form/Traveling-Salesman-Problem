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
#include "../code/core/Neighborhood.h"
#include "tspParserTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(swapTests);

FirstFit ff(50000, 280);
BestFit bf(50000, 280);

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
    //std::cout <<"\n"<<result.getCost() << " < "<<n.getCost()<<"\n";
    int result_cost, original_cost;
    result_cost = result.getCost();
    original_cost = n.getCost();
    //CPPUNIT_ASSERT(result.getCost() < n.getCost());
    CPPUNIT_ASSERT(result_cost < original_cost);
}

void swapTests::test_applyRelation_bestFit() {
    Neighborhood& result = swap_bf.applyRelation(n);
    int result_cost, original_cost, r2_cost;
    result_cost = result.getCost();
    original_cost = n.getCost();
    CPPUNIT_ASSERT(result_cost < original_cost);
    Neighborhood& r2 = swap_bf.applyRelation(n);
    r2_cost = r2.getCost();
    CPPUNIT_ASSERT_EQUAL(result_cost, r2_cost);
}
