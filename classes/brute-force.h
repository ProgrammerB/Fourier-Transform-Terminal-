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
class Brute_Force: public Fourier<T> {
public:
  Brute_Force();
  //~Brute_Force();
  std::vector<complex<double>> DFT(const std::vector<double> &index,
    const std::vector<double> &value,std::vector<complex<double>> &result);
private:
  double frequency;
  double frequency_step;
  std::vector<complex<T>> result;
  std::vector<T>* index;
  std::vector<T>* value;
  std::string file_name;
  std::string output_name;
};

#endif
