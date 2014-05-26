/* 
 * File:   Neighborhood.h
 * Author: etudiant
 *
 * Created on 23 avril 2014, 15:22
 */

#ifndef NEIGHBORHOOD_H
#define	NEIGHBORHOOD_H

#include <vector>
#include <iostream>

#include "Problem.h"

class Neighborhood {
private:
    Problem& problem;
    int dimension;
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
    int calculatePotentialCostSwap(int index1, int index2) const;
    int calculatePotentialCostInsert(int origin, int target) const;
    int calculatePotentialCostReverse(int left, int right) const;
    // Getters / Setters
    int* getPath() const;
    void setPath(int* path);
    int getCost() const;
    void setCost(int cost);
    int getDimension() const;
    Problem& getProblem() const;
    void setProblem(Problem& problem);
    
};

std::ostream& operator<<(std::ostream& out, Neighborhood& n);
bool operator==(const Neighborhood& left, const Neighborhood& right);
bool operator!=(const Neighborhood& left, const Neighborhood& right);

#endif	/* NEIGHBORHOOD_H */

