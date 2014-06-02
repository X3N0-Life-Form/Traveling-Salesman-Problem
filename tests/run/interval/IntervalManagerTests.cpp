/*
 * File:   IntervalManagerTests.cpp
 * Author: etudiant
 *
 * Created on 2 juin 2014, 10:01:58
 */

#include "IntervalManagerTests.h"

#include "../../../code/run/interval/IntervalManager.h"
#include "../../../code/run/interval/Interval.h"
#include "../../../code/run/interval/Action.h"
#include "../../../code/utils.h"

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

void IntervalManagerTests::test_memorizeAction() {
    std::pair<int, int> pair = std::make_pair(1, 30);
    int distance = pair.second - pair.first;
    manager->prepareIntervals(40);
    manager->memorizeAction(pair, 50);
    std::list<Interval*> intervals = manager->getIntervals();
    
    bool fail = true;
    for (Interval* interval : intervals) {
        std::vector<Action*> actions = interval->getActions();
        PRINTLN(actions.size());
        if (actions.size() > 0) {
            fail = false;
            Action* action = actions.front();
            CPPUNIT_ASSERT_EQUAL(50, action->getCostDiff());
            CPPUNIT_ASSERT_EQUAL(pair.first, action->getPair().first);
            CPPUNIT_ASSERT_EQUAL(pair.second, action->getPair().second);
            CPPUNIT_ASSERT(distance >= interval->getMinDistance());
            CPPUNIT_ASSERT(distance <  interval->getMaxDistance());
        }
    }
    if (fail) {
        CPPUNIT_ASSERT(false);
    }
}
