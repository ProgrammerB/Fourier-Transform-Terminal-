/*
@file: main.cpp
@desc: Header file for the cooley-tukey FFT algorithm
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/
#ifndef COOLEY_TUKEY_H
#define COOLEY_TUKEY_H

#include "fourier_algorithm.h"
#include <cmath>
#include <vector>
#include <complex>
#include <string>
using std::complex;

template<typename T>
class Cooley_tukey: public Fourier<T>
{
  public:
    Cooley_tukey();
    Cooley_tukey(std::string file_name, double frequency, double frequency_step, std::string output_name);
    //~Cooley_tukey();

    void FFT(std::vector<T>* index, std::vector<T>* value);
    void FFT_REC(std::vector<complex<T>> &temp, int total_time); //recursion function for FFT

  private:
    int total_time;
};


#endif
