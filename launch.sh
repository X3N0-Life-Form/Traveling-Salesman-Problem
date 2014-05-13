#!/bin/sh
# 
# File:   launch.sh
# Author: etudiant
#
# Created on 6 mai 2014, 10:35:01
#
#-file data/a280.tsp -maxDepth 2000 -r swap -s firstFit -s bestFit -s worstFit -o auto

maxDepth=64000
relations="-r swap"
strategies="-s firstFit -s bestFit -s worstFit"

execPath="./dist/Debug/GNU-Linux-x86/traveling_salesman_problem"
args="-maxDepth $maxDepth $relations $strategies -o auto"

$execPath -file data/a280.tsp $args
$execPath -file data/att48.tsp $args
$execPath -file data/berlin52.tsp $args
$execPath -file data/ali535.tsp $args
$execPath -file data/ch130.tsp $args
$execPath -file data/ch150.tsp $args
$execPath -file data/bier127.tsp $args
#$execPath -file data/burma14.tsp $args
$execPath -file data/brd14051.tsp $args

echo "Merging all .csv into allResults.csv"
cat data/results/*.csv > data/allResults.csv
