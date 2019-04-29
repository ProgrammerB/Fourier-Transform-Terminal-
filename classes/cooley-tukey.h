/*
@file: main.cpp
@desc: Header file for the cooley-tukey FFT algorithm
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#ifndef COOLEY_TUKEY_H
#define COOLEY_TUKEY_H

#include <cmath>
#include <vector>
#include <complex>
#include <string>
#include "fourier_algorithm.h"
using std::complex;


template<typename T>
class Cooley_tukey: public Fourier<T>
{
  public:
    Cooley_tukey(std::string file_name, double frequency, double frequency_step, std::string output_name);

    std::vector<complex<T>>& getData(void) {return data; }

    void FFT(std::vector<T>* index, std::vector<T>* value, std::vector<complex<T>>& result);
  private:
    std::vector<complex<T>> data;
};

#endif
