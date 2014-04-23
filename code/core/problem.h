/* 
 * File:   problem.h
 * Author: etudiant
 *
 * Created on 22 avril 2014, 13:53
 */

#ifndef PROBLEM_H
#define	PROBLEM_H

#include <string>
#include <vector>
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
    std::vector<City*> cities;
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
    std::vector<City*> getCities();
    void setCities(std::vector<City*>& cities);
};

#endif	/* PROBLEM_H */

