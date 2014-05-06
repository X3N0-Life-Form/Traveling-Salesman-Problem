#!/bin/sh
# 
# File:   launch.sh
# Author: etudiant
#
# Created on 6 mai 2014, 10:35:01
#
./dist/Debug/GNU-Linux-x86/traveling_salesman_problem \
    -file data/a280.tsp \
    -maxDepth 500 \
    -rs swap firstFit \
    -rs swap bestFit \
    -rs swap worstFit \
    -o data/results/a280.results