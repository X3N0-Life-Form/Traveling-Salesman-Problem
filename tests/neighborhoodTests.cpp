/*
 * File:   neighborhoodTests.cpp
 * Author: etudiant
 *
 * Created on 23 avr. 2014, 15:46:46
 */

#include "neighborhoodTests.h"


CPPUNIT_TEST_SUITE_REGISTRATION(neighborhoodTests);

neighborhoodTests::neighborhoodTests() {
}

neighborhoodTests::~neighborhoodTests() {
}

void neighborhoodTests::setUp() {
}

void neighborhoodTests::tearDown() {
}

void neighborhoodTests::testMethod() {
    Problem p = parseProblem(path_a280);
    Neighborhood n(p);
    n.generateRandomNeighborhood();
    int* path = n.getPath();
    std::vector<int> check(p.getDimension());
    for (int i = 0; i < p.getDimension(); i++) {
        int value = path[i];
        auto res = find(check.begin(), check.end(), value);
        CPPUNIT_ASSERT(res == check.end());
        check.push_back(value);
    }
}

void neighborhoodTests::testFailedMethod() {
    //CPPUNIT_ASSERT(false);
}

