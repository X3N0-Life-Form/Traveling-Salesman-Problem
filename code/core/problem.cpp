#include "problem.h"

Problem::Problem(std::string name, int dimension, DistanceType distanceType) :
    dimension(dimension),
    name(name),
    distanceType(distanceType),
    distances_i(),
    distances_f() {
    switch (distanceType) {
        case INTEGER:
            //distances_i = new int[dimension][dimension];
            distances_f = NULL;
            break;
        case FLOAT:
            distances_i = NULL;
            //distances_f = new float[dimension][dimension];
            break;
    }
}

int Problem::getDimension() {
    return dimension;
}

std::string Problem::getName() {
    return name;
}

float** Problem::getDistances_f() {
    return distances_f;
}

void Problem::setDistances_f(float** d_f) {
    distances_f = d_f;
}


int** Problem::getDistances_i() {
    return distances_i;
}

void Problem::setDistances_i(int** d_i) {
    distances_i = d_i;
}

