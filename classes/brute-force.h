#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include "fourier_algorithm.h"
#include <cmath>
#include <vector>

//TODO:: implement print file from fourier abstract classes
class Brute_Force: protected Fourier {
public:
  void DFT(const std::vector<double> &index, const std::vector<double> &value);

private:
  double* frequency;
  double* frequency_step;
  //TODO: change to complex vectors
  std::vector<double>* index;
  std::vector<double>* value;
};

#endif BRUTEFORCE_H
