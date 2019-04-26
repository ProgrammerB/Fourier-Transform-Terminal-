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

template<typename T>
class Cooley_tukey: public Fourier<T> {
public:
  Cooley_tukey();
  Cooley_tukey(T frequency, T frequency_step);
  ~Cooley_tukey();

  void FFT(const std::vector<double> &index, const std::vector<double> &value);
  void FFT_REC(std::vector<complex<double>> &x, int total_time); //recursion function for FFT
private:
  double total_time;
  double frequency;
  double frequency_step;
  std::vector<complex<T>> result;
  std::vector<T>* index;
  std::vector<T>* value;
  std::string file_name;
  std::string output_name;
};


#endif
