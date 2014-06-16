/*
 * File:   ChoicePickerTests.cpp
 * Author: etudiant
 *
 * Created on 16 juin 2014, 10:47:09
 */

#include "ChoicePickerTests.h"


CPPUNIT_TEST_SUITE_REGISTRATION(ChoicePickerTests);

ChoicePickerTests::ChoicePickerTests() {
}

ChoicePickerTests::~ChoicePickerTests() {
}

#include "../../code/choice/ChoicePicker.h"
#include "code/strategy/BestFit.h"
#include "code/relation/Reverse.h"
#include "../../code/parse/tspParser.h"

#include "../../code/utils.h"
extern bool SILENT;

BestFit* besty;
Reverse* rev;
ChoicePicker* picker;
IntervalManager* manager;
Problem* problem;
std::vector<std::pair<int, int> > pairs;

void ChoicePickerTests::setUp() {
    SILENT = true;
    
    problem = new Problem("prob", 40, INTEGER);
    besty = new BestFit(40, 250);
    rev = new Reverse(*problem, besty);
    manager = new IntervalManager(besty, rev);
    picker = new ChoicePicker(manager);
    manager->prepareIntervals(40);
    for (int i = 1; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            std::pair<int, int> pair(i, j);
            pairs.push_back(pair);
        }
    }
}

void ChoicePickerTests::tearDown() {
}

void ChoicePickerTests::test_selectContainer() {
    Interval* interval = manager->getInterval(3);
    ChoiceContainer* container = new ChoiceContainer(interval);
    picker->getContainers().push_back(container);
    std::pair<int, int> pair(1, 4);
    ChoiceContainer* result = picker->selectContainer(pair);
    CPPUNIT_ASSERT(container != NULL);
    CPPUNIT_ASSERT(container == result);
}


void ChoicePickerTests::test_prepareContainers() {
    picker->prepareContainers(pairs);
    std::vector<ChoiceContainer*> them = picker->getContainers();
    CPPUNIT_ASSERT(them.size() > 0);
    for (ChoiceContainer* it : them) {
        CPPUNIT_ASSERT(it->size() > 0);
        for (int i = 0; i < it->size(); i++)  {
            std::pair<int, int> pair = it->getNextPair();
            CPPUNIT_ASSERT(getPairDistance(pair, 40) < it->getInterval()->getMaxDistance());
            CPPUNIT_ASSERT(getPairDistance(pair, 40) >= it->getInterval()->getMinDistance());
        }
    }
}

