#!/bin/sh
# 
# File:   launch.sh
# Author: etudiant
#
# Created on 6 mai 2014, 10:35:01
#
#./dist/Debug/GNU-Linux-x86/traveling_salesman_problem -file data/a280.tsp -maxDepth 2000 -sameStartingPoint -doubleCheckCost -r swap -r insert -r reverse -s firstFit -s bestFit -s worstFit

maxDepth=2000
relations="-r reverse"
strategies="-s firstFit -s bestFit -s worstFit"
intervals="-saveIntervalData -intervalStep 4 -intervalType disjoint"
miscArgs="-sameStartingPoint -doubleCheckCost -noMaxDepth -choicePicker"

execPath="./dist/Debug/GNU-Linux-x86/traveling_salesman_problem"
args="-maxDepth $maxDepth $miscArgs $intervals $relations $strategies -o auto"

loopCount=1

make

if [ "$#" -ge 1 ]
then
    echo "Setting loop count to $1"
    loopCount=$1
fi

for i in `seq 1 $loopCount`
do
    echo "Loop #$i/$loopCount"
    #$execPath -file data/a280.tsp $args
    $execPath -file data/att48.tsp $args
    #$execPath -file data/berlin52.tsp $args
    #$execPath -file data/ali535.tsp $args
    #$execPath -file data/ch130.tsp $args
    #$execPath -file data/ch150.tsp $args
    #$execPath -file data/burma14.tsp $args
    #$execPath -file data/bier127.tsp $args
done

#big
#$execPath -file data/brd14051.tsp -maxDepth 256000 $miscArgs $relations $strategies -o auto

echo "Looped $loopCount times"
echo "Merging all .csv into allResults.csv"
cat data/results/*.csv > data/allResults.csv
