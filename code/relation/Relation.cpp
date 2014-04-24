/* 
 * File:   Relation.cpp
 * Author: etudiant
 * 
 * Created on 23 avril 2014, 17:43
 */

#include "Relation.h"

Relation::Relation(Problem& problem, Strategy& strategy) :
    problem(problem), strategy(strategy) {
}

Relation::Relation(const Relation& orig) :
    problem(orig.problem), strategy(orig.strategy) {
}

Relation::~Relation() {
}

