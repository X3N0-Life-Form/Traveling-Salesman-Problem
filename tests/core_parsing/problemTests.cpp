/*
 * File:   problemTests.cpp
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 10:20:18
 */

#include "problemTests.h"

#include "../../code/core/Problem.h"
#include "tspParserTests.h"
#include <list>

CPPUNIT_TEST_SUITE_REGISTRATION(problemTests);

Problem* p;

problemTests::problemTests() {
}

problemTests::~problemTests() {
}

void problemTests::setUp() {
    Problem temp = parseProblem(path_a280);
    p = new Problem(temp);
}

void problemTests::tearDown() {
    delete(p);
}

void problemTests::test_getDistance() {
    //Note: what's in the matrix
    CPPUNIT_ASSERT_EQUAL(20, p->getDistance(1, 2));
}

void problemTests::test_getCitiesAsList() {
    std::list<int> cityIds = p->getCityIdsAsList();
    Problem* copy = new Problem(*p);
    for (int i = 0; i < p->getDimension(); i++) {
        CPPUNIT_ASSERT_EQUAL(i + 1, cityIds.front());
        cityIds.pop_front();
    }
    cityIds = copy->getCityIdsAsList();
    for (int i = 0; i < p->getDimension(); i++) {
        CPPUNIT_ASSERT_EQUAL(i + 1, cityIds.front());
        cityIds.pop_front();
    }
    delete(copy);
}

