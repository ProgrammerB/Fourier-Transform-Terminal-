#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include "fourier_algorithm.h"
#include <cmath>
#include <vector>
#include <complex>
using std::complex;

template<class T>
class Brute_force: public Fourier<T>
{
  public:
    Brute_force();
    Brute_force(std::string file_name, double frequency, double frequency_step, std::string output_name);
    ~Brute_force();

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
