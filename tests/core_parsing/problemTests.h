/*
 * File:   problemTests.h
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 10:20:18
 */

#ifndef PROBLEMTESTS_H
#define	PROBLEMTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class problemTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(problemTests);

    CPPUNIT_TEST(test_getDistance);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    problemTests();
    virtual ~problemTests();
    void setUp();
    void tearDown();

private:
    void test_getDistance();
    void testFailedMethod();
};

#endif	/* PROBLEMTESTS_H */

