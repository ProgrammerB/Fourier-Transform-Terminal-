/*
@file: main.cpp
@desc: Control file for all classes
@date: 3/6/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#include <iostream>
#include <string>
#include <vector>
#include "argument.h"
#include "fourier_algorithm.h"
#include "cooley-tukey.h"
#include "brute-force.h"

using namespace std;

void programStart(int argc, char* argv[])
{
  if(checkNumParam(argc))
  {
    parseParam(argc, argv);
  }
}

int main(int argc, char* argv[])
{
  programStart(argc, argv);

  return 0;
}
