#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include "fourier_algorithm.h"
#include <cmath>
#include <vector>
#include <complex>
using std::complex;

//TODO:: implement print file from fourier abstract classes
class Brute_Force: protected Fourier {
public:
  std::vector<complex<double>> DFT(const std::vector<double> &index,
    const std::vector<double> &value,std::vector<complex<double>> &result);

private:
  double frequency;
  double frequency_step;
  //TODO: change to complex vectors
  std::vector<std::complex<double>> result;
  std::vector<double>* index;
  std::vector<double>* value;
};

#endif
