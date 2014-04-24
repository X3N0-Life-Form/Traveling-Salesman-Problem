/*
 * File:   problemTests.cpp
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 10:20:18
 */

#include "problemTests.h"

#include "../code/core/Problem.h"
#include "tspParserTests.h"

CPPUNIT_TEST_SUITE_REGISTRATION(problemTests);

Problem p;

problemTests::problemTests() {
}

problemTests::~problemTests() {
}

void problemTests::setUp() {
    p = parseProblem(path_a280);
}

void problemTests::tearDown() {
}

void problemTests::test_getDistance() {
    //Note: what's in the matrix
    CPPUNIT_ASSERT_EQUAL(20, p.getDistance(1, 2));
}

void problemTests::testFailedMethod() {
    //CPPUNIT_ASSERT(false);
}

