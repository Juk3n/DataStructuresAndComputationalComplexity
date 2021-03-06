#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "myOutput.h"

class myFile
{
	std::ifstream file;
public:
	myFile(std::string fileName);
	~myFile();
	int readNextValue();
	static void generateRandomValuesInFile(std::string fileName, int numberOfValues);
};