/*
 * File:   ChoiceMakerTests.h
 * Author: etudiant
 *
 * Created on 10 juin 2014, 13:57:25
 */

#ifndef CHOICEMAKERTESTS_H
#define	CHOICEMAKERTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class ChoiceMakerTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ChoiceMakerTests);

    CPPUNIT_TEST(test_processPair_one);
    CPPUNIT_TEST(test_processPair_multi);

    CPPUNIT_TEST_SUITE_END();

public:
    ChoiceMakerTests();
    virtual ~ChoiceMakerTests();
    void setUp();
    void tearDown();

private:
    void test_processPair_one();
    void test_processPair_multi();
};

#endif	/* CHOICEMAKERTESTS_H */

