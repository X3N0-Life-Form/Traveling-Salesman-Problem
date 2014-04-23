/* 
 * File:   tspParser.h
 * Author: etudiant
 *
 * Created on 22 avril 2014, 13:51
 */

#ifndef TSPPARSER_H
#define	TSPPARSER_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <regex>
#include <cmath>

#include "../core/problem.h"
#include "../core/city.h"

#define NUMBER "1234567890"

enum ParsingMode {
    DISCOVER,
    PARSE_INTEGER,
    PARSE_FLOAT
};

Problem parseProblem(std::string filePath);
std::string trim(std::string toTrim);
City* parseInt(std::string line);
City* parseFloat(std::string line);
void calculateDistances(std::vector<City*>& cities, float** distanceMatrix);

#endif	/* TSPPARSER_H */

