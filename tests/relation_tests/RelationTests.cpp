/*
 * File:   RelationTests.cpp
 * Author: etudiant
 *
 * Created on 2 juin 2014, 17:13:19
 */

#include "RelationTests.h"

#include "../../code/utils.h"
#include "../../code/relation/Relation.h"
#include "../../code/relation/Reverse.h"
#include "../../code/strategy/strategies.h"
#include "../../code/core/Problem.h"

CPPUNIT_TEST_SUITE_REGISTRATION(RelationTests);

RelationTests::RelationTests() {
}

RelationTests::~RelationTests() {
}

Relation* r;
FirstFit* ff;
BestFit* bf;

void RelationTests::setUp() {
    Problem problem("nameless", 10, INTEGER);
    ff = new FirstFit(problem.getDimension(), 200);
    bf = new BestFit(problem.getDimension(), 200);
    r = new Reverse(problem, ff);
}

void RelationTests::tearDown() {
}

void RelationTests::test_polymorphism() {
    CPPUNIT_ASSERT_EQUAL(ff->getType(), r->getStrategy()->getType());
    r->setStrategy(bf);
    CPPUNIT_ASSERT_EQUAL(bf->getType(), r->getStrategy()->getType());
}

