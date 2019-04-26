@echo off

g++ -std=c++11 -Wall -Werror classes\main.cpp classes\argument.cpp classes\fourier_algorithm.cpp  classes\cooley-tukey.cpp classes\brute-force.cpp -o fourier
