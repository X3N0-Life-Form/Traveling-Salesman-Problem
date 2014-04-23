/*
 * File:   tspParserTests.cpp
 * Author: etudiant
 *
 * Created on 22 avr. 2014, 14:41:37
 */

#include "tspParserTests.h"


CPPUNIT_TEST_SUITE_REGISTRATION(tspParserTests);

std::string path_a280 = "data/a280.tsp";
std::string path_att48 = "data/att48.tsp";
std::string path_berlin52 = "data/berlin52.tsp";

tspParserTests::tspParserTests() {
}

tspParserTests::~tspParserTests() {
}

void tspParserTests::setUp() {
}

void tspParserTests::tearDown() {
}

void tspParserTests::test_parseProblem() {
    Problem p = parseProblem(path_a280);
    CPPUNIT_ASSERT_EQUAL(std::string("a280"), p.getName());
    CPPUNIT_ASSERT_EQUAL(280, p.getDimension());
    CPPUNIT_ASSERT(p.getDistanceMatrix() != NULL);
    // test city nodes as well
    CPPUNIT_ASSERT_EQUAL(std::set<City>::size_type(280), p.getCities().size());
    CPPUNIT_ASSERT_EQUAL(1, p.getCities()[0]->getId());
    CPPUNIT_ASSERT_EQUAL(288, p.getCities()[0]->getXI());
    CPPUNIT_ASSERT_EQUAL(149, p.getCities()[0]->getYI());
    CPPUNIT_ASSERT_EQUAL(280, p.getCities()[279]->getId());
    /*float** distances = p.getDistanceMatrix();
    for (int i = 0; i < p.getDimension(); i++) {
        for (int j = 0; j < p.getDimension(); j++) {
            std::cout << distances[i][j] << ", ";
        }
        std::cout << "\n";
    }*/
}

