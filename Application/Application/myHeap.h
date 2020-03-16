#pragma once

#include <iostream>


class myHeap
{
    int* pointerToHeap;
    int size;
    
    const int maxSize{ 1000 };

    void fixHeapDown(int arr[], int index, int arrayLength);

public:
    myHeap();

    void createHeap(int arr[], int arrayLength);

    void showHeap();

    void add(int value);
    void remove();

    bool isInHeap(int value);

    static void testHeap();
};

