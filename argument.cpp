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

const int MIN_ARG       = 5; // Minimum amount of arguments for program to run
const std::string HELP  = "-help"; // String literal for the '-help' option
const std::string LIST  = "-list"; // String literal for the '-list' option
const std::string TEXT_DIRECTORY = "text_files\\";
const std::string HELP_MENU = TEXT_DIRECTORY + "helpMenu.txt";
const std::string LIST_MENU = TEXT_DIRECTORY + "listMenu.txt";

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
    for(int i = 1; i < argc; i++)
    {
      if(argc == 2)
      {
        if(argv[i] == HELP)
        {
          helpMenu();
        }
        else if(argv[i] == LIST)
        {
          listMenu();
        }
      }
    }
  }
  catch(std::runtime_error& exception)
  {
    std::cerr << "ERROR: Issue parsing inputted paramters" << std::endl;
  }
}


/*Loads the helpMenu.txt file and prints it to the console  */
void helpMenu(void)
{
  std::ifstream help_file(HELP_MENU);

  printFile(help_file);
}


void listMenu(void)
{
  std::ifstream menu_file(LIST_MENU);
  printFile(menu_file);
}


/*Loads the listMenu.txt file and prints it to the console  */
void printFile(std::ifstream& file)
{
  std::string line;

  if (file.is_open())
  {
    while (std::getline(file,line))
    {
      std::cout << line << std::endl;
    }
    file.close();
  }
}
