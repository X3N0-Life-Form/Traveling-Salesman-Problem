/*
 * File:   IntervalManagerTests.h
 * Author: etudiant
 *
 * Created on 2 juin 2014, 10:01:57
 */

#ifndef INTERVALMANAGERTESTS_H
#define	INTERVALMANAGERTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class IntervalManagerTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(IntervalManagerTests);

    CPPUNIT_TEST(test_prepareIntervals_default);
    CPPUNIT_TEST(test_prepareIntervals_jao);
    CPPUNIT_TEST(test_memorizeAction);
    CPPUNIT_TEST(test_getInterval_OK);
    CPPUNIT_TEST(test_getInterval_KO_sup);
    CPPUNIT_TEST(test_getInterval_KO_inf);
    
    CPPUNIT_TEST_SUITE_END();

public:
    IntervalManagerTests();
    virtual ~IntervalManagerTests();
    void setUp();
    void tearDown();

private:
    void test_prepareIntervals_default();
    void test_prepareIntervals_jao();
    void test_memorizeAction();
    void test_getInterval_OK();
    void test_getInterval_KO_sup();
    void test_getInterval_KO_inf();
};

#endif	/* INTERVALMANAGERTESTS_H */

