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

//TODO: make a complex classes
//TODO: make it so complex vector can be used in derived classes

template<typename T>
class Fourier
{
  public:
    Fourier(double frequency, double frequency_step);
    virtual ~Fourier(void) = 0;
    //TODO: Add copy constructor

    void setFrequency(double frequency);
    void setFrequencyStep(double frequency_step);

    double getFrequency(void)     const;
    double getFrequencyStep(void) const;

    void parseFile(std::string file_path, std::vector<double>& index, std::vector<double>& value);
    void outputFile(std::vector<complex<double>> result);
    //TODO: print real and imaginary variables
    //TODO: for loop to assign user input file to vector
    //TODO: make class or struct for complex (complex object or structure)
      //@ vector<complex>
  protected:
    double frequency;
    double frequency_step;
    std::vector<complex<double>> result;
    std::vector<double>* index;
    std::vector<double>* value;
};

#endif
