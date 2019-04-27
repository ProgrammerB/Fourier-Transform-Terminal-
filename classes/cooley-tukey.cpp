/*
@file: main.cpp
@desc: Class definitions for the cooley-tukey class
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#include "Cooley-tukey.h"
#include "fourier_algorithm.h"
#include <string>
using std::complex;


template<typename T>
Cooley_tukey<T>::Cooley_tukey()
{
	this->index = new std::vector<T>;
	this->value = new std::vector<T>;

	this->file_name = "none";
	this->output_name = "result.txt";
	this->frequency_step = 0;
	this->frequency = 0;
}


template<typename T>
Cooley_tukey<T>::Cooley_tukey(std::string file_name, double frequency, double frequency_step, std::string output_name)
{
	this->file_name = file_name;
  this->frequency = frequency;
  this->frequency_step = frequency_step;
  this->output_name = output_name;

  this->index = new std::vector<T>;
  this->value = new std::vector<T>;
	total_time = this->index.size();
}

/*
template<typename T>
Cooley_tukey<T>::~Cooley_tukey()
{
	delete  index;
	delete  value;

	index = nullptr;
	value = nullptr;
}
*/

template<typename T>
void Cooley_tukey<T>::FFT(const std::vector<T> &index, const std::vector<T> &value)
{
total_time = index.size();
std::vector<complex<T>> temp;

	// Make copy of array and apply window
	for (int time = 0; time < total_time; time++)
	{
		temp[time] = index[time];
		temp[time] *= 1; // Window
	}

	// Start recursion function to split up the tasks
	FFT_REC(temp, total_time);
}


template<typename T>
std::vector<complex<T>> Cooley_tukey<T>::FFT_REC(std::vector<complex<T>>& temp, int total_time)
{
	// Check if it is split up enough
	if (total_time >= 2)
	{

		// Split even and odds up
		complex<T> odd[total_time/2];
		complex<T> even[total_time/2];
		for (int i = 0; i < total_time / 2; i++)
		{
			even[i] = temp[i*2];
			odd[i] 	= temp[i*2+1];
		}

		// Split up tasks through FFT recursion method
		FFT_REC(even, total_time/2);
		FFT_REC(odd, total_time/2);


		// DFT portion of FFT - calculates after everything has been split up through FFT_REC
		for (int frequency = 0; frequency < total_time / 2; frequency += this->frequency_step)
		{
			std::complex<T> t = exp(std::complex<T>(0, -2 * M_PI * frequency / total_time)) * odd[frequency];

			//Result of Cooley-Tukey algorithm:
				//*This gives us the frequency values at certain times
			temp[frequency] = even[frequency] + t;
			temp[total_time / 2 + frequency] = even[frequency] - t;

		}
	}
	return temp;
}

template class Cooley_tukey<double>;
