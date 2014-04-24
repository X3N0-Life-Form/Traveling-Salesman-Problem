/* 
 * File:   Relation.cpp
 * Author: etudiant
 * 
 * Created on 23 avril 2014, 17:43
 */

#include "Relation.h"

Relation::Relation(Problem& problem) : problem(problem) {
}

Relation::Relation(const Relation& orig) : problem(orig.problem) {
}

Relation::~Relation() {
}

