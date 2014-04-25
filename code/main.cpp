/* 
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 22 avril 2014, 13:44
 */

#include <cstdlib>

#include "parse/tspParser.h"
#include "core/Problem.h"

#include "../tests/tspParserTests.h"
#include "strategy/Strategy.h"
#include "relation/Swap.h"
#include "strategy/BestFit.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    

    Problem p = parseProblem(path_a280);
    Neighborhood n(p);
    n.generateRandomNeighborhood();
    n.calculateCost();

    BestFit bf(n.getCost(), 280);
    Swap swap_bf(p, bf);
    
    Neighborhood& result = swap_bf.applyRelation(n);
    
    return 0;
}

