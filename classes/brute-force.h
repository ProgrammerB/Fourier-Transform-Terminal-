#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include "fourier_algorithm.h"
#include <cmath>
#include <vector>
#include <complex>
#include <string>
using std::complex;

template<class T>
class Brute_force: public Fourier<T>
{
  public:
    Brute_force();
    Brute_force(std::string file_name, double frequency, double frequency_step, std::string output_name);
    //~Brute_force();

    void DFT(std::vector<double>* index,
      std::vector<double>* value, std::vector<complex<double>>& result);

};

#endif
