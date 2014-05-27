/*
 * File:   ReverseTests.h
 * Author: etudiant
 *
 * Created on 27 mai 2014, 10:43:25
 */

#ifndef REVERSETESTS_H
#define	REVERSETESTS_H

#include <cppunit/extensions/HelperMacros.h>

class ReverseTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ReverseTests);

    CPPUNIT_TEST(test_applyRelation_firstFit);
    CPPUNIT_TEST(test_applyRelation_bestFit);
    CPPUNIT_TEST(test_applyRelation_worstFit);

    CPPUNIT_TEST_SUITE_END();

public:
    ReverseTests();
    virtual ~ReverseTests();
    void setUp();
    void tearDown();

private:
    void test_applyRelation_firstFit();
    void test_applyRelation_bestFit();
    void test_applyRelation_worstFit();
};

#endif	/* REVERSETESTS_H */

