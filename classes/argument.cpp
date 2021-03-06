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
#include <vector>
#include <typeinfo>
#include <stdlib.h>
#include "argument.h"
#include "cooley-tukey.h"
#include "brute-force.h"
#include "fourier_test.h"
using std::complex;

const int REQUIRED_ARGS     = 5; // Args needed for the program fully run
const int MIN_ARGS          = 2; // Minimum args needed to access the program
const std::string HELP      = "-help"; // String literal for the '-help' option
const std::string LIST      = "-list"; // String literal for the '-list' option
const std::string COOLEY    = "cooley_tukey"; // String literal for the 'cooley_tukey' algorithm option
const std::string BRUTE     = "brute_force"; // String literal for 'brute_force' algorithm option
const std::string UNIT_TEST = "-unit_test"; // If selected, runs built-in unit test
const std::string TEXT_DIRECTORY = "text_files\\"; // Directory for text files
const std::string HELP_PATH = TEXT_DIRECTORY + "helpMenu.txt";
const std::string LIST_PATH = TEXT_DIRECTORY + "listMenu.txt";


/*Checks for the amount of command-line parameters entered and throws an
  exception if there aren't enough to run the program correctly
  @param argc - Num of command-line parameters caught by main() */
bool checkNumParam(int argc)
{
  try
  {
    if(argc == REQUIRED_ARGS)
    {
      return true;
    }
    else if (argc == MIN_ARGS)
    {
      return true;
    }
    else
    {
      throw std::runtime_error("ERROR: To few arguments, try " + HELP);
    }
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
    if(argc == MIN_ARGS)
    {
      runUniqueParam(argv[1]);
    }
    else if (argc == REQUIRED_ARGS)
    {
      runParam(argc, argv);
    }
    else
    {
      throw std::runtime_error("ERROR: Issue parsing inputted paramters");
    }
  }
  catch(std::runtime_error& exception)
  {
    std::cerr << exception.what() << std::endl;
  }
}


/*If REQUIRED_ARGS is met, then parse the cmd line data into objects based
  on said input.
  @param argc - num of user arguments
  @param argv[4] - String of said arguments */
void runParam(int argc, char* argv[])
{
  try
  {
    if (argv[2] == BRUTE)
    {
      Brute_force<double> brute_obj(argv[1], std::atof(argv[3]), argv[4]);

      brute_obj.parseFile(brute_obj.getFileName(), brute_obj.getIndex(), brute_obj.getValue());
      brute_obj.DFT(brute_obj.getIndex(), brute_obj.getValue(), brute_obj.getResult());
      brute_obj.outputFile(brute_obj.getResult(), brute_obj.getOutputName());
    }
    else if (argv[2] == COOLEY)
    {
      Cooley_tukey<double> cooley_obj(std::string(argv[1]), std::atof(argv[3]), std::string(argv[4]));

      cooley_obj.parseFile(cooley_obj.getFileName(), cooley_obj.getIndex(), cooley_obj.getValue());
      cooley_obj.FFT(cooley_obj.getIndex(), cooley_obj.getValue(), cooley_obj.getData());
      cooley_obj.outputFile(cooley_obj.getData(), cooley_obj.getOutputName());
    }
    else
    {
      throw std::runtime_error("ERROR: No compatible algorithm selected");
    }
  }
  catch(std::runtime_error& exception)
  {
    std::cerr << exception.what() << std::endl;
  }
}


/*If only 1 parameter has been entered, check for which one it was and then
  call the appropriate function(s)
  @param parameter  - A command-line parameter inputted as a string*/
void runUniqueParam(std::string parameter)
{
  if(parameter == HELP)
  {
    printFile(HELP_PATH);
  }
  else if(parameter == LIST)
  {
    printFile(LIST_PATH);
  }
  else if(parameter == UNIT_TEST)
  {
    FOURIER_TEST();
  }
}


/*Receives an ifstream object and prints its contents. Used to print menus
  stored in txt file format.
  @param file - text file to print
  @example  - printFile(file) @output: "Hello World\n"  */
void printFile(std::string file_path)
{
  std::string line;
  std::ifstream file(file_path);

  if (file.is_open())
  {
    while (std::getline(file, line))
    {
      std::cout << line << std::endl;
    }
    file.close();
  }
}
