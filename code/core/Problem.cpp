#include "Problem.h"

#include "../utils.h"
#include <iostream>

Problem::Problem(std::string name, int dimension, DistanceType distanceType) :
    dimension(dimension),
    name(name),
    distanceType(distanceType),
    distanceMatrix() {
}

Problem::Problem(const Problem& orig) :
        name(orig.name),
        comment(orig.comment),
        dimension(orig.dimension),
        distanceType(orig.distanceType) {
    distanceMatrix = new float*[dimension];
    for (int i = 0; i < dimension; i++) {
        distanceMatrix[i] = new float[dimension];
        ARRAY_COPY(distanceMatrix[i], orig.distanceMatrix[i], dimension);
        cities.push_back(orig.cities[i]);
    }
}

int Problem::getDimension() const {
    return dimension;
}

std::string Problem::getName() const {
    return name;
}

float** Problem::getDistanceMatrix() {
    return distanceMatrix;
}

void Problem::setDistanceMatrix(float** d_f) {
    distanceMatrix = d_f;
}


std::vector<City*> Problem::getCities() {
    return cities;
}

void Problem::setCities(std::vector<City*>& cities) {
    this->cities = cities;
}

std::vector<int> Problem::getCityIdsAsVector() {
    std::vector<int> v;
    for (City* city : cities) {
        int id = city->getId();
        v.push_back(id);
    }
    return v;
}

std::list<int> Problem::getCityIdsAsList() {
    std::list<int> l;
    for (City* city : cities) {
        int id = city->getId();
        l.push_back(id);
    }
    return l;
}

/**
 * Retrieves the distance beween two cities.
 * @param id1 City id (NOT AN INDEX, ie. 1..number of cities)
 * @param id2 City id
 * @return Distance between these two cities
 */
int Problem::getDistance(int id1, int id2) {
    return distanceMatrix[id1 - 1][id2 - 1];
}

Problem& Problem::operator =(const Problem& right) {
    Problem* p = new Problem(right);
    return *p;
}

std::ostream& operator<<(std::ostream out, const Problem& problem) {
    out << "Problem " << problem.getName()
            << ": size=" << problem.getDimension();
    return out;
}