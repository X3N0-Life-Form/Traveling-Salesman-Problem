#!/bin/sh
# 
# File:   launch.sh
# Author: etudiant
#
# Created on 6 mai 2014, 10:35:01
#
#-file data/a280.tsp -maxDepth 2000 -r swap -s firstFit -s bestFit -s worstFit -o auto

./dist/Debug/GNU-Linux-x86/traveling_salesman_problem \
    -file data/a280.tsp \
    -maxDepth 2000 -r swap -s firstFit -s bestFit -s worstFit -o auto

./dist/Debug/GNU-Linux-x86/traveling_salesman_problem \
    -file data/att48.tsp \
    -maxDepth 2000 -r swap -s firstFit -s bestFit -s worstFit -o auto

./dist/Debug/GNU-Linux-x86/traveling_salesman_problem \
    -file data/berlin52.tsp \
    -maxDepth 2000 -r swap -s firstFit -s bestFit -s worstFit -o auto

./dist/Debug/GNU-Linux-x86/traveling_salesman_problem \
    -file data/ali535.tsp \
    -maxDepth 2000 -r swap -s firstFit -s bestFit -s worstFit -o auto

./dist/Debug/GNU-Linux-x86/traveling_salesman_problem \
    -file data/ch130.tsp \
    -maxDepth 2000 -r swap -s firstFit -s bestFit -s worstFit -o auto

./dist/Debug/GNU-Linux-x86/traveling_salesman_problem \
    -file data/ch150.tsp \
    -maxDepth 2000 -r swap -s firstFit -s bestFit -s worstFit -o auto

./dist/Debug/GNU-Linux-x86/traveling_salesman_problem \
    -file data/bier127.tsp \
    -maxDepth 2000 -r swap -s firstFit -s bestFit -s worstFit -o auto

#./dist/Debug/GNU-Linux-x86/traveling_salesman_problem \
#    -file data/burma14.tsp \
#    -maxDepth 2000 -r swap -s firstFit -s bestFit -s worstFit -o auto

#./dist/Debug/GNU-Linux-x86/traveling_salesman_problem \
#    -file data/brd14051.tsp \
#    -maxDepth 2000 -r swap -s firstFit -s bestFit -s worstFit -o auto

echo "Merging all .csv into allResults.csv"
cat data/results/*.csv > data/allResults.csv
