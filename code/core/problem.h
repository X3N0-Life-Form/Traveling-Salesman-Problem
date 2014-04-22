/* 
 * File:   problem.h
 * Author: etudiant
 *
 * Created on 22 avril 2014, 13:53
 */

#ifndef PROBLEM_H
#define	PROBLEM_H

#include <string>
#include <set>
#include "city.h"

enum DistanceType {
    INTEGER,
    FLOAT
};

class Problem {
private:
    std::string name;
    std::string comment;
    int dimension;
    std::set<City> cities;
    int** distances_i;
    float** distances_f;
    DistanceType distanceType;
    
public:
    // Constructors //
    Problem(std::string name, int dimension, DistanceType distanceType);
    // Getters / Setters //
    int getDimension();
    std::string getName();
    int** getDistances_i();
    void setDistances_i(int** d_i);
    float** getDistances_f();
    void setDistances_f(float** d_f);
};

#endif	/* PROBLEM_H */

