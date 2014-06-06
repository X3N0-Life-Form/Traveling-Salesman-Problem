/*
 * File:   RelationTests.h
 * Author: etudiant
 *
 * Created on 2 juin 2014, 17:13:19
 */

#ifndef RELATIONTESTS_H
#define	RELATIONTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class RelationTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(RelationTests);

    CPPUNIT_TEST(test_polymorphism);

    CPPUNIT_TEST_SUITE_END();

public:
    RelationTests();
    virtual ~RelationTests();
    void setUp();
    void tearDown();

private:
    void test_polymorphism();
};

#endif	/* RELATIONTESTS_H */

