/*
 * File:   InsertTests.cpp
 * Author: etudiant
 *
 * Created on 14 mai 2014, 16:44:38
 */

#include "InsertTests.h"

#include "../../code/relation/Insert.h"
#include "../../code/utils.h"
#include "../../code/parse/tspParser.h"

#include "../../code/strategy/FirstFit.h"
#include "../../code/strategy/BestFit.h"
#include "../../code/strategy/WorstFit.h"
#include "../../code/core/Neighborhood.h"

CPPUNIT_TEST_SUITE_REGISTRATION(InsertTests);

InsertTests::InsertTests() {
}

InsertTests::~InsertTests() {
}

Problem problem(parseProblem(path_a280));

FirstFit* ff;
BestFit* bf;
WorstFit* wf;

Insert* i_ff;
Insert* i_bf;
Insert* i_wf;

Neighborhood* n;

void InsertTests::setUp() {
    n = new Neighborhood(problem);
    n->generateRandomNeighborhood();
    n->calculateCost();
    
    ff = new FirstFit(problem.getDimension(), n->getCost());
    bf = new BestFit(problem.getDimension(), n->getCost());
    wf = new WorstFit(problem.getDimension(), n->getCost());
    
    i_ff = new Insert(problem, *ff);
    i_bf = new Insert(problem, *bf);
    i_wf = new Insert(problem, *wf);
}

void InsertTests::tearDown() {
    delete(n);
    delete(i_ff);
    delete(i_bf);
    delete(i_wf);
}

void InsertTests::test_applyRelation_firstFit() {
    int originalCost = n->getCost();
    Neighborhood* result = i_ff->applyRelation(*n);
    int resultCost = result->getCost();
    CPPUNIT_ASSERT(resultCost < originalCost);
    CPPUNIT_ASSERT(*n != *result);
}

void InsertTests::test_applyRelation_bestFit() {
    int originalCost = n->getCost();
    Neighborhood* result = i_bf->applyRelation(*n);
    int resultCost = result->getCost();
    CPPUNIT_ASSERT(resultCost < originalCost);
    CPPUNIT_ASSERT(*n != *result);
    Neighborhood* r2 = i_bf->applyRelation(*n);
    int r2Cost = r2->getCost();
    CPPUNIT_ASSERT_EQUAL(resultCost, r2Cost);
}

void InsertTests::test_applyRelation_worstFit() {
    int originalCost = n->getCost();
    Neighborhood* result = i_wf->applyRelation(*n);
    int resultCost = result->getCost();
    CPPUNIT_ASSERT(resultCost < originalCost);
    CPPUNIT_ASSERT(*n != *result);
    Neighborhood* r2 = i_wf->applyRelation(*n);
    int r2Cost = r2->getCost();
    CPPUNIT_ASSERT_EQUAL(resultCost, r2Cost);
}
