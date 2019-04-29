@echo off

g++ -std=c++17 -Wall -Werror classes\main.cpp classes\argument.cpp classes\fourier_algorithm.cpp classes\cooley-tukey.cpp classes\brute-force.cpp classes\fourier_test.cpp -o fourier
