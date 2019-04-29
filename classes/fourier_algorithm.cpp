/*
@file: main.cpp
@desc: Base algorithm class for other classes
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <complex>
#include <sstream>
#include "fourier_algorithm.h"
#include "cooley-tukey.h"
using std::complex;


/*Default constructor assigned memory to frequency and frequency_step then
  sets that equal to the given parameters.
  @param frequency - frequency applied to the fourier algorithm
  @param frequency_step - frequency step applied to the fourier algorithm */
template<typename T>
Fourier<T>::Fourier(void)
{
  index                 = new std::vector<double>;
  value                 = new std::vector<double>;

  this->frequency_step  = frequency_step;
}


//Base destructor, deallocates memory for index and value
template<typename T>
Fourier<T>::~Fourier(void)
{
  delete [] index;
  delete [] value;

  index = nullptr;
  value = nullptr;
}


/*Sets frequency_step equal to the given input
  @param frequency_step - double val to assign frequency_step*/
template<typename T>
void Fourier<T>::setFrequencyStep(double frequency_step)
{
  this->frequency_step = frequency_step;
}


/*Takes a given txt file and parses it assuming there are 2 columns.  It stores
  the 2 different columns in 2 different vectors that are referenced in the call
  @file_path - string of the file name/location
  @index - vector reference for storing the 1st column in txt file
  @value - vector reference for storing the 2nd column in txt file  */
template<typename T>
void Fourier<T>::parseFile(std::string file_path, std::vector<double>* index, std::vector<double>* value)
{
  double time        = 0.0;
  double temperature = 0.0;
  std::ifstream file(file_path);

  while(file >> time >> temperature)
  {
    index->push_back(time);
    value->push_back(temperature);
  }
  file.close();
}


/*Takes the results of a fourier transform and outputs the raw data in a txt
  file named using user inputted data
  @param result - fourier analysis data
  @param file_name - name for the outputted file, must end in .txt  */
template<typename T>
void Fourier<T>::outputFile(std::vector<complex<T>> result, std::string file_name)
{
  std::ofstream file;
  file.open(file_name);
  std::ostringstream convert_string;

  if (file.is_open())
  {
    for (unsigned int vector_index = 0; vector_index < result.size(); vector_index++)
    {
      file << std::real(result.at(vector_index)) << " " << std::imag(result.at(vector_index)) << '\n';
    }
  }
  file.close();
}

template class Fourier<double>;
