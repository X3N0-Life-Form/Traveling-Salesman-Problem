#include "tspParser.h"

using namespace std;

Problem parseProblem(string filePath) {
    string name("");
    int dimension = 1;
    DistanceType type = INTEGER;
    
    Problem p(name, dimension, type);
    return p;
}