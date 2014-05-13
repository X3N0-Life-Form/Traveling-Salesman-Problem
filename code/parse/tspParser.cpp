#include "tspParser.h"

using namespace std;
#include "../utils.h"
/**
 * Move along, nothing to see here.
 * @param dim
 * @return Something that wouldn't be needed if those damn regex worked
 */
int doom(int dim) {
    int dom = 1;
    int dem = 1;
    while (dim / dom > 1) {
        dom *= 10;
        dem++;
    }
    return dem;
}

Problem parseProblem(string filePath) {
    string name("");
    int dimension = 1;
    DistanceType type = INTEGER;
    ParsingMode parsingMode = DISCOVER;
    
    float** distanceMatrix_f;
    int** distanceMatrix_i;
    vector<City> cities;
    //[ \t]*[0-9]+[ \t]+[0-9]+(\\.[0-9]+)?[ \t]+[0-9]+(\\.[0-9]+)?[ \t]*
    regex rex("[ \t]*[0-9]+[ \t]+[0-9]+(\\.[0-9]+)?[ \t]+[0-9]+(\\.[0-9]+)?[ \t]*",
            std::regex_constants::basic);
    
    ifstream stream(filePath);
    PRINTLN("Parsing file " << filePath);
    while (stream.is_open() && !stream.eof()) {
        char line[256];
        stream.getline(line, 256, '\n');
        string line_str(line);
        
        //cout << line_str << " ==> "
        //        << regex_search(line_str, rex) << "\n";
        
        if (line_str.find("NAME") != string::npos) {
            
            string::size_type pos = line_str.find_last_of(':');
            line_str = line_str.substr(pos + 1);
            name = trim(line_str);
            
        } else if (line_str.find("DIMENSION") != string::npos) {
            
            string::size_type pos = line_str.find_last_of(':');
            line_str = line_str.substr(pos + 1);
            dimension = stoi(trim(line_str));
            
        } else if (line_str.find_first_of(NUMBER) <= doom(dimension) //ugly hack
                || regex_search(line_str, rex)) {
            switch(parsingMode) {
                case DISCOVER:
                    if (line_str.find_first_of('.') != string::npos) {
                        parsingMode = PARSE_FLOAT;
                        distanceMatrix_f = new float*[dimension];
                        for (int i = 0; i < dimension; i++) {
                            distanceMatrix_f[i] = new float[dimension];
                        }
                        type = FLOAT;
                        cities.push_back(parseFloat(line_str));
                    } else {
                        parsingMode = PARSE_INTEGER;
                        distanceMatrix_i = new int*[dimension];
                        for (int i = 0; i < dimension; i++) {
                            distanceMatrix_i[i] = new int[dimension];
                        }
                        type = INTEGER;
                        cities.push_back(parseInt(line_str));
                    }
                    break;
                    
                case PARSE_INTEGER:
                    cities.push_back(parseInt(line_str));
                    break;
                case PARSE_FLOAT:
                    cities.push_back(parseFloat(line_str));
                    break;
            }
        }
    }
    
    Problem p(name, dimension, type);
    p.setCities(cities);
    if (type == FLOAT) {
        calculateDistances(cities, distanceMatrix_f);
        p.setDistanceMatrix(distanceMatrix_f);
    } else {
        calculateDistances(cities, distanceMatrix_i);
        p.setDistanceMatrix(distanceMatrix_i);
    }

    return p;
}

string trim(std::string toTrim) {
    string::size_type beginning = toTrim.find_first_not_of(" \t");
    toTrim = toTrim.substr(beginning);
    //TODO: remove trailing whitespaces
    //cout << "then " << toTrim << "\n";
    return toTrim;
}

City parseInt(std::string line) {
    line = trim(line);
    //find first whitespace
    string::size_type pos = line.find_first_not_of(NUMBER);
    int id = stoi(line.substr(0, pos));
    // find second whitespace
    line = trim(line.substr(pos));
    pos = line.find_first_not_of(NUMBER);
    int x = stoi(trim(line.substr(0, pos)));
    int y = stoi(trim(line.substr(pos)));
    // create city object
    return City(id, x, y);
}

City parseFloat(std::string line) {
    line = trim(line);
    //find first whitespace
    string::size_type pos = line.find_first_not_of(NUMBER);
    int id = stoi(line.substr(0, pos));
    // find second whitespace
    line = trim(line.substr(pos));
    pos = line.find_first_not_of(NUMBER);
    float x = stof(trim(line.substr(0, pos)));
    float y = stof(trim(line.substr(pos)));
    // create city object
    return City(id, x, y);
}

void calculateDistances(std::vector<City>& cities, float** distanceMatrix) {
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities.size(); j++) {
            int dx = cities[i].getXF() - cities[j].getXF();
            int dy = cities[i].getYF() - cities[j].getYF();
            float dij = sqrt(dx*dx + dy*dy);
            distanceMatrix[i][j] = dij;
        }
    }
}

void calculateDistances(std::vector<City>& cities, int** distanceMatrix) {
    for (int i = 0; i < cities.size(); i++) {
        for (int j = 0; j < cities.size(); j++) {
            int dx = cities[i].getXI() - cities[j].getXI();
            int dy = cities[i].getYI() - cities[j].getYI();
            int dij = sqrt(dx*dx + dy*dy);
            distanceMatrix[i][j] = dij;
        }
    }
}
