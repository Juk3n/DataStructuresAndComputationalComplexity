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
    void fixHeapDown(int index);
    void fixHeapUp(int index);
    bool isHeap(); // zwraca czy tablica spelnia warunki kopca
    bool isHeap(int index); // zwracza czy tablica spelnia lokalne warunki kopca 
    void swapValues(int* first, int* second);
    int find(int value);

public:
    myHeap();

    void createHeap(int arrayLength);

    void showHeap();

    void add(int value);
    void remove(int value);

    bool isInHeap(int value);

    static void testHeap();
};

