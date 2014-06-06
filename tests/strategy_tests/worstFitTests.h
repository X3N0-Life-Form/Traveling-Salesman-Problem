/*
 * File:   WorstFitTests.h
 * Author: etudiant
 *
 * Created on 28 avr. 2014, 15:13:02
 */

#ifndef WORSTFITTESTS_H
#define	WORSTFITTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class WorstFitTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(WorstFitTests);

    CPPUNIT_TEST(test_applyStrategy_OK);
    CPPUNIT_TEST(test_applyStrategy_KO_worseCost);
    CPPUNIT_TEST(test_applyStrategy_KO_betterCost);

    CPPUNIT_TEST_SUITE_END();

public:
    WorstFitTests();
    virtual ~WorstFitTests();
    void setUp();
    void tearDown();

private:
    void test_applyStrategy_OK();
    void test_applyStrategy_KO_worseCost();
    void test_applyStrategy_KO_betterCost();
};

#endif	/* WORSTFITTESTS_H */

