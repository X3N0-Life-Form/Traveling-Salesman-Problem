/*
 * File:   IntervalManagerTests.cpp
 * Author: etudiant
 *
 * Created on 2 juin 2014, 10:01:58
 */

#include "IntervalManagerTests.h"

#include "../../../code/run/interval/IntervalManager.h"
#include "../../../code/run/interval/Interval.h"

CPPUNIT_TEST_SUITE_REGISTRATION(IntervalManagerTests);

IntervalManagerTests::IntervalManagerTests() {
}

IntervalManagerTests::~IntervalManagerTests() {
}

IntervalManager* manager;

void IntervalManagerTests::setUp() {
    manager = new IntervalManager(NULL, NULL);
}

void IntervalManagerTests::tearDown() {
    delete(manager);
}

void IntervalManagerTests::test_prepareIntervals() {
    manager->prepareIntervals(40);
    std::list<Interval*> intervals = manager->getIntervals();
    int prev = 1;
    for (Interval* interval : intervals) {
        CPPUNIT_ASSERT(interval->getMinDistance() < interval->getMaxDistance());
        CPPUNIT_ASSERT_EQUAL(prev, interval->getMinDistance());
        prev = interval->getMaxDistance();
    }
}

