/*
 * File:   neighborhoodTests.cpp
 * Author: etudiant
 *
 * Created on 23 avr. 2014, 15:46:46
 */

#include "neighborhoodTests.h"

#include "../../code/utils.h"
#include <algorithm>
#include <iterator>
#include <set>
#include "../../code/parse/tspParser.h"

CPPUNIT_TEST_SUITE_REGISTRATION(neighborhoodTests);

neighborhoodTests::neighborhoodTests()
    : p(std::string("test"), 10, INTEGER), n(p) {
}

neighborhoodTests::~neighborhoodTests() {
}

void neighborhoodTests::setUp() {
    std::vector<City*> cities;
    int** matrix = new int*[p.getDimension()];
    for (int i = 0; i < p.getDimension(); i++) {
        cities.push_back(new City(i, i, 0));
        matrix[i] = new int[p.getDimension()];
    }
    
    calculateDistances(cities, matrix);
    
    p.setCities(cities);
    p.setDistanceMatrix(matrix);
}

void neighborhoodTests::tearDown() {
}

void neighborhoodTests::test_generateRandomNeighborhood() {
    n.generateRandomNeighborhood();
    int* path = n.getPath();
    std::set<int> check;
    // for each city in our path
    for (int i = 0; i < p.getDimension(); i++) {// review that test
        int value = path[i];
        // see if we've already seen it
        //CPPUNIT_ASSERT(check.find(value) == std::set<int>::end);
        // add this city to the list of seen cities
        check.insert(value);
    }
}

void neighborhoodTests::test_calculateCost() {
    int* path = new int[p.getDimension()];
    for (int i = 1; i <= p.getDimension(); i++) {
        path[i - 1] = i;
    }
    // Note: path = [0, 1, 2, ..., 9]
    //  0==>9 = 9==>0 = 9
    //  cost should be 0==>9==>0 = 18
    n.setPath(path);
    CPPUNIT_ASSERT_EQUAL(18, n.calculateCost());
}

void neighborhoodTests::test_calculatePotentialCost() {
    int* path = new int[p.getDimension()];
    for (int i = 1; i <= p.getDimension(); i++) {
        path[i - 1] = i;
    }
    n.setPath(path);
    n.calculateCost();
    // see above cost calculation
    int nuCost = n.calculatePotentialCost(0,1);
    SWAP(path, 0, 1);
    n.setPath(path);
    CPPUNIT_ASSERT_EQUAL(nuCost, n.calculateCost());
    // new cost calc:
    //  new path = [1, 0, 2, ..., 9]
    //      1==>0 = 1, 0==>2 = 2
    //  1==>9 cost = 10
    //nuts
}

