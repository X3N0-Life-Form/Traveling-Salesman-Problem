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
    CPPUNIT_TEST(test_calculatePotentialCostInsert_before);
    CPPUNIT_TEST(test_calculatePotentialCostInsert_after);
    CPPUNIT_TEST(test_calculatePotentialCostInsert_ot);
    CPPUNIT_TEST(test_calculatePotentialCostInsert_to);
    CPPUNIT_TEST(test_calculatePotentialCostInsert_itself);
    CPPUNIT_TEST(test_calculatePotentialCostReverse_std);
    CPPUNIT_TEST(test_calculatePotentialCostReverse_stdRev);
    CPPUNIT_TEST(test_calculatePotentialCostReverse_begMid);
    CPPUNIT_TEST(test_calculatePotentialCostReverse_midEnd);
    CPPUNIT_TEST(test_calculatePotentialCostReverse_begEnd);
    CPPUNIT_TEST(test_calculatePotentialCostReverse_begEndRev);
    CPPUNIT_TEST(test_calculatePotentialCostReverse_next);
    CPPUNIT_TEST(test_calculatePotentialCostReverse_nextRev);
    CPPUNIT_TEST(test_calculatePotentialCostReverse_self);

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
    void test_calculatePotentialCostInsert_before();
    void test_calculatePotentialCostInsert_after();
    void test_calculatePotentialCostInsert_ot();
    void test_calculatePotentialCostInsert_to();
    void test_calculatePotentialCostInsert_itself();
    void test_calculatePotentialCostReverse_std();
    void test_calculatePotentialCostReverse_stdRev();
    void test_calculatePotentialCostReverse_begMid();
    void test_calculatePotentialCostReverse_midEnd();
    void test_calculatePotentialCostReverse_begEnd();
    void test_calculatePotentialCostReverse_begEndRev();
    void test_calculatePotentialCostReverse_next();
    void test_calculatePotentialCostReverse_nextRev();
    void test_calculatePotentialCostReverse_self();
};

#endif	/* NEIGHBORHOODTESTS_H */

