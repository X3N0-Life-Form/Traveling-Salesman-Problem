/* 
 * File:   StrategicChoiceHook.cpp
 * Author: etudiant
 * 
 * Created on 10 juin 2014, 12:52
 */

#include "RelationChoiceHook.h"

RelationChoiceHook::RelationChoiceHook() {
}

RelationChoiceHook::RelationChoiceHook(const RelationChoiceHook& orig) {
}

RelationChoiceHook::~RelationChoiceHook() {
}

void RelationChoiceHook::setChoiceMaker(Hookable* choiceMaker) {
    this->choiceMaker = choiceMaker;
}

void RelationChoiceHook::setRelation(Hookable* relation) {
    this->relation = relation;
}

bool RelationChoiceHook::isPairWorthConsidering(std::pair<int, int>& pair) {
    return choiceMaker->processPair(pair);
}
