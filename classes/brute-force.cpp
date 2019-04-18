#include "brute-force.h"
#include <complex>
#include <vector>
#include <algorithm>
#include <array>
#include <cstdint>
using complex = std::complex<double>;

void Brute_Force::DFT(const std::vector<double> &index, const std::vector<double> &value) {

  std::vector<complex> value(index.size());

  for (size_t frequency = 0; frequency < index.size(); frequency++) {  // For each output element
    double temp = 0;
    temp = (1 / index.end());

    for (size_t time = 0; time < index.size(); time++) {  // For each input element
      double angle = 2 * M_PI * time * frequency / index.size();
      //TODO: change inreal and inimag to class Complex vector
      value = complex(sumreal + inreal[t] * cos(angle) + inimag[t] * sin(angle), 0);
      value = complex(0, -inreal[t] * sin(angle) + inimag[t] * cos(angle));

    }
    //outreal[k] = sumreal;
    //outimag[k] = sumimag;
    value.at(frequency) = temp;
  }
}


for (int elements = 0; elements < index.size(); elements++)
{
    value = std::exp(std::complex(0, ))
}
