/* 
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 22 avril 2014, 13:44
 */

#include <cstdlib>

#include "parse/tspParser.h"
#include "core/problem.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Problem p = parseProblem(argv[1]);
    return 0;
}

