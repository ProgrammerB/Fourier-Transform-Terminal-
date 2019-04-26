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
Brute_Force::Brute_Force(){
  frequency             = new T;
  frequency_step        = new T;
  index                 = new std::vector<complex<T>>;
  value                 = new std::vector<complex<T>>;

  this->frequency       = frequency;
  this->frequency_step  = frequency_step;
}

template<typename T>
Brute_Force<T>::~Brute_Force()
{
  delete [] index;
  delete [] value;
  index = nullptr;
  value = nullptr;
}

//TODO: change parameter to vector<complex<double>>
template<typename T>
std::vector<complex<double>> Brute_Force<T>::DFT(const std::vector<double> &index,
   const std::vector<double> &value, std::vector<complex<double>> &result) {
//  std::vector<complex<double>> value(index.size());
  //Changing real and imaginary parameters
    //@ real(vector.at(i));  -returns real part
    //@ imag(vector.at(i));  -returns imaginary part
  std::vector<complex<double>> temp; //temporary complex<double> vector to be made equal to result
  for (size_t frequency = 0; frequency < index.size(); frequency += frequency_step) {  // For each output element
    complex<double> sum(0.0, 0.0);
    for (size_t time = 0; time < index.size(); time++) {  // For each input element
      double angle = 2 * M_PI * time * frequency / index.size();
      sum = sum + index[time] * exp(-angle);
    }
    //outreal[k] = sumreal;
    //outimag[k] = sumimag;
    //value.at(frequency) = temp;
    temp.push_back(sum);
  }
  return temp;
}

/*

BRAXTON::TODO

for (int elements = 0; elements < index.size(); elements++)
{
    value = std::exp(std::complex(0, ))
}
*/
