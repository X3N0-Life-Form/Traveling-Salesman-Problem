/*
 * File:   neighborhoodTests.cpp
 * Author: etudiant
 *
 * Created on 23 avr. 2014, 15:46:46
 */

#include "neighborhoodTests.h"


CPPUNIT_TEST_SUITE_REGISTRATION(neighborhoodTests);

neighborhoodTests::neighborhoodTests()
    : p(parseProblem(path_a280)), n(p) {
}

neighborhoodTests::~neighborhoodTests() {
}

void neighborhoodTests::setUp() {
}

void neighborhoodTests::tearDown() {
}

void neighborhoodTests::test_generateRandomNeighborhood() {
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

void neighborhoodTests::test_calculateCost() {
    int* path = new int[p.getDimension()];
    for (int i = 1; i <= p.getDimension(); i++) {
        path[i - 1] = i;
    }
    n.setPath(path);
    CPPUNIT_ASSERT_EQUAL(2786, n.calculateCost());
}

void neighborhoodTests::test_calculatePotentialCost() {
    int* path = new int[p.getDimension()];
    for (int i = 1; i <= p.getDimension(); i++) {
        path[i - 1] = i;
    }
    n.setPath(path);
    // see above cost
    CPPUNIT_ASSERT(n.calculatePotentialCost(0,1) != 2786);
}

