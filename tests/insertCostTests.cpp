/*
 * File:   insertCostTests.cpp
 * Author: etudiant
 *
 * Created on 23 mai 2014, 10:36:52
 */

#include "insertCostTests.h"

#include "../code/utils.h"
#include "../code/parse/tspParser.h"
#include "../code/strategy/strategies.h"
#include "../code/relation/Insert.h"
#include "../code/run/Runner.h"

CPPUNIT_TEST_SUITE_REGISTRATION(insertCostTests);

Problem* problem;
Neighborhood* startingPoint;

Insert* r_insert;
FirstFit* ff;
BestFit* bf;
WorstFit* wf;

Runner* runner;
std::list<RunData*> results;

insertCostTests::insertCostTests() {
}

insertCostTests::~insertCostTests() {
}

void insertCostTests::setUp() {
    problem = new Problem(parseProblem(path_burma14));
    startingPoint = new Neighborhood(*problem);
    startingPoint->generateRandomNeighborhood();
    startingPoint->calculateCost();
    
    ff = new FirstFit(problem->getDimension(), startingPoint->getCost());
    bf = new BestFit(problem->getDimension(), startingPoint->getCost());
    wf = new WorstFit(problem->getDimension(), startingPoint->getCost());
    r_insert = new Insert(*problem, *ff);
    
    runner = new Runner(*problem, 200);
    runner->addRelation(r_insert);
    runner->addStrategy(ff);
    runner->addStrategy(bf);
    runner->addStrategy(wf);
}

void insertCostTests::tearDown() {
    delete(runner);
}
/**
 * Launch that thing lots of time
 */
void insertCostTests::test_negativeCost() {
    runner->run();
    results = runner->getResults();
    for (RunData* data : results) {
        /*if (data->getEndPoint()->cost <= 0) {
            ARRAY_PRINT(data->getEndPoint()->path, problem->getDimension());
        }*/
        CPPUNIT_ASSERT(data->getEndPoint()->cost > 0);
    }
}

