/*
@file: main.cpp
@desc: Header file for the base algorithm class that other algorithms will derive from
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#ifndef FOURIER_ALGORITHM_H
#define FOURIER_ALGORITHM_H

class Fourier
{
  public:
    Fourier(double frequency, double frequency_step);
    ~Fourier(void);

    void setFrequency(double frequency);
    void setFrequencyStep(double frequency_step);

    double getFrequency(void)     const;
    double getFrequencyStep(void) const;
  protected:
    double* frequency;
    double* frequency_step;
};

#endif
