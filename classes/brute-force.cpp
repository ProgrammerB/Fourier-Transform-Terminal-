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
Brute_force<T>::Brute_force(){
  this->index = new std::vector<complex<T>>;
  this->value = new std::vector<complex<T>>;
}


template<typename T>
Brute_force<T>::Brute_force(std::string file_name, double frequency, double frequency_step, std::string output_name)
{
  this->file_name = file_name;
  this->frequency = frequency;
  this->frequency_step = frequency_step;
  this->output_name = output_name;

  this->index = new std::vector<complex<T>>;
  this->value = new std::vector<complex<T>>;
}

/*
template<typename T>
Brute_force<T>::~Brute_force()
{
  delete [] index;
  delete [] value;

  index = nullptr;
  value = nullptr;
}
*/

template<typename T>
std::vector<complex<double>> Brute_force<T>::DFT(const std::vector<double> &index,
   const std::vector<double> &value, std::vector<complex<double>> &result)
{
  std::vector<complex<double>> temp; //temporary complex<double> vector to be made equal to result

  // For each output element
  for (size_t freq = 0; freq < index.size(); freq += frequency_step)
  {
    complex<double> sum(0.0, 0.0);
    // For each input element
    for (size_t time = 0; time < index.size(); time++)
    {
      double angle = 2 * M_PI * time * freq / index.size();
      sum = sum + index[time] * exp(-angle);
    }
    temp.push_back(sum);
  }
  return temp;
}
