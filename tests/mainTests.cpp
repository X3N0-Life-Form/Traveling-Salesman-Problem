/*
 * File:   mainTests.cpp
 * Author: etudiant
 *
 * Created on 5 mai 2014, 15:56:10
 */

#include "mainTests.h"

#include "../code/utils.h"
#include "../code/parse/tspParser.h"
#include "../code/strategy/WorstFit.h"
#include "../code/strategy/BestFit.h"
#include "../code/strategy/FirstFit.h"
#include "../code/relation/Swap.h"
#include "../code/run/Runner.h"
extern bool SILENT;

CPPUNIT_TEST_SUITE_REGISTRATION(mainTests);

extern Problem* main_problem;
extern Runner* main_runner;

mainTests::mainTests() {
}

mainTests::~mainTests() {
}

void mainTests::setUp() {
    SILENT = true;
    main_problem = new Problem(parseProblem(path_a280));
}

void mainTests::tearDown() {
    delete(main_problem);
}

void mainTests::test_createStrategy_OK() {
    Strategy* s = createStrategy(std::string("firstFit"));
    FirstFit* ff = dynamic_cast<FirstFit*> (s);
    CPPUNIT_ASSERT(ff != NULL);
    delete(s);
    s = createStrategy(std::string("bestFit"));
    BestFit* bf = dynamic_cast<BestFit*> (s);
    CPPUNIT_ASSERT(bf != NULL);
    delete(s);
    s = createStrategy(std::string("worstFit"));
    WorstFit* wf = dynamic_cast<WorstFit*> (s);
    CPPUNIT_ASSERT(wf != NULL);
    delete(s);
}

void mainTests::test_createStrategy_KO_bogusType() {
    try {
        createStrategy(std::string("blurg"));
        CPPUNIT_FAIL("an exception should have been thrown");
    } catch (...) {
        // all clear
    }
}

void mainTests::test_createRelation_OK() {
    Strategy* s = createStrategy("firstFit");
    Relation* r = createRelation(std::string("swap"), s);
    Swap* sw = dynamic_cast<Swap*> (r);
    CPPUNIT_ASSERT(sw != NULL);
}

void mainTests::test_createRelation_KO_bogusType() {
    try {
        Strategy* s = createStrategy("firstFit");
        createRelation(std::string("blurg"), s);
        CPPUNIT_FAIL("an exception should have been thrown");
    } catch (...) {
        // all clear
    }
}

void mainTests::test_createRelation_KO_badStrategy() {
    try {
        createRelation(std::string("swap"), NULL);
        CPPUNIT_FAIL("an exception should have been thrown");
    } catch (...) {
        // all clear
    }
}

void mainTests::test_dealWithArgs_standard() {
    // set up
    const int argc = 11;
    char* argv[argc];
    argv[0] = "hohoho";
    argv[1] = "-file"; argv[2] = "data/a280.tsp";
    argv[3] = "-maxDepth"; argv[4] = "404";
    argv[5] = "-rs"; argv[6] = "swap"; argv[7] = "firstFit";
    argv[8] = "-rs"; argv[9] = "swap"; argv[10] = "bestFit";
    //argv[11] = NULL;
    // actual test
    dealWithArgs(argc, argv);
    CPPUNIT_ASSERT(main_runner != NULL);
    CPPUNIT_ASSERT_EQUAL(404, main_runner->getMaxDepth());
    CPPUNIT_ASSERT_EQUAL(std::string("a280"), main_problem->getName());
    CPPUNIT_ASSERT_EQUAL(std::list<Relation*>::size_type(2),
            main_runner->getRelations().size());
    CPPUNIT_ASSERT_EQUAL(std::list<Strategy*>::size_type(2),
            main_runner->getStrategies().size());
}
