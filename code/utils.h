/* 
 * File:   utils.h
 * Author: etudiant
 *
 * Created on 24 avril 2014, 14:25
 */

#ifndef UTILS_H
#define	UTILS_H

#include <string>

const std::string path_a280 = "data/a280.tsp";
const std::string path_att48 = "data/att48.tsp";
const std::string path_berlin52 = "data/berlin52.tsp";
const std::string path_burma14 = "data/burma14.tsp";

#define ARRAY_COPY(target, source, length) for (int iii = 0; iii < length; iii++) {target[iii] = source[iii];}
#define SWAP(target, i, j) auto c = target[i]; target[i]=target[j]; target[j]=c;
void insert(int* target_array, int* source_array, int size, int origin, int target);
void reverse(int* target_array, int*source_array, int size, int left, int right);

#define ARRAY_PRINT(target, length) for (int i=0; i<length; i++) {std::cout<<target[i]<<" ";}
#define PRINTLN(line) std::cout << "\n" << line; std::cout.flush();

// stuff for main.cpp
#include "strategy/Strategy.h"
#include "relation/Relation.h"
Strategy* createStrategy(std::string type);
Relation* createRelation(std::string type, Strategy* strategy);
void dealWithArgs(int argc, char** argv);
bool checkData();

#endif	/* UTILS_H */

