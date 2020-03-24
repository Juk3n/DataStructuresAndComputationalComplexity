#pragma once

#include <iostream>

#include "myFile.h"
#include "myTimer.h"

class myArray
{
	int* pointerToArray;
    int* temporaryPointerToArray;
    int size;
public:
    myArray();
    ~myArray();

    void showArray();
    int find(int value);

    void pushBack(int value);
    void popBack();

    void pushFront(int value);
    void popFront();

    void push(int value, int position);
    void pop(int value);

    static void testArray();
};

