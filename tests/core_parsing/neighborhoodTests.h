/*
 * File:   neighborhoodTests.h
 * Author: etudiant
 *
 * Created on 23 avr. 2014, 15:46:46
 */

#ifndef NEIGHBORHOODTESTS_H
#define	NEIGHBORHOODTESTS_H

#include <cppunit/extensions/HelperMacros.h>

#include "../../code/core/Neighborhood.h"

class neighborhoodTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(neighborhoodTests);

    CPPUNIT_TEST(test_generateRandomNeighborhood);
    CPPUNIT_TEST(test_calculateCost);
    CPPUNIT_TEST(test_calculatePotentialCostSwap);
    CPPUNIT_TEST(test_calculatePotentialCostInsert);

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
    void test_calculateCost();
    void test_calculatePotentialCostSwap();
    void test_calculatePotentialCostInsert();
};

#endif	/* NEIGHBORHOODTESTS_H */

