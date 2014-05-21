#!/bin/sh
# 
# File:   launch.sh
# Author: etudiant
#
# Created on 6 mai 2014, 10:35:01
#
#./dist/Debug/GNU-Linux-x86/traveling_salesman_problem -file data/a280.tsp -maxDepth 2000 -sameStartingPoint  -r swap -r insert -s firstFit -s bestFit -s worstFit

maxDepth=2000
relations="-r swap -r insert"
strategies="-s firstFit -s bestFit -s worstFit"

execPath="./dist/Debug/GNU-Linux-x86/traveling_salesman_problem"
args="-maxDepth $maxDepth -sameStartingPoint $relations $strategies -o auto"

make

$execPath -file data/a280.tsp $args
$execPath -file data/att48.tsp $args
$execPath -file data/berlin52.tsp $args
#$execPath -file data/ali535.tsp $args      #malloc error w/ insert
$execPath -file data/ch130.tsp $args
$execPath -file data/ch150.tsp $args
#$execPath -file data/bier127.tsp $args     #malloc error w/ insert
#$execPath -file data/burma14.tsp $args     #parsing error
#big
#$execPath -file data/brd14051.tsp -maxDepth 4 $relations $strategies -o auto


echo "Merging all .csv into allResults.csv"
cat data/results/*.csv > data/allResults.csv
