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
#include <set>

#include "../core/problem.h"

#define NUMBER "1234567890"

enum ParsingMode {
    DISCOVER,
    PARSE_INTEGER,
    PARSE_FLOAT
};

Problem parseProblem(std::string filePath);
std::string trim(std::string toTrim);
City& parseInt(std::string line);
City& parseFloat(std::string line);

#endif	/* TSPPARSER_H */

