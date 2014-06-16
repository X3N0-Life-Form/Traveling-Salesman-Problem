/*
 * File:   ChoiceContainerTests.cpp
 * Author: etudiant
 *
 * Created on 16 juin 2014, 10:03:34
 */

#include "ChoiceContainerTests.h"


CPPUNIT_TEST_SUITE_REGISTRATION(ChoiceContainerTests);

ChoiceContainerTests::ChoiceContainerTests() {
}

ChoiceContainerTests::~ChoiceContainerTests() {
}

#include "../../code/choice/ChoiceContainer.h"

Interval* interval;
ChoiceContainer* container;

void ChoiceContainerTests::setUp() {
    interval = new Interval(1, 18);
    container = new ChoiceContainer(interval);
}

void ChoiceContainerTests::tearDown() {
    delete(container);
    delete(interval);
}

void ChoiceContainerTests::test_getNextPair() {
    std::pair<int, int> pair1(1, 2), pair2(3, 4), pair3(1,7);
    container->addPair(pair1);
    container->addPair(pair2);
    container->addPair(pair3);
    CPPUNIT_ASSERT(pair1 == container->getNextPair());
    CPPUNIT_ASSERT(pair2 == container->getNextPair());
    CPPUNIT_ASSERT(pair3 == container->getNextPair());
    CPPUNIT_ASSERT(pair1 == container->getNextPair());
}
