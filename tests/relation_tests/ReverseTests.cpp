/*
 * File:   ReverseTests.cpp
 * Author: etudiant
 *
 * Created on 27 mai 2014, 10:43:25
 */

#include "ReverseTests.h"

#include "../../code/relation/Reverse.h"
#include "../../code/utils.h"
#include "../../code/parse/tspParser.h"
#include "../../code/core/Neighborhood.h"

#include "../../code/strategy/strategies.h"

extern bool SILENT;

Problem problem(parseProblem(path_a280));

FirstFit* ff;
BestFit* bf;
WorstFit* wf;

Reverse* r_ff;
Reverse* r_bf;
Reverse* r_wf;

Neighborhood* n;

CPPUNIT_TEST_SUITE_REGISTRATION(ReverseTests);

ReverseTests::ReverseTests() {
}

ReverseTests::~ReverseTests() {
}

void ReverseTests::setUp() {
    SILENT = true;
    n = new Neighborhood(problem);
    n->generateRandomNeighborhood();
    n->calculateCost();
    
    ff = new FirstFit(problem.getDimension(), n->getCost());
    bf = new BestFit(problem.getDimension(), n->getCost());
    wf = new WorstFit(problem.getDimension(), n->getCost());
    
    r_ff = new Reverse(problem, ff);
    r_bf = new Reverse(problem, bf);
    r_wf = new Reverse(problem, wf);
}

void ReverseTests::tearDown() {
    delete(n);
    delete(r_ff);
    delete(r_bf);
    delete(r_wf);
}

void ReverseTests::test_applyRelation_firstFit() {
    int originalCost = n->getCost();
    Neighborhood* result = r_ff->applyRelation(*n);
    int resultCost = result->getCost();
    CPPUNIT_ASSERT(resultCost < originalCost);
    CPPUNIT_ASSERT(*n != *result);
}

void ReverseTests::test_applyRelation_bestFit() {
    int originalCost = n->getCost();
    Neighborhood* result = r_bf->applyRelation(*n);
    int resultCost = result->getCost();
    CPPUNIT_ASSERT(resultCost < originalCost);
    CPPUNIT_ASSERT(*n != *result);
    bf->setInitialCost(originalCost);
    Neighborhood* r2 = r_bf->applyRelation(*n);
    int r2Cost = r2->getCost();
    CPPUNIT_ASSERT(r2Cost < originalCost);
    CPPUNIT_ASSERT_EQUAL(resultCost, r2Cost);
}

void ReverseTests::test_applyRelation_worstFit() {
    int originalCost = n->getCost();
    Neighborhood* result = r_wf->applyRelation(*n);
    int resultCost = result->getCost();
    CPPUNIT_ASSERT(resultCost < originalCost);
    CPPUNIT_ASSERT(*n != *result);
    wf->setInitialCost(originalCost);
    Neighborhood* r2 = r_wf->applyRelation(*n);
    int r2Cost = r2->getCost();
    CPPUNIT_ASSERT(r2Cost < originalCost);
    CPPUNIT_ASSERT_EQUAL(resultCost, r2Cost);
}
