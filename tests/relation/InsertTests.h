/*
 * File:   InsertTests.h
 * Author: etudiant
 *
 * Created on 14 mai 2014, 16:44:38
 */

#ifndef INSERTTESTS_H
#define	INSERTTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class InsertTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(InsertTests);

    CPPUNIT_TEST(test_applyRelation_firstFit);
    CPPUNIT_TEST(test_applyRelation_bestFit);
    CPPUNIT_TEST(test_applyRelation_worstFit);

    CPPUNIT_TEST_SUITE_END();

public:
    InsertTests();
    virtual ~InsertTests();
    void setUp();
    void tearDown();

private:
    void test_applyRelation_firstFit();
    void test_applyRelation_bestFit();
    void test_applyRelation_worstFit();
};

#endif	/* INSERTTESTS_H */

