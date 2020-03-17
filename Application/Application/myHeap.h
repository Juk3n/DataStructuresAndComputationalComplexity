#pragma once

#include <iostream>


class myHeap
{
    int* pointerToHeap;
    int size;
    
    const int maxSize{ 1000 };

    int getLeftChildIndex(int parentIndex);
    int getRightChildIndex(int parentIndex);
    int getParentIndex(int childIndex);
    void fixHeapDown(int arr[], int index, int arrayLength);
    void fixHeapUp(int arr[], int index);
    bool isHeap(); // zwraca czy tablica spelnia warunki kopca
    void swapValues(int* first, int* second);

public:
    myHeap();

    void createHeap(int arr[], int arrayLength);

    void showHeap();

    void add(int value);
    void remove();

    bool isInHeap(int value);

    static void testHeap();
};

