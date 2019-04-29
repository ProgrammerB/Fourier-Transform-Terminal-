/*
@file: main.cpp
@desc: Class definitions for the cooley-tukey class
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#include "Cooley-tukey.h"
#include "fourier_algorithm.h"
#include <string>
#include <vector>
#include <complex>
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
	total_time = this->index->size();
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
void Cooley_tukey<T>::FFT(std::vector<T>* index, std::vector<T>* value, std::vector<complex<T>>& result)
{
	std::cout << index->size() << std::endl;
	// Make copy of array and apply window
	for (unsigned int time = 0; time < index->size(); time++)
	{
		result.push_back(index->at(time));
		result.at(time) *= 1; //Window
	}

	// Start recursion function to split up the tasks
	FFT_REC(result, index->size());
}


template<typename T>
void Cooley_tukey<T>::FFT_REC(std::vector<complex<T>>& result, int total_time)
{
	// Check if it is split up enough
	if (total_time > 1)
	{
		// Split even and odds up
		std::vector<complex<T>> odd;
		std::vector<complex<T>> even;
		odd.reserve(total_time/2);
		even.reserve(total_time/2);
		for (int i = 0; i < total_time / 2; i++)
		{
		    even.push_back(result.at(i*2));
		    odd.push_back(result.at(i*2+1));
		}


		//Split on tasks
		FFT_REC(even, total_time/2);
		FFT_REC(odd, total_time/2);

		// DFT portion of FFT - calculates after everything has been split up through FFT_REC
		for (int frequency = 0; frequency < total_time / 2; frequency += this->frequency_step)
		{
			std::complex<T> t = exp(std::complex<T>(0, (-2 * M_PI * frequency) / total_time)) * odd.at(frequency);

			//Result of Cooley-Tukey algorithm:
				//*This gives us the frequency values at certain times
			result.at(frequency) = even.at(frequency) + t;
			result.at(total_time / 2 + frequency) = even.at(frequency) - t;

		}
	}
}

template class Cooley_tukey<double>;
