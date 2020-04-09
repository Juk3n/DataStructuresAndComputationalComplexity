#include "myFile.h"

myFile::myFile(std::string fileName)
{
    file = std::ifstream{ fileName.c_str() };
    
    if (!file)
        myOutput::displayOnScreen("Nie udalo sie odczytac pliku");
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
