/*
@file: fourier_test.h
@desc: Header file for the unit testing file
@date: 4/29/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#ifndef TEST
#define TEST

bool compare_complex (complex<double> A, complex<double> B);

std::vector<double>* makeTimeVector(void);
std::vector<double>* makeValueVector(void);

void FOURIER_TEST(void);

#endif
