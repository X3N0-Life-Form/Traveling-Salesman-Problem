/*
 * File:   swapTests.cpp
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 14:38:57
 */

#include "swapTests.h"

#include "../../code/relation/Swap.h"
#include "../../code/strategy/FirstFit.h"
#include "../../code/strategy/BestFit.h"
#include "../../code/strategy/WorstFit.h"
#include "../../code/core/Problem.h"
#include "../../code/core/Neighborhood.h"
#include "../../code/utils.h"
#include "../../code/parse/tspParser.h"
extern bool SILENT;

CPPUNIT_TEST_SUITE_REGISTRATION(swapTests);

Problem p = parseProblem(path_a280);

FirstFit* ff;
BestFit* bf;
WorstFit* wf;

Neighborhood* n;

Swap* swap_ff;
Swap* swap_bf;
Swap* swap_wf;

swapTests::swapTests() {
}

swapTests::~swapTests() {
}

void swapTests::setUp() {
    SILENT = true;
    //Problem p = parseProblem(path_a280);
    n = new Neighborhood(p);
    n->generateRandomNeighborhood();
    n->calculateCost();
    
    ff = new FirstFit(p.getDimension(), n->getCost());
    bf = new BestFit(p.getDimension(), n->getCost());
    wf = new WorstFit(p.getDimension(), n->getCost());
    
    swap_ff = new Swap(p, ff);
    swap_bf = new Swap(p, bf);
    swap_wf = new Swap(p, wf);
}

void swapTests::tearDown() {
    delete(n);
    delete(swap_ff);
    delete(swap_bf);
    delete(swap_wf);
    //delete(ff);
    //delete(bf);
    //delete(wf);
}

void swapTests::test_applyRelation_firstFit() {
    Neighborhood* result = swap_ff->applyRelation(*n);
    //std::cout <<"\n"<<result.getCost() << " < "<<n.getCost()<<"\n";
    int result_cost, original_cost;
    result_cost = result->getCost();
    original_cost = n->getCost();
    //CPPUNIT_ASSERT(result.getCost() < n.getCost());
    CPPUNIT_ASSERT(result_cost < original_cost);
    CPPUNIT_ASSERT(*n != *result);
}

void swapTests::test_applyRelation_bestFit() {
    Neighborhood* result = swap_bf->applyRelation(*n);
    int result_cost, original_cost, r2_cost;
    result_cost = result->getCost();
    original_cost = n->getCost();
    CPPUNIT_ASSERT(result_cost < original_cost);
    Neighborhood* r2 = swap_bf->applyRelation(*n);
    r2_cost = r2->getCost();
    CPPUNIT_ASSERT_EQUAL(result_cost, r2_cost);
    CPPUNIT_ASSERT(*n != *result);
}

// copy pasted again
void swapTests::test_applyRelation_worstFit() {
    Neighborhood* result = swap_wf->applyRelation(*n);
    int result_cost, original_cost, r2_cost;
    result_cost = result->getCost();
    original_cost = n->getCost();
    CPPUNIT_ASSERT(result_cost < original_cost);
    Neighborhood* r2 = swap_wf->applyRelation(*n);
    r2_cost = r2->getCost();
    CPPUNIT_ASSERT_EQUAL(result_cost, r2_cost);
    CPPUNIT_ASSERT(*n != *result);
}