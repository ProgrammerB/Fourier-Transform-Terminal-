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

const int REQUIRED_ARGS     = 6; // Args needed for the program fully run
const int MIN_ARGS          = 2; // Minimum args needed to access the program
const std::string HELP      = "-help"; // String literal for the '-help' option
const std::string LIST      = "-list"; // String literal for the '-list' option
const std::string COOLEY    = "cooley_tukey"; // String literal for the 'cooley_tukey' algorithm option
const std::string BRUTE     = "brute_force"; // String literal for 'brute_force' algorithm option
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
  }
  catch(std::runtime_error& exception)
  {
    std::cerr << "ERROR: Issue parsing inputted paramters" << std::endl;
  }
}


void runParam(int argc, char* argv[])
{
  std::string file(argv[1]);
  std::string output(argv[5]);

  if (argv[2] == BRUTE)
  {
    Brute_force<double> brute_obj(file, std::atof(argv[3]), std::atof(argv[4]), output);
    std::cout << argv[5] << std::endl;
    std::cout << brute_obj.getOutputName() << std::endl;

    brute_obj.parseFile(brute_obj.getFileName(), brute_obj.getIndex(), brute_obj.getValue());

    brute_obj.DFT(brute_obj.getIndex(), brute_obj.getValue(), brute_obj.getResult());

    brute_obj.outputFile(brute_obj.getResult(), brute_obj.getOutputName());
  }
  else if (argv[1] == COOLEY)
  {
    Cooley_tukey<double> cooley_obj(std::string(argv[1]), std::atof(argv[3]), std::atof(argv[4]), std::string(argv[5]));

    cooley_obj.parseFile(cooley_obj.getFileName(), cooley_obj.getIndex(), cooley_obj.getValue());
  }
  else
  {
    std::cout << "Neither" << std::endl;
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
}


/*Receives an ifstream object and prints its contents. Mainly to be used for
  testing purposes.
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


void parseFile(std::string file_path, std::vector<double>& index, std::vector<double>& value)
{
  double time = 0.0;
  double temperature = 0.0;
  std::ifstream file(file_path);

  while(file >> time >> temperature)
  {
    index.push_back(time);
    value.push_back(temperature);
  }

  file.close();
}
