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
#include <list>
#include "City.h"

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
    float** distanceMatrix;
    DistanceType distanceType;
    
public:
    // Constructors
    Problem(std::string name, int dimension, DistanceType distanceType);
    Problem(const Problem& orig);
    // Getters / Setters
    int getDimension();
    std::string getName();
    float** getDistanceMatrix();
    void setDistanceMatrix(float** d_f);
    std::vector<City*> getCities();
    void setCities(std::vector<City*>& cities);
    Problem& operator=(const Problem& right);
    // Advanced Getters
    std::vector<int> getCityIdsAsVector();
    std::list<int> getCityIdsAsList();
    int getDistance(int id1, int id2);
};

#endif	/* PROBLEM_H */

