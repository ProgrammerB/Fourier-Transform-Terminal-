/*
@file: main.cpp
@desc: Functions for parsing and analysing command-line arguments
@date: 3/6/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include "argument.h"

const int MIN_ARG = 5; // Minimum amount of arguments for program to run
const std::string HELP = "-help"; // String literal for the '-help' option

/*Checks for the amount of command-line parameters entered and throws an
  exception if there aren't enough to run the program correctly
  @param argc - Num of command-line parameters caught by main() */
bool checkNumParam(int argc)
{
  try
  {
    if(argc != 2 && argc < MIN_ARG)
    {
      throw std::runtime_error("ERROR: To few arguments, try " + HELP + " for usage");
    }
    return true;
  }
  catch(std::runtime_error& exception)
  {
    std::cerr << exception.what() << std::endl;
  }
  return false;
}


/*Goes through the list of inputted parameters and sends it to the appropriate
  locations
  @param argc - number of arguments, used to check if 'help' was entered
  @param argv[] - string array of the inputted parameters*/
void parseParam(int argc, char* argv[])
{
  try
  {
    if(argc == 2 && argv[1] == HELP)
    {
      helpMenu();
    }
  }
  catch(std::runtime_error& exception)
  {
    std::cerr << "ERROR: Issue parsing inputted paramters" << std::endl;
  }
}


void helpMenu(void)
{
  std::string line;
  std::ifstream help_file("helpMenu.txt");

  if (help_file.is_open())
  {
    while (std::getline(help_file,line))
    {
      std::cout << line << std::endl;
    }
    help_file.close();
  }
}
