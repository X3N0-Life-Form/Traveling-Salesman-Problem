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
#include "relation/Insert.h"
#include "relation/Reverse.h"

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
int main_maxDepth = 1;
bool main_noDepth = false;
bool main_sameStartingPoint= false;
ofstream* main_f_out = NULL;
ofstream* main_f_out_csv = NULL;
string main_oFileName("");
string main_oFileNameCSV("");
bool main_quietMode = true;
bool main_doubleCheckCost = false;
bool main_noNeighborhoodCutoff = true;

/**
 * Note: requires problem to be initialized.
 * @param type firstFit, bestFit or worstFit are valid types
 * @return Strategy object of the requested type
 * @throws Unrecognized Strategy type
 */
Strategy* createStrategy(std::string type) {
    Strategy* s = NULL;
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
 * @throws Unrecognized Relation type
 */
Relation* createRelation(std::string type, Strategy* strategy) {
    Relation* r = NULL;
    if (type == "swap") {
        r = new Swap(*main_problem, strategy);
    } else if (type == "insert") {
        r = new Insert(*main_problem, strategy);
    } else if (type == "reverse") {
        r = new Reverse(*main_problem, strategy);
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
    PRINTLN("\t-help\t\t\t\tdisplays this text");
    
    PRINTLN("\t-file [file path]\t\tspecify which file to read the problem from");
    
    PRINTLN("\t-maxDepth [int]\t\t\tspecify how many times a"
            << " relation will be applied; default = 1");
    PRINTLN("\t-noMaxDepth\t\t\tremoves the depth limit;"
            << " overrides the previous option");
    
    PRINTLN("\t-sameStartingPoint\treuse the same starting path for each run");
    
    PRINTLN("\t-r [relation]\t\t\tspecify a relation to apply to the problem");
    PRINTLN("\t-s [strategy]\t\t\tspecify a strategy to apply to the problem");
    PRINTLN("\t(deprecated) -rs [relation] [strategy]\tspecify a relation & strategy"
            << " to apply to the problem. Note that several -rs can/should"
            << " be specified.");
    
    PRINTLN("\t-quietMode [yes|no]\t\tIf set to no, print depth and loop info."
            << " Defaults to yes.");
    
    PRINTLN("\t-doubleCheckCost\t\t\tperform a full calculation check at "
            << "the end of each execution and report inconsitencies");
    
    PRINTLN("\t-neighborhoodCutoff\t\tactivate the neighborhood cutoff "
            << "feature, see below");
    PRINTLN("\t(deprecated) -noNeighborhoodCutoff\tdo not remove any value "
            << "when creating pair lists, even meaningless or redundant ones. "
            << "Note: on by default");
    
    PRINTLN("\t-o [file path]\t\t\tspecifies an output file");
    PRINTLN("\t-o auto\t\t\t\tlet the application name the output file");
    
    PRINTLN("");
    PRINTLN("Valid Relations are\tswap, insert, reverse");
    PRINTLN("Valid Strategies are\tfirstFit, bestFit, worstFit");
}

std::string getOutputName(std::string problemName, bool csv = false) {
    string res("data/results/");
    res.append(problemName);
    time_t t = time(0);
    struct tm* now = localtime( & t );
    res.append(".");
    res.append(std::to_string(1900 + now->tm_year));
    res.append("-");
    res.append(std::to_string(1 + now->tm_mon));
    res.append("-");
    res.append(std::to_string(now->tm_mday));
    res.append("__");
    res.append(std::to_string(1 + now->tm_hour));
    res.append("_");
    res.append(std::to_string(1 + now->tm_min));
    res.append("_");
    res.append(std::to_string(1 + now->tm_sec));
    if (csv)
        res.append(".csv");
    else
        res.append(".results");
    return res;
}

/**
 * Handles the command line arguments.
 * @param argc
 * @param argv
 */
void dealWithArgs(int argc, char** argv) {
    list<pair<string, string>> rs;
    list<string> r_list;
    list<string> s_list;
    string rName, sName;
    
    for (int i = 1; i < argc; i++) {
        string arg(argv[i]);
        if (arg == "-file") {
            ARG_CHECK(main_problem = new Problem(parseProblem(string(argv[i])));,
                    "file name");
        } else if (arg == "-maxDepth") {
            ARG_CHECK(main_maxDepth = atoi(argv[i]) , "integer");
        } else if (arg == "-noMaxDepth") {
            PRINTLN("Selecting no max depth");
            main_noDepth = true;
        } else if (arg == "-sameStartingPoint") {
            main_sameStartingPoint = true;
        } else if (arg == "-rs") {
            PRINTLN("Warning: \"-rs\" argument is deprecated."
                    << " Use \"-r\" and \"-s\" instead.");
            ARG_CHECK(rName = string(argv[i]), "relation name");
            ARG_CHECK(sName = string(argv[i]), "strategy name");
            rs.push_back(pair<string, string>(rName, sName));
        } else if (arg == "-r") {
            ARG_CHECK(rName = string(argv[i]), "relation name");
            r_list.push_back(rName);
        } else if (arg == "-s") {
            ARG_CHECK(sName = string(argv[i]), "strategy name");
            s_list.push_back(sName);
        } else if (arg == "-quietMode") {
            if (string(argv[++i]) == "no") {
                main_quietMode = false;
            } else {
                main_quietMode = true;
            }
        } else if (arg == "-doubleCheckCost") {
            main_doubleCheckCost = true;
        } else if (arg == "-noNeighborhoodCutoff") {
            main_noNeighborhoodCutoff = true;
        } else if (arg == "-neighborhoodCutoff") {
            main_noNeighborhoodCutoff = false;
        } else if (arg == "-o") {
            ARG_CHECK(main_oFileName = string(argv[i]), "output file name");
        } else if (arg == "-help") {
            printHelp();
        } else {
            PRINTLN("Unrecognised argument: " << argv[i]);
        }
    }
    if (main_oFileName == "auto") {
        main_oFileName = getOutputName(main_problem->getName());
        main_oFileNameCSV = getOutputName(main_problem->getName(), true);
    }
    if (main_oFileName != "") {
        main_f_out = new ofstream(main_oFileName);
        main_f_out_csv = new ofstream(main_oFileNameCSV);
    }
    
    main_runner = new Runner(*main_problem, main_maxDepth);
    // set runner settings
    main_runner->setNoDepth(main_noDepth);
    main_runner->setSameStartingPoint(main_sameStartingPoint);
    main_runner->setDoubleCheckCost(main_doubleCheckCost);
    main_runner->setNoNeighborhoodCutoff(main_noNeighborhoodCutoff);
    // Now that we should have all the data we need, actually create & add these
    for (string s_type : s_list) {
        Strategy* s = createStrategy(s_type);
        main_runner->addStrategy(s);
    }
    Strategy* s_default = main_runner->getStrategies().front();
    for (string r_type : r_list) {
        Relation* r = createRelation(r_type, s_default);
        main_runner->addRelation(r);
    }
    // deprecated
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
    PRINTLN(*main_problem);
    PRINTLN("maxDepth=" << main_maxDepth);
    //for (Relation* r : main_runner->getRelations()) {
    //    PRINTLN(r->getType() << " ==> " << r->getStrategy().getType());
    //}
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
            if (main_f_out != NULL) {
                PRINTLN("Results saved in " << main_oFileName);
                PRINTLN("\tas CSV in " << main_oFileNameCSV);
                main_runner->outputResults(*main_f_out);
                main_runner->outputResultsCSV(*main_f_out_csv);
            }
            // delete things
            delete(main_problem);
            delete(main_runner);
            if (main_f_out != NULL) {
                main_f_out->close();
                main_f_out_csv->close();
                delete(main_f_out);
                delete(main_f_out_csv);
            }
        } else {
            PRINTLN("Detected incorrectly entered data. Exiting.");
        }
    } else {
        printHelp();
    }
    PRINTLN("");
    // exit things
    return 0;
}

