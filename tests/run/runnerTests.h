/*
 * File:   runnerTests.h
 * Author: etudiant
 *
 * Created on 29 avr. 2014, 13:35:11
 */

#ifndef RUNNERTESTS_H
#define	RUNNERTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class runnerTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(runnerTests);

    CPPUNIT_TEST(test_start_OK_depth_1);
    CPPUNIT_TEST(test_start_OK_depth_5);
    CPPUNIT_TEST(test_start_OK_depth_10);
    CPPUNIT_TEST(test_start_OK_depth_100);
    CPPUNIT_TEST(test_start_OK_depth_1000);

    CPPUNIT_TEST_SUITE_END();

public:
    runnerTests();
    virtual ~runnerTests();
    void setUp();
    void tearDown();

private:
    void test_start_OK_depth_1();
    void test_start_OK_depth_5();
    void test_start_OK_depth_10();
    void test_start_OK_depth_100();
    void test_start_OK_depth_1000();
};

#endif	/* RUNNERTESTS_H */

