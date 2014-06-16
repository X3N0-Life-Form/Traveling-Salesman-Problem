/*
 * File:   IntervalTests.cpp
 * Author: etudiant
 *
 * Created on 16 juin 2014, 13:46:40
 */

#include "IntervalTests.h"
#include "code/run/interval/Interval.h"


CPPUNIT_TEST_SUITE_REGISTRATION(IntervalTests);

IntervalTests::IntervalTests() {
}

IntervalTests::~IntervalTests() {
}
Interval* interval;

void IntervalTests::setUp() {
    interval = new Interval(1, 5);
    interval->setDimension(40);
}

void IntervalTests::tearDown() {
    delete(interval);
}

void IntervalTests::test_includes() {
    CPPUNIT_ASSERT(interval->includes(std::pair<int, int>(1,3)));
    CPPUNIT_ASSERT(!interval->includes(std::pair<int, int>(1,15)));
}

