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
#include "argument.h"

const int REQUIRED_ARGS     = 5; // Args needed for the program fully run
const int MIN_ARGS          = 2; // Minimum args needed to access the program
const std::string HELP      = "-help"; // String literal for the '-help' option
const std::string LIST      = "-list"; // String literal for the '-list' option
const std::string TEXT_DIRECTORY = "text_files\\"; // Directory for text files
const std::string HELP_MENU = TEXT_DIRECTORY + "helpMenu.txt";
const std::string LIST_MENU = TEXT_DIRECTORY + "listMenu.txt";

/*Checks for the amount of command-line parameters entered and throws an
  exception if there aren't enough to run the program correctly
  @param argc - Num of command-line parameters caught by main() */
bool checkNumParam(int argc)
{
  try
  {
    if(argc != MIN_ARGS && argc != REQUIRED_ARGS)
    {
      throw std::runtime_error("ERROR: To few arguments, try " + HELP);
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
    for(int current_arg = 1; current_arg < argc; current_arg++)
    {
      if(argc == MIN_ARGS)
      {
        runUniqueParam(argv[current_arg]);
      }
    }
  }
  catch(std::runtime_error& exception)
  {
    std::cerr << "ERROR: Issue parsing inputted paramters" << std::endl;
  }
}


/*If only 1 parameter has been entered, check for which one it was and then
  call the appropriate function(s)
  @param parameter  - A command-line parameter inputted as a string*/
void runUniqueParam(std::string parameter)
{
  if(parameter == HELP)
  {
    helpMenu();
  }
  else if(parameter == LIST)
  {
    listMenu();
  }
}


/*Loads the helpMenu.txt file and prints it to the console  */
void helpMenu(void)
{
  std::ifstream help_file(HELP_MENU);
  printFile(help_file);
}


/*Loads the listMenu.txt file and prints it to the console  */
void listMenu(void)
{
  std::ifstream menu_file(LIST_MENU);
  printFile(menu_file);
}


/*Receives an ifstream object and prints its contents
  @param file - text file to print
  @example  - printFile(file) @output: "Hello World\n"  */
void printFile(std::ifstream& file)
{
  std::string line;

  if (file.is_open())
  {
    while (std::getline(file, line))
    {
      std::cout << line << std::endl;
    }
    file.close();
  }
}
