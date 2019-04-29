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
#include <cstdint>
#include <array>
#include <algorithm>
using std::complex;


template<typename Iter, typename T>
void FFT_REC(Iter first, Iter last, T data_type, double frequency_step, int total_time);


template<typename T>
Cooley_tukey<T>::Cooley_tukey(std::string file_name, double frequency, double frequency_step, std::string output_name)
{
	this->file_name			 = file_name;
  this->frequency_step = frequency_step;
  this->output_name 	 = output_name;

  this->index = new std::vector<T>;
  this->value = new std::vector<T>;
}


template<typename T>
void Cooley_tukey<T>::FFT(std::vector<T>* index, std::vector<T>* value, std::vector<complex<T>>& data)
{
	// Make copy of array and apply window
	for (unsigned int time = 0; time < index->size(); time++)
	{
		data.push_back(std::complex<T>(value->at(time), 0));
	}

	// Start recursion function to split up the tasks
	FFT_REC(std::begin(data), std::end(data), data, this->frequency_step, this->value->size());
}


template<typename Iter, typename T>
void FFT_REC(Iter first, Iter last, T data_type, double frequency_step, int total_time)
{
	auto current_size = last - first;
	// Check if it is split up enough
	if (current_size >= 2)
	{
		// Split even and odds up
		std::vector<complex<double>> odd;
		//std::vector<complex<T>> even;

		odd.resize(current_size / 2);
		//even.resize(total_time/2);

		for (int i = 0; i < (current_size / 2); ++i)
		{
		    odd.at(i) 	= first[i * 2 + 1];
				first[i] 		= first[i * 2];
		}

		for (int i = 0; i < current_size / 2; ++i)
		{
				first[i + current_size / 2] = odd.at(i);
		}

		//Split on tasks
		auto split = first + current_size / 2;
		FFT_REC(first, split, data_type, frequency_step, total_time);
		FFT_REC(split, last, data_type, frequency_step, total_time);

		// DFT portion of FFT - calculates after everything has been split up through FFT_REC
		for (int frequency = 0; frequency < current_size / 2; ++frequency)
		{
			auto t = std::exp(std::complex<double>(0, -2.0 * M_PI * frequency / current_size));


			//Result of Cooley-Tukey algorithm:
			//*This gives us the frequency values at certain times
			auto& bottom 	= first[frequency];
			auto& top 		= first[frequency + current_size / 2];
			top 					= bottom - t * top;
			bottom 				-= top - bottom;

		}
	}
}

template class Cooley_tukey<double>;
