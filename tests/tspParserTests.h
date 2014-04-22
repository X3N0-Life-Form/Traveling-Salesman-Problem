/*
 * File:   tspParserTests.h
 * Author: etudiant
 *
 * Created on 22 avr. 2014, 14:41:37
 */

#ifndef TSPPARSERTESTS_H
#define	TSPPARSERTESTS_H

#include <cppunit/extensions/HelperMacros.h>
#include <string>

class tspParserTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(tspParserTests);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    tspParserTests();
    virtual ~tspParserTests();
    void setUp();
    void tearDown();

private:
    void test_parseProblem();
};

#endif	/* TSPPARSERTESTS_H */

