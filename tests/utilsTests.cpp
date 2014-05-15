/*
 * File:   utilsTests.cpp
 * Author: etudiant
 *
 * Created on 14 mai 2014, 17:01:22
 */

#include "utilsTests.h"

#include "../code/utils.h"

CPPUNIT_TEST_SUITE_REGISTRATION(utilsTests);

utilsTests::utilsTests() {
}

utilsTests::~utilsTests() {
}

void utilsTests::setUp() {
}

void utilsTests::tearDown() {
}

void utilsTests::test_insert_ot() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int origin = 0;
    int target = 5;
    int expected[10] = {1, 2, 3, 4, 0, 5, 6, 7, 8, 9};
    int produced[10];
    insert(produced, original, 10, origin, target);
    ARRAY_PRINT(produced, 10);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_insert_to() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int origin = 5;
    int target = 0;
    int expected[10] = {5, 0, 1, 2, 3, 4, 6, 7, 8, 9};
    int produced[10];
    insert(produced, original, 10, origin, target);
    ARRAY_PRINT(produced, 10);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_insert_before() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int origin = 5;
    int target = 4;
    int expected[10] = {0, 1, 2, 3, 5, 4, 6, 7, 8, 9};
    int produced[10];
    insert(produced, original, 10, origin, target);
    ARRAY_PRINT(produced, 10);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_insert_after() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int origin = 4;
    int target = 5;
    int expected[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int produced[10];
    insert(produced, original, 10, origin, target);
    ARRAY_PRINT(produced, 10);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_insert_same() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int origin = 5;
    int target = 5;
    int expected[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int produced[10];
    insert(produced, original, 10, origin, target);
    ARRAY_PRINT(produced, 10);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}
