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

#include "Problem.h"

class Neighborhood {
private:
    Problem& problem;
    int* path;
    int cost;
public:
    Neighborhood(Problem& problem);
    Neighborhood(const Neighborhood& orig);
    virtual ~Neighborhood();
    Neighborhood& operator=(const Neighborhood& right);
    // other methods
    void generateRandomNeighborhood();
    int calculateCost();
    int calculatePotentialCost(int index1, int index2) const;
    // Getters / Setters
    int* getPath() const;
    void setPath(int* path);
    int getCost() const;
    void setCost(int cost);
    int getDimension();
    Problem& getProblem();
    
};

std::ostream& operator<<(std::ostream& out, Neighborhood& n);

#endif	/* NEIGHBORHOOD_H */

