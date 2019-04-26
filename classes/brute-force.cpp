#include "brute-force.h"
#include "fourier_algorithm.h"
#include <complex>
#include <vector>
#include <algorithm>
#include <array>
#include <cstdint>
using std::complex;
using std::exp;

//Brute Force constructor
template<typename T>
Brute_force<T>::Brute_force()
{
  index                 = new std::vector<complex<T>>;
  value                 = new std::vector<complex<T>>;
}

template<typename T>
Brute_force<T>::~Brute_force()
{
  delete [] index;
  delete [] value;

  index = nullptr;
  value = nullptr;
}

template<typename T>
std::vector<complex<double>> Brute_force<T>::DFT(const std::vector<double> &index,
   const std::vector<double> &value, std::vector<complex<double>> &result)
{
  std::vector<complex<double>> temp; //temporary complex<double> vector to be made equal to result
  for (size_t frequency = 0; frequency < index.size(); frequency += frequency_step) {  // For each output element
    complex<double> sum(0.0, 0.0);
    for (size_t time = 0; time < index.size(); time++) {  // For each input element
      double angle = 2 * M_PI * time * frequency / index.size();
      sum = sum + index[time] * exp(-angle);
    }
    temp.push_back(sum);
  }
  return temp;
}
