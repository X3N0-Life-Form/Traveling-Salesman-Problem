#include "Problem.h"

#include "../utils.h"
#include <iostream>

Problem::Problem(std::string name, int dimension, DistanceType distanceType) :
    dimension(dimension),
    name(name),
    distanceType(distanceType),
    distanceMatrix_f(),
    distanceMatrix_i() {
}

Problem::Problem(const Problem& orig) :
        name(orig.name),
        comment(orig.comment),
        dimension(orig.dimension),
        distanceType(orig.distanceType)
{
    if (distanceType == FLOAT) {
        distanceMatrix_f = new float*[dimension];
        for (int i = 0; i < dimension; i++) {
            distanceMatrix_f[i] = new float[dimension];
            ARRAY_COPY(distanceMatrix_f[i], orig.distanceMatrix_f[i], dimension);
            cities.push_back(orig.cities[i]);
        }
        distanceMatrix_i = NULL;
    } else {
        distanceMatrix_i = new int*[dimension];
        for (int i = 0; i < dimension; i++) {
            distanceMatrix_i[i] = new int[dimension];
            ARRAY_COPY(distanceMatrix_i[i], orig.distanceMatrix_i[i], dimension);
            cities.push_back(orig.cities[i]);
        }
        distanceMatrix_f = NULL;
    }
}

Problem::~Problem() {
    if (distanceType == INTEGER) {
        /*for (int i = 0; i < dimension; i++) {
            delete[](distanceMatrix_i[i]);
        }*/
        delete[](distanceMatrix_i);
    }
    if (distanceType == FLOAT) {
        /*for (int f = 0; f < dimension; f++) {
            delete[](distanceMatrix_f[f]);
        }*/
        delete[](distanceMatrix_f);
    }
}

int Problem::getDimension() const {
    return dimension;
}

std::string Problem::getName() const {
    return name;
}

DistanceType Problem::getDistanceType() const {
    return distanceType;
}

float** Problem::getDistanceMatrix_f() const {
    return distanceMatrix_f;
}

void Problem::setDistanceMatrix(float** d_f) {
    distanceMatrix_f = d_f;
}

int** Problem::getDistanceMatrix_i() const {
    return distanceMatrix_i;
}

void Problem::setDistanceMatrix(int** d_i) {
    distanceMatrix_i = d_i;
}

std::vector<City> Problem::getCities() const {
    return cities;
}

void Problem::setCities(std::vector<City>& cities) {
    this->cities = cities;
}

std::vector<int> Problem::getCityIdsAsVector() {
    std::vector<int> v;
    for (City city : cities) {
        int id = city.getId();
        v.push_back(id);
    }
    return v;
}

std::list<int> Problem::getCityIdsAsList() {
    std::list<int> l;
    for (City city : cities) {
        int id = city.getId();
        l.push_back(id);
    }
    return l;
}

std::vector<std::pair<int, int> >* Problem::getCityPairs(PairingMode mode) {
    std::vector<std::pair<int, int> >* pairs = 
        new std::vector<std::pair<int, int> >(dimension * dimension);
    int c = 0;
    switch (mode) {
        case PM_SWAP:
            for (int i = 0; i < dimension; i++) {
                for (int j = i + 1; j < dimension; j++) {
                    if (i == j)
                        continue;
                    std::pair<int, int> p(i, j);
                    pairs->at(c) = p;
                    c++;
                }
            }
            break;
        case PM_INSERT:
            for (int i = 0; i < dimension; i++) {
                for (int j = 1; j < dimension; j++) {
                    // if target = origin + 1
                    if (j == i + 1 || i == j)
                        continue;
                    std::pair<int, int> p(i, j);
                    pairs->at(c) = p;
                    c++;
                }
            }
            break;
    }
    pairs->shrink_to_fit();
    return pairs;
}

/**
 * Retrieves the distance beween two cities.
 * @param id1 City id (NOT AN INDEX, ie. 1..number of cities)
 * @param id2 City id
 * @return Distance between these two cities
 */
int Problem::getDistance(int id1, int id2) {
    if (distanceType == FLOAT)
        return distanceMatrix_f[id1 - 1][id2 - 1];
    else
        return distanceMatrix_i[id1 - 1][id2 - 1];
}

Problem& Problem::operator =(const Problem& right) {
    this->name = right.name;
    this->comment = right.comment;
    this->dimension = right.dimension;
    this->distanceType = right.distanceType;
    this->cities = right.cities;
    this->distanceMatrix_i = right.distanceMatrix_i;
    this->distanceMatrix_f = right.distanceMatrix_f;
    
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Problem& problem) {
    out << "Problem " << problem.getName()
            << ": size=" << problem.getDimension();
    return out;
}

bool operator==(const Problem& left, const Problem& right) {
    if (left.getName() != right.getName())
        return false;
    else if (left.getDimension() != right.getDimension())
        return false;
    // compare cities
    /*for (int i = 0; i < left.getCities().size(); i++) {
        if (left.getCities()[i] != right.getCities()[i])//TODO: fix this
            return false;
    }*/
    // compare the matrix
    for (int i = 0; i < left.getDimension(); i++) {
        for (int j = 0; j < left.getDimension(); j++) {
            if (left.getDistanceType() == FLOAT) {
                if (left.getDistanceMatrix_f()[i][j]
                        != right.getDistanceMatrix_f()[i][j])
                return false;
            } else {
                if (left.getDistanceMatrix_i()[i][j]
                        != right.getDistanceMatrix_i()[i][j])
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const Problem& left, const Problem& right) {
    return !(left == right);
}
