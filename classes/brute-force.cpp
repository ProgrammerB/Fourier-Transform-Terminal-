/*
@file: brute-force.cpp
@desc: Function declarations for Brute_force class
@date: 4/29/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#include "fourier_algorithm.h"
#include "brute-force.h"
#include <complex>
#include <vector>
#include <algorithm>
#include <array>
#include <cstdint>
using std::complex;
using std::exp;


/*Brute_force constructor, requires file_name, frequency_step, and output_name
  to create obj
  @param file_name - Name of the file to parse data from
  @param frequency_step - 'Resolution' of fourier transform
  @param output_name - Name of the file to export results to  */
template<typename T>
Brute_force<T>::Brute_force(std::string file_name, double frequency_step, std::string output_name)
{
  this->file_name       = file_name;
  this->frequency_step  = frequency_step;
  this->output_name     = output_name;

  this->index = new std::vector<T>;
  this->value = new std::vector<T>;
}


template<typename T>
void Brute_force<T>::DFT(std::vector<double>* index,
    std::vector<double>* value, std::vector<complex<double>> &result)
{
  // For each output element
  for (size_t freq = 0; freq < index->size(); freq += this->frequency_step)
  {
    complex<double> sum(0.0, 0.0);
    // For each input element
    for (size_t time = 0; time < index->size(); time++)
    {
      double angle = (2 * M_PI * time * freq) / index->size();
      sum += value->at(time) * std::exp(std::complex<T>(0, -angle));
    }
    result.push_back(sum);
  }
}

template class Brute_force<double>;
