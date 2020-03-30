#pragma once

#include <iostream>
#include <random> // for std::mt19937
#include <ctime> // for std::time

#include "myFile.h"
#include "myTimer.h"
#include "myOutput.h"

class myArray
{
	int* pointerToArray;
    int* temporaryPointerToArray;
    int size;
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    
public:
    myArray();
    ~myArray();

    void loadFromFile(std::string fileName);
    void generateRandom(int size);

    void clear();

    void showArray();
    bool find(int value); // zwraca prawde jesli element jest w tablicy

    void pushBack(int value);
    void popBack();

    void pushFront(int value);
    void popFront();

    void push(int value, int position);
    void pop(int index);

    static void testArray();
};

