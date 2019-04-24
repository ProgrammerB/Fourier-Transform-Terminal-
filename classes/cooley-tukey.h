/*
@file: main.cpp
@desc: Header file for the cooley-tukey FFT algorithm
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/
//TODO: change class and function name
#ifndef COOLEY_TUKEY_H
#define COOLEY_TUKEY_H
#include "fourier_algorithm.h"

class Cooley_tukey: protected Fourier {
public:
  void FFT(int *x_in, complex<double> *x_out, int N);
  void FFT_REC(complex<double> *x, int N); //recursion function for FFT

private:
  double frequency;
  double frequency_step;
  std::vector<std::complex<double>> result;
  std::vector<double>* index;
  std::vector<double>* value;
};


#endif
