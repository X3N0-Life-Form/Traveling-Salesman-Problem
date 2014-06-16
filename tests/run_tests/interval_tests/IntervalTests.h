/*
 * File:   IntervalTests.h
 * Author: etudiant
 *
 * Created on 16 juin 2014, 13:46:40
 */

#ifndef INTERVALTESTS_H
#define	INTERVALTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class IntervalTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(IntervalTests);

    CPPUNIT_TEST(test_includes);

    CPPUNIT_TEST_SUITE_END();

public:
    IntervalTests();
    virtual ~IntervalTests();
    void setUp();
    void tearDown();

private:
    void test_includes();
};

#endif	/* INTERVALTESTS_H */

