/*
 * File:   utilsTests.h
 * Author: etudiant
 *
 * Created on 14 mai 2014, 17:01:22
 */

#ifndef UTILSTESTS_H
#define	UTILSTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class utilsTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(utilsTests);

    CPPUNIT_TEST(test_insert_ot);
    CPPUNIT_TEST(test_insert_to);
    CPPUNIT_TEST(test_insert_before);
    CPPUNIT_TEST(test_insert_after);
    CPPUNIT_TEST(test_insert_same);

    CPPUNIT_TEST_SUITE_END();

public:
    utilsTests();
    virtual ~utilsTests();
    void setUp();
    void tearDown();

private:
    void test_insert_ot();
    void test_insert_to();
    void test_insert_before();
    void test_insert_after();
    void test_insert_same();
};

#endif	/* UTILSTESTS_H */

