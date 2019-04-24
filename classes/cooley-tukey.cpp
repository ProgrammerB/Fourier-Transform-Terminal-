/*
@file: main.cpp
@desc: Class definitions for the cooley-tukey class
@date: 3/7/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#include "Cooley-tukey.h"
#include "fourier_algorithm.h"

void FFT(int *x_in, std::complex<double> *x_out, int N) {

	// Make copy of array and apply window
	for (int i = 0; i < N; i++) {
		x_out[i] = complex<double>(x_in[i], 0);
		x_out[i] *= 1; // Window
	}

	// Start recursion
	FFT_REC(x_out, N);
}

void FFT_REC(complex<double> *x, int N) {
	// Check if it is splitted enough
	if (N <= 1) {
		return;
	}

	// Split even and odd
	complex<double> odd[N/2];
	complex<double> even[N/2];
	for (int i = 0; i < N / 2; i++) {
		even[i] = x[i*2];
		odd[i] = x[i*2+1];
	}

	// Split on tasks
	FFT_REC(even, N/2);
	FFT_REC(odd, N/2);


	// Calculate DFT
	for (int k = 0; k < N / 2; k++) {
		std::complex<double> t = exp(std::complex<double>(0, -2 * M_PI * k / N)) * odd[k];
		x[k] = even[k] + t;
		x[N / 2 + k] = even[k] - t;
	}
}
