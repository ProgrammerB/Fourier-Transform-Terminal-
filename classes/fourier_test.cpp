/*
@file: main.cpp
@desc: Header file for the cooley-tukey FFT algorithm
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#include "brute-force.h"
#include "cooley-tukey.h"
#include <random>
#include <cstdbool>
#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <vector>
#include <typeinfo>
#include <stdlib.h>
#include <iomanip>
#include "argument.h"

#define EPSILON .00001
using std::complex;

const int SAMPLE_SIZE = 1024; //Artifical size of the sample txt
const int RAND_RANGE  = 500;  //Random number range from 0 to N


bool compare_complex (complex<double> A, complex<double> B)
{
   double diff_real = real(A) - real(B);
   double diff_imag = imag(A) - imag(B);
   return (diff_real < EPSILON) && (-diff_real < EPSILON)
            && (diff_imag < EPSILON) && (-diff_imag < EPSILON);
}

//time vector generation
//maybe make max and min rand inside some large interval
std::vector<double>* makeTimeVector(void)
{
  std::vector<double>* sample_vector_time;
  sample_vector_time = new std::vector<double>;

  for(int i = 0; i < SAMPLE_SIZE; i++){
    sample_vector_time->push_back(i);
  }
  return sample_vector_time;
}

//..
//amplitude/temperature vector generation
std::vector<double>* makeValueVector(void)
{
  std::vector<double>* sample_vector_value;
  sample_vector_value = new std::vector<double>;

  srand (time(NULL));
  double rand_num = static_cast<double>(rand() % RAND_RANGE + 1);

  for(int index = 0; index < SAMPLE_SIZE; index++)
  {
    sample_vector_value->push_back(rand_num);
    rand_num = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / RAND_RANGE));
  }
  return sample_vector_value;
}

void FOURIER_TEST(void)
{
  //complex vectors which will be used as references
  std::vector<complex<double>> cooley_ref;
  std::vector<complex<double>> brute_ref;

  //created cooley-tukey and brute force objects
  Brute_force<double> brute{};
  Cooley_tukey<double> cooley{};

  brute.DFT(makeTimeVector(), makeValueVector(), brute_ref);
  cooley.FFT(makeTimeVector(), makeValueVector(), cooley_ref);


  //Compares the vectors side by side (real and imag)
  int num_true = 0;
  for(int i = 0; i < SAMPLE_SIZE; i++)
  {
    if(compare_complex(cooley_ref.at(i), brute_ref.at(i)))
    {
      num_true++;
    }
  }

  //Prints out the data from cooley and brute side-by-side with the difference
  std::cout << std::right << std::setw(16) << "Index" << std::setw(16) << "Cooley"
            << std::setw(16) << "Brute_force" << std::setw(16) << "Difference"
            <<std::endl;
  for (size_t i = 0; i < SAMPLE_SIZE; ++i)
  {
    std::cout << std::setw(16) << i << std::setw(16) << std::abs(cooley_ref.at(i))
              << std::setw(16) << std::abs(brute_ref.at(i)) << std::setw(16)
              << (std::abs(cooley_ref.at(i)) - std::abs(brute_ref.at(i))) << std::endl;
  }

  //If they're all within margin of error, print success
  if(num_true / SAMPLE_SIZE == 1)
  {
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "FOURIER_TEST: testing'(Accuracy of Cooley-tukey and Brute-force)'" << std::endl;
    std::cout << "      Result:  SUCCESS                                            " << std::endl;
    std::cout << "------------------------------------------------------------------\n\n" << std::endl;
  }
  else
  {
    std::cout << "------------------------------------------------------------------" << std::endl;
    std::cout << "FOURIER_TEST: testing'(Equality of Cooley-tukey and Brute-force)'" << std::endl;
    std::cout << "      Result:  FAILURE                                            " << std::endl;
    std::cout << "------------------------------------------------------------------\n\n" << std::endl;
  }
}
