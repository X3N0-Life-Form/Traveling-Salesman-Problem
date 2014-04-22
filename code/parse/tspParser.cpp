#include "tspParser.h"

using namespace std;

Problem parseProblem(string filePath) {
    string name("");
    int dimension = 1;
    DistanceType type = INTEGER;
    ParsingMode parsingMode = DISCOVER;
    int** d_i;
    float** d_f;
    set<City> cities;
    
    ifstream stream(filePath);
    while (stream.is_open() && !stream.eof()) {
        char line[256];
        stream.getline(line, 256, '\n');
        string line_str(line);
        if (line_str.find("NAME") != string::npos) {
            
            string::size_type pos = line_str.find_last_of(':'); //TODO: macro this?
            line_str = line_str.substr(pos + 1);
            name = trim(line_str);
            
        } else if (line_str.find("DIMENSION") != string::npos) {
            
            string::size_type pos = line_str.find_last_of(':');
            line_str = line_str.substr(pos + 1);
            dimension = stoi(trim(line_str));
            
        } else if (line_str.find_first_of(NUMBER) == 0) {
            switch(parsingMode) {
                case DISCOVER:
                    if (line_str.find_first_of('.' != string::npos)) {
                        parsingMode = PARSE_FLOAT;
                        d_f = new float*[dimension];
                        for (int i = 0; i < dimension; i++) {
                            d_f[i] = new float[dimension];
                        }
                        type = FLOAT;
                        //cities.insert(parseFloat(line_str));
                    } else {
                        parsingMode = PARSE_INTEGER;
                        d_i = new int*[dimension];
                        for (int i = 0; i < dimension; i++) {
                            d_i[i] = new int[dimension];
                        }
                        type = INTEGER;
                        //cities.insert(parseInt(line_str));
                    }
                    break;
                    
                case PARSE_INTEGER:
                    //cities.insert(parseInt(line_str));
                    break;
                case PARSE_FLOAT:
                    //cities.insert(parseFloat(line_str));
                    break;
            }
        }
    }
    
    Problem p(name, dimension, type);
    if (parsingMode == PARSE_INTEGER)
        p.setDistances_i(d_i);
    else
        p.setDistances_f(d_f);
    return p;
}

string trim(std::string toTrim) {
    //cout << "in " << toTrim << "\n";
    string::size_type beginning = toTrim.find_first_not_of(" \t");
    toTrim = toTrim.substr(beginning);
    //TODO: remove trailing whitespaces
    //cout << "then " << toTrim << "\n";
    return toTrim;
}
//TODO: return a City?
City& parseInt(std::string line) {
    //find first whitespace
    string::size_type pos = line.find_first_not_of(NUMBER);
    int id = stoi(line.substr(0, pos));
    // find second whitespace
    line = line.substr(pos);
    pos = line.find_first_not_of(NUMBER);
    int x = stoi(line.substr(0, pos));
    int y = stoi(line.substr(pos));
    //TODO: create city object
    //d_i[id]
}

City& parseFloat(std::string line) {
    
}