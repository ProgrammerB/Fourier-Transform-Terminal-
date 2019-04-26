/*
@file: main.cpp
@desc: Header file for argument functions
@date: 3/6/19

Copyright(c) 2019 Braxton Laster & Ben Rader
*/

#ifndef ARGUMENT_H
#define ARGUMENT_H

bool checkNumParam(int argc);
void parseParam(int argc, char* argv[]);

void runParam(int argc, char* argv[]);
void runUniqueParam(std::string parameter);
void printFile(std::string file_path);

#endif
