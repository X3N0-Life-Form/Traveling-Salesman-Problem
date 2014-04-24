/*
 * File:   firstFitTests.cpp
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 15:02:19
 */

#include "firstFitTests.h"

#include "../code/strategy/FirstFit.h"

FirstFit f(50, 280);

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
    CPPUNIT_ASSERT(f.applyStrategy(NULL, 40));
}

void firstFitTests::test_applyStrategy_KO() {
    CPPUNIT_ASSERT(!f.applyStrategy(NULL, 60));
}
