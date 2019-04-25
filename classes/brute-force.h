#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include "fourier_algorithm.h"
#include <cmath>
#include <vector>
#include <complex>
using std::complex;
//TODO: change class and function name
//TODO:: implement print file from fourier abstract classes
template<typename T>
class Brute_Force: protected Fourier<T> {
public:
  ~Brute_Force();
  std::vector<complex<double>> DFT(const std::vector<double> &index,
    const std::vector<double> &value,std::vector<complex<double>> &result);
};

#endif
