#pragma once

#include <iostream>

#include "myFile.h"
#include "myTimer.h"
#include "myOutput.h"

class myArray
{
	int* pointerToArray;
    int* temporaryPointerToArray;
    int size;
public:
    myArray();
    ~myArray();

    void loadFromFile(std::string fileName);

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

