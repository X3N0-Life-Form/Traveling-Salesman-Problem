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
    std::vector<City> cities;
    int** matrix = new int*[p.getDimension()];
    for (int i = 0; i < p.getDimension(); i++) {
        cities.push_back(City(i, i, 0));
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

#define FASTSETUP(path) int* path = new int[p.getDimension()];\
    for (int i = 1; i <= p.getDimension(); i++) {\
        path[i - 1] = i;\
    }\
    n.setPath(path);\
    n.calculateCost();

void neighborhoodTests::test_calculatePotentialCostSwap() {
    FASTSETUP(path)
    // see above cost calculation
    int nuCost = n.calculatePotentialCostSwap(0,1);
    SWAP(path, 0, 1);
    n.setPath(path);
    CPPUNIT_ASSERT_EQUAL(nuCost, n.calculateCost());
    // new cost calc:
    //  new path = [1, 0, 2, ..., 9]
    //      1==>0 = 1, 0==>2 = 2
    //  1==>9 cost = 10
    //nuts
}

void neighborhoodTests::test_calculatePotentialCostInsert_before() {
    FASTSETUP(path)
    
    int nuCost = n.calculatePotentialCostInsert(0, 5);
    CPPUNIT_ASSERT_EQUAL(24, nuCost);
    int* nuPath = new int[p.getDimension()];
    insert(nuPath, path, p.getDimension(), 0, 5);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}

void neighborhoodTests::test_calculatePotentialCostInsert_after() {
    FASTSETUP(path)
    
    int nuCost = n.calculatePotentialCostInsert(5, 0);
    CPPUNIT_ASSERT_EQUAL(18, nuCost);
    int* nuPath = new int[p.getDimension()];
    insert(nuPath, path, p.getDimension(), 5, 0);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}

void neighborhoodTests::test_calculatePotentialCostInsert_ot() {
    FASTSETUP(path)
    
    int nuCost = n.calculatePotentialCostInsert(4, 5);
    CPPUNIT_ASSERT_EQUAL(18, nuCost);
    int* nuPath = new int[p.getDimension()];
    insert(nuPath, path, p.getDimension(), 4, 5);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}

void neighborhoodTests::test_calculatePotentialCostInsert_to() {
    FASTSETUP(path)
    
    int nuCost = n.calculatePotentialCostInsert(5, 4);
    CPPUNIT_ASSERT_EQUAL(20, nuCost);
    int* nuPath = new int[p.getDimension()];
    insert(nuPath, path, p.getDimension(), 5, 4);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}

void neighborhoodTests::test_calculatePotentialCostInsert_itself() {
    FASTSETUP(path)
    
    int nuCost = n.calculatePotentialCostInsert(5, 5);
    CPPUNIT_ASSERT_EQUAL(18, nuCost);
    int* nuPath = new int[p.getDimension()];
    insert(nuPath, path, p.getDimension(), 5, 5);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}

void neighborhoodTests::test_calculatePotentialCostReverse_std() {
    FASTSETUP(path);
    
    int nuCost = n.calculatePotentialCostReverse(5, 8);
    CPPUNIT_ASSERT_EQUAL(24, nuCost);
    int* nuPath = new int[p.getDimension()];
    reverse(nuPath, path, p.getDimension(), 5, 8);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}

void neighborhoodTests::test_calculatePotentialCostReverse_stdRev() {
    FASTSETUP(path);
    
    int nuCost = n.calculatePotentialCostReverse(8, 5);
    int* nuPath = new int[p.getDimension()];
    reverse(nuPath, path, p.getDimension(), 8, 5);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}

void neighborhoodTests::test_calculatePotentialCostReverse_begMid() {
    FASTSETUP(path);
    
    int nuCost = n.calculatePotentialCostReverse(0, 5);
    int* nuPath = new int[p.getDimension()];
    reverse(nuPath, path, p.getDimension(), 0, 5);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}

void neighborhoodTests::test_calculatePotentialCostReverse_midEnd() {
    FASTSETUP(path);
    
    int nuCost = n.calculatePotentialCostReverse(5, 9);
    int* nuPath = new int[p.getDimension()];
    reverse(nuPath, path, p.getDimension(), 5, 9);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}

void neighborhoodTests::test_calculatePotentialCostReverse_begEnd() {
    FASTSETUP(path);
    
    int nuCost = n.calculatePotentialCostReverse(0, 9);
    int* nuPath = new int[p.getDimension()];
    reverse(nuPath, path, p.getDimension(), 0, 9);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}

void neighborhoodTests::test_calculatePotentialCostReverse_begEndRev() {
    FASTSETUP(path);
    
    int nuCost = n.calculatePotentialCostReverse(9, 0);
    int* nuPath = new int[p.getDimension()];
    reverse(nuPath, path, p.getDimension(), 9, 0);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}

void neighborhoodTests::test_calculatePotentialCostReverse_next() {
    FASTSETUP(path);
    
    int nuCost = n.calculatePotentialCostReverse(5, 6);
    int* nuPath = new int[p.getDimension()];
    reverse(nuPath, path, p.getDimension(), 5, 6);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}

void neighborhoodTests::test_calculatePotentialCostReverse_nextRev() {
    FASTSETUP(path);
    
    int nuCost = n.calculatePotentialCostReverse(6, 5);
    int* nuPath = new int[p.getDimension()];
    reverse(nuPath, path, p.getDimension(), 6, 5);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}

void neighborhoodTests::test_calculatePotentialCostReverse_self() {
    FASTSETUP(path);
    
    int nuCost = n.calculatePotentialCostReverse(5, 5);
    int* nuPath = new int[p.getDimension()];
    reverse(nuPath, path, p.getDimension(), 5, 5);
    n.setPath(nuPath);
    n.calculateCost();
    CPPUNIT_ASSERT_EQUAL(n.getCost(), nuCost);
}
