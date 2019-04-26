/*
@file: main.cpp
@desc: Header file for the base algorithm class that other algorithms will derive from
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#ifndef FOURIER_ALGORITHM_H
#define FOURIER_ALGORITHM_H
#define _USE_MATH_DEFINES
#include <string>
#include <vector>
#include <complex>
#include <iostream>
#include <cmath>
#include <memory>
#include <algorithm>
#include <chrono>
#include <fstream>
using std::complex;

template<typename T>
class Fourier
{
  public:
    Fourier(T frequency, T frequency_step, std::string );
    virtual ~Fourier(void) = 0; //makes Fourier class our "abstract" Base class

    void setFrequency    (double frequency);
    void setFrequencyStep(double frequency_step);

    double getFrequency    (void) const;
    double getFrequencyStep(void) const;

    void parseFile (std::string file_path, std::vector<double>& index, std::vector<double>& value);
    void outputFile(std::vector<complex<double>> result);

  protected:
    double frequency;
    double frequency_step;
    std::vector<complex<T>> result;
    std::vector<T>* index;
    std::vector<T>* value;
    std::string file_name;
    std::string output_name;
};

#endif
