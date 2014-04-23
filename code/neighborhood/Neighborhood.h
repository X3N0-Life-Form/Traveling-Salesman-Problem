/* 
 * File:   Neighborhood.h
 * Author: etudiant
 *
 * Created on 23 avril 2014, 15:22
 */

#ifndef NEIGHBORHOOD_H
#define	NEIGHBORHOOD_H

#include <vector>
#include <random>
#include <iostream>

#include "../core/Problem.h"

class Neighborhood {
public:
    Neighborhood();
    Neighborhood(Problem& problem);
    Neighborhood(const Neighborhood& orig);
    virtual ~Neighborhood();
private:
    Problem& problem;
    int* path;
public:
    void generateRandomNeighborhood();
    Neighborhood& applyRelation(Relation r);
    int* getPath();
};

#endif	/* NEIGHBORHOOD_H */

