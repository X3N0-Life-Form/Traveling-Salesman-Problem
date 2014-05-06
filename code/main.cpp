/* 
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 22 avril 2014, 13:44
 */

#include <cstdlib>

#include "parse/tspParser.h"
#include "core/Problem.h"
#include "strategy/Strategy.h"
#include "relation/Swap.h"
#include "strategy/BestFit.h"
#include "run/Runner.h"
#include "utils.h"
#include "strategy/FirstFit.h"
#include "strategy/WorstFit.h"

using namespace std;

//TODO turn that into a function?
#define ARG_CHECK(line, expected) if (++i < argc) {\
                line;\
            } else {\
                PRINTLN("Unsufficient number of arguments, expexted"\
                    << expected);\
            }

Runner* main_runner;
Problem* main_problem;
int maxDepth = 1;
ofstream* f_out = NULL;

/**
 * Note: requires problem to be initialized.
 * @param type firstFit, bestFit or worstFit are valid types
 * @return Strategy object of the requested type
 * @throws Unrecognized Strategy type
 */
Strategy* createStrategy(std::string type) {
    Strategy* s;
    if (type == "firstFit") {
        s = new FirstFit(main_problem->getDimension());
    } else if (type == "bestFit") {
        s = new BestFit(main_problem->getDimension());
    } else if (type == "worstFit") {
        s = new WorstFit(main_problem->getDimension());
    } else {
        throw string("Unrecognized Stategy type ").append(type);
    }
    return s;
}

/**
 * Note: strategy must have been initialized.
 * @param type swap
 * @param strategy not NULL
 * @return Relation object of the requested type
 * @throws NULL strategy passed
 * @throws Unrecognized Relation type
 */
Relation* createRelation(std::string type, Strategy* strategy) {
    Relation* r;
    if (strategy == NULL) {
        throw "NULL Strategy* passed";
    } else if (type == "swap") {
        r = new Swap(*main_problem, *strategy);
    } else if (type == "insert") {
        throw "Not implemented";
    } else if (type == "?invert/revert/?") {
        throw "Not implemented";
    } else {
        throw string("Unrecognized Relation type ").append(type);
    }
    return r;
}

/**
 * Displays help.
 */
void printHelp() {
    PRINTLN("TSP - help");
    PRINTLN("\t-help\t\t\tdisplays this text");
    PRINTLN("\t-file [file path]\tspecify which file to read the problem from");
    PRINTLN("\t-maxDepth [int]\t\tspecify how many times a"
            << " relation will be applied; default = 1");
    PRINTLN("\t-rs [relation] [strategy]\tspecify a relation & strategy"
            << " to apply to the problem. Note that several -rs can/should"
            << " be specified.");
    PRINTLN("");
    PRINTLN("\tValid Relations are\tswap");
    PRINTLN("\tValid Strategies are\tfirstFit, bestFit, worstFit");
}

/**
 * Handles the command line arguments.
 * @param argc
 * @param argv
 */
void dealWithArgs(int argc, char** argv) {
    list<pair<string, string>> rs;
    for (int i = 1; i < argc; i++) {
        string arg(argv[i]);
        if (arg == "-file") {
            ARG_CHECK(main_problem = new Problem(parseProblem(string(argv[i])));,
                    "file name");
        } else if (arg == "-maxDepth") {
            ARG_CHECK(maxDepth = atoi(argv[i]) , "integer");
        } else if (arg == "-rs") {
            string rName, sName;
            ARG_CHECK(rName = string(argv[i]), "relation name");
            ARG_CHECK(sName = string(argv[i]), "strategy name");
            rs.push_back(pair<string, string>(rName, sName));
        } else if (arg == "-o") {
            string fName;
            ARG_CHECK(fName = string(argv[i]), "output file name");
            f_out = new ofstream(fName);
        } else if (arg == "-help") {
            printHelp();
        } else {
            PRINTLN("Unrecognised argument: " << argv[i]);
        }
    }
    main_runner = new Runner(*main_problem, maxDepth);
    // Now that we should have all the data we need, actually create & add these
    for (pair<string, string> p : rs) {
        Strategy* s = createStrategy(p.second);
        Relation* r = createRelation(p.first, s);
        main_runner->addStrategy(s);
        main_runner->addRelation(r);
    }
}

/**
 * Checks whether the data we have so far is good enough to be run.
 * @return true if it is.
 */
bool checkData() {
    if (main_problem == NULL || main_runner == NULL) {//TODO:print errors
        return false;
    } else if (main_runner->getRelations().size() == 0
            || main_runner->getStrategies().size() == 0) {
        return false;
    }
    return true;
}

/**
 * Prints a small recap of the submitted problem and selected relations &
 * strategies.
 */
void printRecap() {
    PRINTLN(main_problem);
    for (Relation* r : main_runner->getRelations()) {
        PRINTLN(r->getType() << " ==> " << r->getStrategy().getType());
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    if (argc > 1) {
        // initialize things
        dealWithArgs(argc, argv);
        // verify that the supplied data is correct
        if (checkData()) {
            printRecap();
            // run things
            main_runner->run();
            // output things
            main_runner->outputResults();
            if (f_out != NULL) {
                main_runner->outputResults(*f_out);
            }
            // delete things
            delete(main_problem);
            delete(main_runner);
            if (f_out != NULL) {
                f_out->close();
                delete(f_out);
            }
        } else {
            PRINTLN("Detected incorrectly entered data. Exiting.");
        }
    } else {
        printHelp();
    }
    // exit things
    return 0;
}

