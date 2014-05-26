/*
 * File:   firstFitTests.cpp
 * Author: etudiant
 *
 * Created on 24 avr. 2014, 15:02:19
 */

#include "firstFitTests.h"

#include "../../code/strategy/FirstFit.h"

FirstFit* ff;
int* path;

CPPUNIT_TEST_SUITE_REGISTRATION(firstFitTests);

firstFitTests::firstFitTests() {
}

firstFitTests::~firstFitTests() {
}

void firstFitTests::setUp() {
    ff = new FirstFit(280, 50);
    path = new int[10];
}

void firstFitTests::tearDown() {
    delete(ff);
    delete(path);
}

void firstFitTests::test_applyStrategy_OK() {
    CPPUNIT_ASSERT(ff->applyStrategy(path, 40));
}

void firstFitTests::test_applyStrategy_KO() {
    CPPUNIT_ASSERT(!ff->applyStrategy(path, 60));
}
