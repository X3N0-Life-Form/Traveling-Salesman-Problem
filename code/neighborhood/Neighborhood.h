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
    Neighborhood(Problem& problem);
    Neighborhood(const Neighborhood& orig);
    virtual ~Neighborhood();
private:
    Problem& problem;
    int* path;
    int cost;
public:
    void generateRandomNeighborhood();
    int calculateCost();
    int calculatePotentialCost(int index1, int index2);
    // Getters / Setters
    int* getPath();
    void setPath(int* path);
    int getCost();
    void setCost(int cost);
    int getDimension();
};

std::ostream& operator<<(std::ostream& out, Neighborhood& n);

#endif	/* NEIGHBORHOOD_H */

