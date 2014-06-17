/*
 * File:   ChoiceContainerTests.h
 * Author: etudiant
 *
 * Created on 16 juin 2014, 10:10:39
 */

#ifndef CHOICECONTAINERTESTS_H
#define	CHOICECONTAINERTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class ChoiceContainerTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ChoiceContainerTests);

    CPPUNIT_TEST(test_getNextPair_OK);
    CPPUNIT_TEST(test_getNextPair_KO);

    CPPUNIT_TEST_SUITE_END();

public:
    ChoiceContainerTests();
    virtual ~ChoiceContainerTests();
    void setUp();
    void tearDown();

private:
    void test_getNextPair_OK();
    void test_getNextPair_KO();
};

#endif	/* CHOICECONTAINERTESTS_H */

