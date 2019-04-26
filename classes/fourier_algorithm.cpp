/*
@file: main.cpp
@desc: Base algorithm class for other classes
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#include "Fourier.h"
#include "cooley-tukey.h"
#include <vector>


/*Default constructor assigned memory to frequency and frequency_step then
  sets that equal to the given parameters.
  @param frequency - frequency applied to the fourier algorithm
  @param frequency_step - frequency step applied to the fourier algorithm */
template<typename T>
Fourier<T>::Fourier(T frequency, T frequency_step)
{
  frequency             = new T;
  frequency_step        = new T;
  index                 = new std::vector<complex<T>>;
  value                 = new std::vector<complex<T>>;

  this->frequency       = frequency;
  this->frequency_step  = frequency_step;
}


/*Default constructor, deallocates memory to frequency and frequency_step then
  assigns them to a nullptr value */
template<typename T>
virtual Fourier<T>::~Fourier(void)
{
  delete index;
  delete value;

  index           = nullptr;
  value           = nullptr;
}


/*Sets frequency equal to the given input
  @param frequency - double val to assign frequency*/
template<typename T>
void Fourier<T>::setFrequency(double frequency)
{
  this->frequency = frequency;
}


/*Sets frequency_step equal to the given input
  @param frequency_step - double val to assign frequency_step*/
template<typename T>
void Fourier<T>::setFrequencyStep(double frequency_step)
{
  this->frequency_step = frequency_step;
}


/*Returns the frequency variable
  @return - objects local frequency ptr value*/
template<typename T>
double Fourier<T>::getFrequency(void) const
{
  return this->frequency;
}


/*Returns the frequency_step variable
  @return - objects local frequency_step ptr value*/
template<typename T>
double Fourier<T>::getFrequencyStep(void) const
{
  return this->frequency_step;
}


/*Takes a given txt file and parses it assuming there are 2 columns.  It stores
  the 2 different columns in 2 different vectors that are referenced in the call
  @file_path - string of the file name/location
  @index - vector reference for storing the 1st column in txt file
  @value - vector reference for storing the 2nd column in txt file  */

//TODO:Change to implement use of complex vector
template<typename T>
void Fourier<T>::parseFile(std::string file_path, std::vector<double>& index, std::vector<double>& value)
{
  double time = 0.0;
  double temperature = 0.0;
  std::ifstream file(file_path);

  while(file >> time >> temperature)
  {
    index.push_back(time);
    value.push_back(temperature);
  }

  file.close();
}


template<typename T>
void Fourier<T>::outputFile(std::vector<complex<double>> result, std::string file_name = "result.txt")
{
  std::ofstream file;
  file.open(file_name);

  if (file.open())
  {
    while (file << result);
  }

  file.close();
}
