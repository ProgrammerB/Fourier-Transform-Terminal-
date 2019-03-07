/*
@file: main.cpp
@desc: Base algorithm class for other classes
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#include "Fourier.h"

Fourier::Fourier(double frequency, double frequency_step)
{
  frequency             = new double;
  frequency_step        = new double;

  this->frequency       = frequency;
  this->frequency_step  = frequency_step;
}


Fourier::~Fourier(void)
{
  delete frequency;
  delete frequency_step;

  frequency       = nullptr;
  frequency_step  = nullptr;
}


void Fourier::setFrequency(double frequency)
{
  this->frequency = frequency;
}


void Fourier::setFrequencyStep(double frequency_step)
{
  this->frequency_step = frequency_step;
}


double Fourier::getFrequency(void) const
{
  return this->frequency;
}


double Fourier::getFrequencyStep(void) const
{
  return this->frequency_step;
}
