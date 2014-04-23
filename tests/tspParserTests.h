/*
 * File:   tspParserTests.h
 * Author: etudiant
 *
 * Created on 22 avr. 2014, 14:41:37
 */

#ifndef TSPPARSERTESTS_H
#define	TSPPARSERTESTS_H

#include <cppunit/extensions/HelperMacros.h>
#include <string>
#include "../code/core/Problem.h"
#include "../code/parse/tspParser.h"

std::string path_a280 = "data/a280.tsp";
std::string path_att48 = "data/att48.tsp";
std::string path_berlin52 = "data/berlin52.tsp";

class tspParserTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(tspParserTests);

    CPPUNIT_TEST(test_parseProblem_int);
    CPPUNIT_TEST(test_parseProblem_float);

    CPPUNIT_TEST_SUITE_END();

public:
    tspParserTests();
    virtual ~tspParserTests();
    void setUp();
    void tearDown();

private:
    void test_parseProblem_int();
    void test_parseProblem_float();
};

#endif	/* TSPPARSERTESTS_H */

