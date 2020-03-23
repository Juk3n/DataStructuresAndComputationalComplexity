#include "myFile.h"

myFile::myFile(std::string fileName)
{
    file = std::ifstream{ fileName.c_str() };
    
    if (!file)
        std::cout << "Nie udalo sie odczytac pliku" << std::endl;
}

myFile::~myFile()
{
    file.close();
}

int myFile::readNextValue()
{
    int value;
    file >> value;
    return value;
}
