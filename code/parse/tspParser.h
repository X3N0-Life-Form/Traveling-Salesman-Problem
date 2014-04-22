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

#include "../core/problem.h"

Problem parseProblem(std::string filePath);
std::string trim(std::string toTrim);

#endif	/* TSPPARSER_H */

