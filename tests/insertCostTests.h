/*
 * File:   insertCostTests.h
 * Author: etudiant
 *
 * Created on 23 mai 2014, 10:36:51
 */

#ifndef INSERTCOSTTESTS_H
#define	INSERTCOSTTESTS_H

#include <cppunit/extensions/HelperMacros.h>

class insertCostTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(insertCostTests);

    CPPUNIT_TEST(test_negativeCost);

    CPPUNIT_TEST_SUITE_END();

public:
    insertCostTests();
    virtual ~insertCostTests();
    void setUp();
    void tearDown();

private:
    void test_negativeCost();
};

#endif	/* INSERTCOSTTESTS_H */

