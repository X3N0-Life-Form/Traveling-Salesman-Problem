/*
 * File:   neighborhoodTests.h
 * Author: etudiant
 *
 * Created on 23 avr. 2014, 15:46:46
 */

#ifndef NEIGHBORHOODTESTS_H
#define	NEIGHBORHOODTESTS_H

#include <cppunit/extensions/HelperMacros.h>

#include "tspParserTests.h"
#include "../code/neighborhood/Neighborhood.h"
#include <algorithm>
#include <iterator>

class neighborhoodTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(neighborhoodTests);

    CPPUNIT_TEST(test_generateRandomNeighborhood);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    neighborhoodTests();
    virtual ~neighborhoodTests();
    void setUp();
    void tearDown();

private:
    Problem p;
    Neighborhood n;

    
    void test_generateRandomNeighborhood();
    void testFailedMethod();
};

#endif	/* NEIGHBORHOODTESTS_H */

