#!/bin/sh
# 
# File:   launch.sh
# Author: etudiant
#
# Created on 6 mai 2014, 10:35:01
#
./dist/Debug/GNU-Linux-x86/traveling_salesman_problem \
    -file data/a280.tsp \
    -maxDepth 2000 \
    -rs swap firstFit \
    -rs swap bestFit \
    -rs swap worstFit \
    -o auto

./dist/Debug/GNU-Linux-x86/traveling_salesman_problem \
    -file data/att48.tsp \
    -maxDepth 2000 \
    -rs swap firstFit \
    -rs swap bestFit \
    -rs swap worstFit \
    -o auto

./dist/Debug/GNU-Linux-x86/traveling_salesman_problem \
    -file data/berlin52.tsp \
    -maxDepth 2000 \
    -rs swap firstFit \
    -rs swap bestFit \
    -rs swap worstFit \
    -o auto

