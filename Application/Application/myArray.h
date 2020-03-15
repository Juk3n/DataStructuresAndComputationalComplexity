#pragma once

#include <iostream>

class myArray
{
	int* pointerToArray;
    int* temporaryPointerToArray;
    int size;
public:
    myArray();

    void showArray();

    void pushBack(int value);
    void popBack();

    void pushFront(int value);
    void popFront();

    void push(int value, int position);
    void pop(int value);

    static void testArray();
};

