/*
 * File:   swapTests.h
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 14:38:57
 */

#ifndef SWAPTESTS_H
#define	SWAPTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class swapTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(swapTests);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    swapTests();
    virtual ~swapTests();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testFailedMethod();
};

#endif	/* SWAPTESTS_H */

