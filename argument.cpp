/*
@file: main.cpp
@desc: Functions for parsing and analysing command-line arguments
@date: 3/6/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#include <iostream>
#include <stdexcept>
#include <exception>
#include "argument.h"

const int MIN_ARG = 4; // Minimum amount of arguments for program to run

/*Checks for the amount of command-line parameters entered and throws an
  exception if there aren't enough to run the program correctly
  @param argc - Num of command-line parameters caught by main() */
void checkArg(int argc)
{
  try
  {
    if(argc != 2 && argc < MIN_ARG)
    {
      throw std::runtime_error("ERROR: To few arguments, try 'help' for usage");
    }
  }
  catch(std::runtime_error& exception)
  {
    std::cerr << exception.what() << std::endl;
  }
}
