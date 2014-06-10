/*
 * File:   ChoiceMakerTests.cpp
 * Author: etudiant
 *
 * Created on 10 juin 2014, 13:57:25
 */

#include "ChoiceMakerTests.h"


CPPUNIT_TEST_SUITE_REGISTRATION(ChoiceMakerTests);

ChoiceMakerTests::ChoiceMakerTests() {
}

ChoiceMakerTests::~ChoiceMakerTests() {
}

#include "../../code/run/interval/IntervalManager.h"
#include "../../code/choice/ChoiceMaker.h"

IntervalManager* manager;
RelationChoiceHook* choiceHook;
ChoiceMaker* choiceMaker;

void ChoiceMakerTests::setUp() {
}

void ChoiceMakerTests::tearDown() {
}

void ChoiceMakerTests::test_isPairWorthConsidering() {
    CPPUNIT_ASSERT(true);
}

