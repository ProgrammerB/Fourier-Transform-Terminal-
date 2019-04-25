/*
@file: main.cpp
@desc: Class definitions for the cooley-tukey class
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#include "Cooley-tukey.h"
#include "fourier_algorithm.h"

template<typename T>
void Cooley_tukey<T>::FFT(const std::vector<double> &index, const std::vector<double> &value) {

total_time = index.size();
std::vector<complex<double>> temp;

	// Make copy of array and apply window
	for (int time = 0; time < total_time; time++) {
		temp[time] = index[time];
		temp[time] *= 1; // Window
	}

	// Start recursion
	FFT_REC(temp, total_time);
}

template<typename T>
void Cooley_tukey<T>::FFT_REC(std::vector<complex<double>> &x, int total_time) {
	// Check if it is splitted enough
	if (total_time <= 1) {
		return;
	}

	// Split even and odd
	complex<double> odd[total_time/2];
	complex<double> even[total_time/2];
	for (int i = 0; i < total_time / 2; i++) {
		even[i] = x[i*2];
		odd[i] = x[i*2+1];
	}

	// Split on tasks
	FFT_REC(even, total_time/2);
	FFT_REC(odd, total_time/2);


	// Calculate DFT
	for (int frequency = 0; frequency < total_time / 2; frequency += frequency_step) {
		std::complex<double> t = exp(std::complex<double>(0, -2 * M_PI * frequency / total_time)) * odd[frequency];
		x[frequency] = even[frequency] + t;
		x[total_time / 2 + frequency] = even[frequency] - t;
	}
}
