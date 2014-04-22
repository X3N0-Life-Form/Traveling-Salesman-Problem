#include "tspParser.h"

using namespace std;

Problem parseProblem(string filePath) {
    string name("");
    int dimension = 1;
    DistanceType type = INTEGER;
    
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
        }
    }
    
    Problem p(name, dimension, type);
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