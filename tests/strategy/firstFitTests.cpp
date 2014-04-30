/*
 * File:   firstFitTests.cpp
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 15:02:19
 */

#include "firstFitTests.h"

#include "../../code/strategy/FirstFit.h"

FirstFit ff(280, 50);

CPPUNIT_TEST_SUITE_REGISTRATION(firstFitTests);

firstFitTests::firstFitTests() {
}

firstFitTests::~firstFitTests() {
}

void firstFitTests::setUp() {
}

void firstFitTests::tearDown() {
}

void firstFitTests::test_applyStrategy_OK() {
    CPPUNIT_ASSERT(ff.applyStrategy(NULL, 40));
}

void firstFitTests::test_applyStrategy_KO() {
    CPPUNIT_ASSERT(!ff.applyStrategy(NULL, 60));
}
