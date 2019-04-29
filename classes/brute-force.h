/*
@file: brute-force.h
@desc: Header file for the Brute_force class
@date: 4/29/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <vector>
#include <complex>
#include <string>
#include "fourier_algorithm.h"
using std::complex;


template<typename T>
class Brute_force: public Fourier<T>
{
  public:
    Brute_force();
    Brute_force(std::string file_name, double frequency_step, std::string output_name);

    void DFT(std::vector<double>* index,
      std::vector<double>* value, std::vector<complex<double>>& result);

};

#endif
