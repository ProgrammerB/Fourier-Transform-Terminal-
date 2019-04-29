/*
@file: main.cpp
@desc: Class definitions for the cooley-tukey class
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#include "fourier_algorithm.h"
#include "Cooley-tukey.h"
#include <string>
#include <vector>
#include <complex>
#include <cstdint>
#include <array>
#include <algorithm>
using std::complex;


template<typename Iter, typename T>
void FFT_REC(Iter first, Iter last, T data_type, double frequency_step);

//Cooley-tukey default constructor - used mainly with unit test
template <typename T>
Cooley_tukey<T>::Cooley_tukey()
{
  this->frequency_step  = 1;
  this->output_name     = "default-Cooley-tukey";

  this->index = new std::vector<double>;
  this->value = new std::vector<double>;
}

//Cooley_tukey constructor, requires file_name, frequency_step, and output_name
template<typename T>
Cooley_tukey<T>::Cooley_tukey(std::string file_name, double frequency_step, std::string output_name)
{
	this->file_name			 = file_name;
  this->frequency_step = frequency_step;
  this->output_name 	 = output_name;

  this->index = new std::vector<T>;
  this->value = new std::vector<T>;
}


/*Function converts weather data from vector<double> to vector<complex<double>>
	and then starts the recursion process for Cooley_tukey
	@param index - Time data
	@param value - Weather data
	@param &data - reference var to where output will be stored */
template<typename T>
void Cooley_tukey<T>::FFT(std::vector<T>* index, std::vector<T>* value, std::vector<complex<T>>& data)
{
	// Make copy of array and apply window
	for (unsigned int time = 0; time < index->size(); time++)
	{
		data.push_back(std::complex<T>(value->at(time), 0));
	}

	// Start recursion function to split up the tasks
	FFT_REC(std::begin(data), std::end(data), data, this->frequency_step);
}


/*Recursive function to do fourier analysis. Takes the data as an iterator
	breaks the data into smaller pieces, and then calculates the fourier analysis
	through several instances of the function call. Then stitches it back together
	@param first - beginning of the vector
	@param last - end of the vector
	@param data_type - Used to keep the template from the Cooley_tukey Class
	@param frequency - Resolution of the fourier analysis	*/
template<typename Iter, typename T>
void FFT_REC(Iter first, Iter last, T data_type, double frequency_step)
{
	auto current_size = last - first;
	// Check if it is split up enough
	if (current_size >= 2)
	{
		// Split even and odds up
		std::vector<complex<double>> odd;
		odd.resize(current_size / 2);

		for (int i = 0; i < (current_size / 2); ++i)
		{
		    odd.at(i) 	= first[i * 2 + 1];
				first[i] 		= first[i * 2];
		}

		//Takes the odd half and just adds it to the 2nd half of vector
		for (int i = 0; i < current_size / 2; ++i)
		{
				first[i + current_size / 2] = odd.at(i);
		}

		//Split on tasks
		auto split = first + current_size / 2;
		FFT_REC(first, split, data_type, frequency_step);
		FFT_REC(split, last, data_type, frequency_step);

		// DFT portion of FFT - calculates after everything has been split up through FFT_REC
		for (int frequency = 0; frequency < current_size / 2; ++frequency)
		{
			auto t = std::exp(std::complex<double>(0, -2.0 * M_PI * frequency / current_size));

			//Result of Cooley-Tukey algorithm:
			auto& bottom 	= first[frequency];
			auto& top 		= first[frequency + current_size / 2];
			top 					= bottom - t * top;
			bottom 				-= top - bottom;
		}
	}
}

template class Cooley_tukey<double>;
