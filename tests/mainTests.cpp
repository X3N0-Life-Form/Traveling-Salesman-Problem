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

CPPUNIT_TEST_SUITE_REGISTRATION(mainTests);

extern Problem* main_problem;

mainTests::mainTests() {
}

mainTests::~mainTests() {
}

void mainTests::setUp() {
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
CPPUNIT_FAIL("TODO");
}

void mainTests::test_dealWithArgs() {
CPPUNIT_FAIL("TODO");
}

void mainTests::test_checkData() {
CPPUNIT_FAIL("TODO");
}
