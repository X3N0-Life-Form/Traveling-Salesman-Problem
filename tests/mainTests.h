/*
 * File:   mainTests.h
 * Author: etudiant
 *
 * Created on 5 mai 2014, 15:56:10
 */

#ifndef MAINTESTS_H
#define	MAINTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class mainTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(mainTests);

    CPPUNIT_TEST(test_createStrategy_OK);
    CPPUNIT_TEST(test_createStrategy_KO_bogusType);
    CPPUNIT_TEST(test_createRelation_OK);
    CPPUNIT_TEST(test_createRelation_KO_bogusType);
    CPPUNIT_TEST(test_createRelation_KO_badStrategy);
    CPPUNIT_TEST(test_dealWithArgs_standard);

    CPPUNIT_TEST_SUITE_END();

public:
    mainTests();
    virtual ~mainTests();
    void setUp();
    void tearDown();

private:
    void test_createStrategy_OK();
    void test_createStrategy_KO_bogusType();
    void test_createRelation_OK();
    void test_createRelation_KO_bogusType();
    void test_createRelation_KO_badStrategy();
    void test_dealWithArgs_standard();
};

#endif	/* MAINTESTS_H */

