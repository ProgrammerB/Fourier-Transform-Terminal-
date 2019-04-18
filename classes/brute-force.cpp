#include "brute-force.h"

void Brute_Force::DFT(const vector<double> &index, const vector<double> &value) {

  size_t n = inreal.size();
  for (size_t k = 0; k < n; k++) {  // For each output element
    double sumreal = 0;
    double sumimag = 0;
    for (size_t t = 0; t < n; t++) {  // For each input element
      double angle = 2 * M_PI * t * k / n;
      //TODO: change inreal and inimag to class Complex vector
      sumreal +=  inreal[t] * cos(angle) + inimag[t] * sin(angle);
      sumimag += -inreal[t] * sin(angle) + inimag[t] * cos(angle);
    }
    outreal[k] = sumreal;
    outimag[k] = sumimag;
  }
}
