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
    CPPUNIT_TEST(test_insert_endTarget);
    CPPUNIT_TEST(test_insert_endOrigin);
    CPPUNIT_TEST(test_reverse_std);
    CPPUNIT_TEST(test_reverse_stdRev);
    CPPUNIT_TEST(test_reverse_begMid);
    CPPUNIT_TEST(test_reverse_midEnd);
    CPPUNIT_TEST(test_reverse_begEnd);
    CPPUNIT_TEST(test_reverse_next);
    CPPUNIT_TEST(test_reverse_nextRev);
    CPPUNIT_TEST(test_reverse_self);
    CPPUNIT_TEST(test_getPairDistance_regular);
    CPPUNIT_TEST(test_getPairDistance_roundTrip);
    
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
    void test_insert_endTarget();
    void test_insert_endOrigin();
    
    void test_reverse_std();
    void test_reverse_stdRev();
    void test_reverse_begMid();
    void test_reverse_midEnd();
    void test_reverse_begEnd();
    void test_reverse_next();
    void test_reverse_nextRev();
    void test_reverse_self();
    
    void test_getPairDistance_regular();
    void test_getPairDistance_roundTrip();
};

#endif	/* UTILSTESTS_H */

