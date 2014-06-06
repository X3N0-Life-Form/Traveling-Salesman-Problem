/*
 * File:   firstFitTests.h
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 15:02:19
 */

#ifndef FIRSTFITTESTS_H
#define	FIRSTFITTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class firstFitTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(firstFitTests);

    CPPUNIT_TEST(test_applyStrategy_OK);
    CPPUNIT_TEST(test_applyStrategy_KO);

    CPPUNIT_TEST_SUITE_END();

public:
    firstFitTests();
    virtual ~firstFitTests();
    void setUp();
    void tearDown();

private:
    void test_applyStrategy_OK();
    void test_applyStrategy_KO();
};

#endif	/* FIRSTFITTESTS_H */

