/*
 * File:   bestFitTests.h
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 17:20:03
 */

#ifndef BESTFITTESTS_H
#define	BESTFITTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class bestFitTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(bestFitTests);

    CPPUNIT_TEST(test_applyStrategy_OK);
    CPPUNIT_TEST(test_applyStrategy_KO_worseCost);
    CPPUNIT_TEST(test_applyStrategy_KO_betterCost);

    CPPUNIT_TEST_SUITE_END();

public:
    bestFitTests();
    virtual ~bestFitTests();
    void setUp();
    void tearDown();

private:
    void test_applyStrategy_OK();
    void test_applyStrategy_KO_worseCost();
    void test_applyStrategy_KO_betterCost();
};

#endif	/* BESTFITTESTS_H */

