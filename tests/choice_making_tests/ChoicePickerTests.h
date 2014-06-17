/*
 * File:   ChoicePickerTests.h
 * Author: etudiant
 *
 * Created on 16 juin 2014, 10:47:08
 */

#ifndef CHOICEPICKERTESTS_H
#define	CHOICEPICKERTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class ChoicePickerTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ChoicePickerTests);

    CPPUNIT_TEST(test_selectContainer);
    CPPUNIT_TEST(test_prepareContainers);
    CPPUNIT_TEST(test_getPair);

    CPPUNIT_TEST_SUITE_END();

public:
    ChoicePickerTests();
    virtual ~ChoicePickerTests();
    void setUp();
    void tearDown();

private:
    void test_selectContainer();
    void test_prepareContainers();
    void test_getPair();
};

#endif	/* CHOICEPICKERTESTS_H */

