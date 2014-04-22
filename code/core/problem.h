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
    int distances_i[1][1];
    float distances_f[1][1];
    DistanceType distanceType;
    
public:
    Problem(std::string name, int dimension, DistanceType distanceType);
};

#endif	/* PROBLEM_H */

