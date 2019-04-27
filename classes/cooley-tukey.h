/*
@file: main.cpp
@desc: Header file for the cooley-tukey FFT algorithm
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/
#ifndef COOLEY_TUKEY_H
#define COOLEY_TUKEY_H
#include "fourier_algorithm.h"

template<typename T>
class Cooley_tukey: protected Fourier<T>
{
  public:
    //Cooley_tukey();
    Cooley_tukey(std::string file_name, double frequency, double frequency_step, std::string output_name);
    //~Cooley_tukey();

    void FFT(const std::vector<double> &index, const std::vector<double> &value);
    std::vector<complex<double>> FFT_REC(std::vector<complex<double>> &x, int total_time); //recursion function for FFT

  private:
    double total_time;
};


#endif
