#!/bin/sh
# 
# File:   cleanResults.sh
# Author: etudiant
#
# Created on 12 mai 2014, 16:35:58
#
echo "rm data/results/*.results"
rm data/results/*.results
echo "rm callgrind.out.*"
rm callgrind.out.*