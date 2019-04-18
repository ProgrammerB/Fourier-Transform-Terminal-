@echo off

g++ -Wall -Werror classes\main.cpp classes\argument.cpp classes\fourier_algorithm.h  classes\cooley-tukey.cpp classes\brute-force.cpp -o fourier
