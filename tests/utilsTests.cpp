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
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_insert_endTarget() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int origin = 5;
    int target = 9;
    int expected[10] = {0, 1, 2, 3, 4, 6, 7, 8, 5, 9};
    int produced[10];
    insert(produced, original, 10, origin, target);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_insert_endOrigin() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int origin = 9;
    int target = 5;
    int expected[10] = {0, 1, 2, 3, 4, 9, 5, 6, 7, 8};
    int produced[10];
    insert(produced, original, 10, origin, target);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_reverse_std() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int left = 5;
    int right = 8;
    int expected[10] = {0, 1, 2, 3, 4, 8, 7, 6, 5, 9};
    int produced[10];
    reverse(produced, original, 10, left, right);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_reverse_stdRev() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int left = 8;
    int right = 5;
    int expected[10] = {3, 2, 1, 0, 9, 8, 6, 7, 5, 4};
    int produced[10];
    reverse(produced, original, 10, left, right);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_reverse_begMid() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int left = 0;
    int right = 5;
    int expected[10] = {5, 4, 3, 2, 1, 0, 6, 7, 8, 9};
    int produced[10];
    reverse(produced, original, 10, left, right);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_reverse_midEnd() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int left = 5;
    int right = 9;
    int expected[10] = {0, 1, 2, 3, 4, 9, 8, 7, 6, 5};
    int produced[10];
    reverse(produced, original, 10, left, right);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_reverse_begEnd() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int left = 0;
    int right = 9;
    int expected[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int produced[10];
    reverse(produced, original, 10, left, right);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_reverse_next() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int left = 5;
    int right = 6;
    int expected[10] = {0, 1, 2, 3, 4, 6, 5, 7, 8, 9};
    int produced[10];
    reverse(produced, original, 10, left, right);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_reverse_nextRev() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int left = 6;
    int right = 5;
    int expected[10] = {1, 0, 9, 8, 7, 6, 5, 4, 3, 2};
    int produced[10];
    reverse(produced, original, 10, left, right);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}

void utilsTests::test_reverse_self() {
    int original[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int left = 5;
    int right = 5;
    int expected[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int produced[10];
    reverse(produced, original, 10, left, right);
    for (int i = 0; i < 10; i++) {
        CPPUNIT_ASSERT_EQUAL(expected[i], produced[i]);
    }
}
