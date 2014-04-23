#include "problem.h"

Problem::Problem(std::string name, int dimension, DistanceType distanceType) :
    dimension(dimension),
    name(name),
    distanceType(distanceType),
    distanceMatrix() {
    
}

Problem::Problem(const Problem& orig) {//TODO

}

Problem::Problem() {
//TODO
}


int Problem::getDimension() {
    return dimension;
}

std::string Problem::getName() {
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

std::vector<int> Problem::getCityIds() {
    std::vector<int> v;
    for (City* city : cities) {
        int id = city->getId();
        v.push_back(id);
    }
    return v;
}

